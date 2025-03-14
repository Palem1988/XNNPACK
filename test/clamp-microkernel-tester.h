// Copyright (c) Facebook, Inc. and its affiliates.
// All rights reserved.
//
// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <gtest/gtest.h>

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <functional>
#include <random>
#include <vector>

#include <xnnpack.h>
#include <xnnpack/params.h>
#include <xnnpack/requantization.h>


class ClampMicrokernelTester {
 public:
  enum class Variant {
    Native,
    Scalar,
  };

  inline ClampMicrokernelTester& n(size_t n) {
    assert(n != 0);
    this->n_ = n;
    return *this;
  }

  inline size_t n() const {
    return this->n_;
  }

  inline ClampMicrokernelTester& inplace(bool inplace) {
    this->inplace_ = inplace;
    return *this;
  }

  inline bool inplace() const {
    return this->inplace_;
  }

  inline ClampMicrokernelTester& qmin(uint8_t qmin) {
    this->qmin_ = qmin;
    return *this;
  }

  inline uint8_t qmin() const {
    return this->qmin_;
  }

  inline ClampMicrokernelTester& qmax(uint8_t qmax) {
    this->qmax_ = qmax;
    return *this;
  }

  inline uint8_t qmax() const {
    return this->qmax_;
  }

  inline ClampMicrokernelTester& iterations(size_t iterations) {
    this->iterations_ = iterations;
    return *this;
  }

  inline size_t iterations() const {
    return this->iterations_;
  }

  void Test(xnn_u8_clamp_ukernel_function clamp, Variant variant = Variant::Native) const {
    std::random_device random_device;
    auto rng = std::mt19937(random_device());
    auto u8rng = std::bind(std::uniform_int_distribution<uint8_t>(), rng);

    std::vector<uint8_t> x(n() + XNN_EXTRA_BYTES / sizeof(uint8_t));
    std::vector<uint8_t> y(n() + (inplace() ? XNN_EXTRA_BYTES / sizeof(uint8_t) : 0));
    std::vector<uint8_t> y_ref(n());
    for (size_t iteration = 0; iteration < iterations(); iteration++) {
      std::generate(x.begin(), x.end(), std::ref(u8rng));
      if (inplace()) {
        std::generate(y.begin(), y.end(), std::ref(u8rng));
      } else {
        std::fill(y.begin(), y.end(), 0xA5);
      }
      const uint8_t* x_data = inplace() ? y.data() : x.data();

      // Prepare clamping parameters.
      union xnn_u8_output_params output_params = { };
      switch (variant) {
        case Variant::Native:
          output_params = xnn_compute_u8_output_params(qmin(), qmax());
          break;
        case Variant::Scalar:
          output_params = xnn_compute_scalar_u8_output_params(qmin(), qmax());
          break;
      }
          

      // Compute reference results.
      for (size_t i = 0; i < n(); i++) {
        y_ref[i] = std::max(std::min(x_data[i], qmax()), qmin());
      }

      // Call optimized micro-kernel.
      clamp(n() * sizeof(uint8_t), x_data, y.data(), &output_params);

      // Verify results.
      for (size_t i = 0; i < n(); i++) {
        ASSERT_LE(uint32_t(y[i]), uint32_t(qmax()))
          << "at position " << i << ", n = " << n();
        ASSERT_GE(uint32_t(y[i]), uint32_t(qmin()))
          << "at position " << i << ", n = " << n();
        ASSERT_EQ(uint32_t(y_ref[i]), uint32_t(y[i]))
          << "at position " << i << ", n = " << n()
          << ", qmin = " << uint32_t(qmin()) << ", qmax = " << uint32_t(qmax());
      }
    }
  }

  void Test(xnn_f32_clamp_ukernel_function clamp, Variant variant = Variant::Native) const {
    std::random_device random_device;
    auto rng = std::mt19937(random_device());
    auto f32rng = std::bind(std::uniform_real_distribution<float>(0.0f, 255.0f), rng);

    std::vector<float> x(n() + XNN_EXTRA_BYTES / sizeof(float));
    std::vector<float> y(n() + (inplace() ? XNN_EXTRA_BYTES / sizeof(float) : 0));
    std::vector<float> y_ref(n());
    for (size_t iteration = 0; iteration < iterations(); iteration++) {
      std::generate(x.begin(), x.end(), std::ref(f32rng));
      if (inplace()) {
        std::generate(y.begin(), y.end(), std::ref(f32rng));
      } else {
        std::fill(y.begin(), y.end(), std::nanf(""));
      }
      const float* x_data = inplace() ? y.data() : x.data();

      // Prepare output parameters.
      xnn_f32_output_params output_params = { };
      switch (variant) {
        case Variant::Native:
          output_params = xnn_compute_f32_output_params(float(qmin()), float(qmax()));
          break;
        case Variant::Scalar:
          output_params = xnn_compute_scalar_f32_output_params(float(qmin()), float(qmax()));
          break;
      }

      // Compute reference results.
      for (size_t i = 0; i < n(); i++) {
        y_ref[i] = std::max(std::min(x_data[i], float(qmax())), float(qmin()));
      }

      // Call optimized micro-kernel.
      clamp(n() * sizeof(float), x_data, y.data(), &output_params);

      // Verify results.
      for (size_t i = 0; i < n(); i++) {
        ASSERT_LE(y[i], float(qmax()))
          << "at position " << i << ", n = " << n();
        ASSERT_GE(y[i], float(qmin()))
          << "at position " << i << ", n = " << n();
        ASSERT_EQ(y_ref[i], y[i])
          << "at position " << i << ", n = " << n()
          << ", qmin = " << uint32_t(qmin()) << ", qmax = " << uint32_t(qmax());
      }
    }
  }

 private:
  size_t n_{1};
  bool inplace_{false};
  uint8_t qmin_{5};
  uint8_t qmax_{250};
  size_t iterations_{15};
};

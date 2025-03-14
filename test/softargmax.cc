// Copyright (c) Facebook, Inc. and its affiliates.
// All rights reserved.
//
// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <gtest/gtest.h>

#include "softargmax-operator-tester.h"


TEST(SOFTARGMAX_OP, single_class) {
  SoftArgMaxOperatorTester()
    .batch_size(1)
    .channels(1)
    .iterations(100)
    .TestQ8();
}

TEST(SOFTARGMAX_OP, two_classes) {
  SoftArgMaxOperatorTester()
    .batch_size(1)
    .channels(2)
    .iterations(100)
    .TestQ8();
}

TEST(SOFTARGMAX_OP, many_classes) {
  for (size_t channels = 3; channels < 100; channels++) {
    SoftArgMaxOperatorTester()
      .batch_size(1)
      .channels(channels)
      .iterations(1)
      .TestQ8();
  }
}

TEST(SOFTARGMAX_OP, cifar_classes) {
  // CIFAR-10
  SoftArgMaxOperatorTester()
    .batch_size(1)
    .channels(10)
    .iterations(15)
    .TestQ8();
  // CIFAR-100
  SoftArgMaxOperatorTester()
    .batch_size(1)
    .channels(100)
    .iterations(15)
    .TestQ8();
}

TEST(SOFTARGMAX_OP, imagenet_classes) {
  // ImageNet-1K
  SoftArgMaxOperatorTester()
    .batch_size(1)
    .channels(1000)
    .iterations(10)
    .TestQ8();
  // ImageNet-1K+1
  SoftArgMaxOperatorTester()
    .batch_size(1)
    .channels(1001)
    .iterations(10)
    .TestQ8();
  // ImageNet-22K
  SoftArgMaxOperatorTester()
    .batch_size(1)
    .channels(21841)
    .iterations(10)
    .TestQ8();
}

TEST(SOFTARGMAX_OP, many_channels_with_input_scale) {
  for (size_t channels = 1; channels < 100; channels += 5) {
    for (float input_scale = 1.0e-2f; input_scale < 1.0e+2f; input_scale *= 3.14159265f) {
      SoftArgMaxOperatorTester()
        .batch_size(1)
        .channels(channels)
        .input_scale(input_scale)
        .iterations(1)
        .TestQ8();
    }
  }
}

TEST(SOFTARGMAX_OP, many_channels_with_input_zero_point) {
  for (size_t channels = 1; channels < 100; channels += 5) {
    for (int32_t input_zero_point = 0; input_zero_point <= 255; input_zero_point += 51) {
      SoftArgMaxOperatorTester()
        .batch_size(1)
        .channels(channels)
        .input_zero_point(uint8_t(input_zero_point))
        .iterations(1)
        .TestQ8();
    }
  }
}

TEST(SOFTARGMAX_OP, small_batch) {
  for (size_t channels = 1; channels < 100; channels += 5) {
    SoftArgMaxOperatorTester()
      .batch_size(3)
      .channels(channels)
      .iterations(3)
      .TestQ8();
  }
}

TEST(SOFTARGMAX_OP, small_batch_with_input_stride) {
  for (size_t channels = 1; channels < 100; channels += 5) {
    SoftArgMaxOperatorTester()
      .batch_size(3)
      .channels(channels)
      .input_stride(129)
      .iterations(3)
      .TestQ8();
  }
}

TEST(SOFTARGMAX_OP, small_batch_with_output_stride) {
  for (size_t channels = 1; channels < 100; channels += 5) {
    SoftArgMaxOperatorTester()
      .batch_size(3)
      .channels(channels)
      .output_stride(117)
      .iterations(3)
      .TestQ8();
  }
}

TEST(SOFTARGMAX_OP, strided_batch_with_input_and_output_stride) {
  for (size_t channels = 1; channels < 100; channels += 5) {
    SoftArgMaxOperatorTester()
      .batch_size(3)
      .channels(channels)
      .input_stride(129)
      .output_stride(117)
      .iterations(3)
      .TestQ8();
  }
}

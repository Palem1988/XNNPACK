// Copyright (c) Facebook, Inc. and its affiliates.
// All rights reserved.
//
// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#if defined(__cplusplus) && (__cplusplus >= 201103L)
  #include <cstdint>
  #include <cstddef>
  #include <cassert>
  #include <cmath>
#else
  #include <stdint.h>
  #include <stddef.h>
  #include <assert.h>
  #include <math.h>
#endif

#include <fp16.h>

#include <xnnpack/common.h>
#include <xnnpack/params.h>
#include <xnnpack/scalar-utils.h>


static inline union xnn_q8_gemm_params xnn_compute_scalar_q8_gemm_params(
  uint8_t input_zero_point,
  uint8_t kernel_zero_point,
  float scale,
  uint8_t output_zero_point,
  uint8_t output_min,
  uint8_t output_max)
{
  // Compute requantization parameters
  const uint32_t scale_bits = fp32_to_bits(scale);

  // Multiplier is in [0x40000000, 0x7FFFFF80] range.
  const int32_t multiplier = (int32_t)(((scale_bits & UINT32_C(0x007FFFFF)) | UINT32_C(0x00800000)) << 7);
  assert(multiplier >= INT32_C(0x40000000));
  assert(multiplier <= INT32_C(0x7FFFFF80));

  // Shift is in [0, 31] range.
  const int32_t shift = 127 + 31 - 32 - (fp32_to_bits(scale) >> 23);
  assert(shift >= 0);
  assert(shift < 32);

  const uint32_t remainder_mask = (UINT32_C(1) << shift) - UINT32_C(1);
  const uint32_t remainder_threshold = remainder_mask >> 1;

  union xnn_q8_gemm_params params;
  params.scalar.input_zero_point = (int32_t) (uint32_t) input_zero_point;
  params.scalar.kernel_zero_point = (int32_t) (uint32_t) kernel_zero_point;
  params.scalar.multiplier = multiplier;
  params.scalar.remainder_mask = (int32_t) remainder_mask;
  params.scalar.remainder_threshold = (int32_t) remainder_threshold;
  params.scalar.shift = (uint32_t) shift;
  params.scalar.output_min_less_zero_point =
    (int32_t) (uint32_t) output_min - (int32_t) (uint32_t) output_zero_point;
  params.scalar.output_max_less_zero_point =
    (int32_t) (uint32_t) output_max - (int32_t) (uint32_t) output_zero_point;
  params.scalar.output_zero_point = (int32_t) (uint32_t) output_zero_point;
  return params;
}

static inline union xnn_q8_gemm_params xnn_compute_q8_gemm_params(
  uint8_t input_zero_point,
  uint8_t kernel_zero_point,
  float scale,
  uint8_t output_zero_point,
  uint8_t output_min,
  uint8_t output_max)
{
  // Compute requantization parameters.
  const uint32_t scale_bits = fp32_to_bits(scale);

  // Multiplier is in [0x40000000, 0x7FFFFF80] range.
  const int32_t multiplier = (int32_t)(((scale_bits & UINT32_C(0x007FFFFF)) | UINT32_C(0x00800000)) << 7);
  assert(multiplier >= INT32_C(0x40000000));
  assert(multiplier <= INT32_C(0x7FFFFF80));

  // Shift is in [0, 31] range.
  const int32_t shift = 127 + 31 - 32 - (fp32_to_bits(scale) >> 23);
  assert(shift >= 0);
  assert(shift < 32);

  union xnn_q8_gemm_params params;
  #if XNN_ARCH_X86 || XNN_ARCH_X86_64
    const uint32_t remainder_mask = (UINT32_C(1) << shift) - UINT32_C(1);
    const uint32_t remainder_threshold = remainder_mask >> 1;
    for (uint32_t i = 0; i < 8; i++) {
      params.sse2.input_zero_point[i] = (int16_t) (uint16_t) input_zero_point;
      params.sse2.kernel_zero_point[i] = (int16_t) (uint16_t) kernel_zero_point;
    }
    params.sse2.multiplier[0] = multiplier;
    params.sse2.multiplier[1] = multiplier;
    params.sse2.multiplier[2] = multiplier;
    params.sse2.multiplier[3] = multiplier;
    params.sse2.rounding[0] = UINT64_C(0x40000000);
    params.sse2.rounding[1] = UINT64_C(0x40000000);
    params.sse2.remainder_mask[0] = (int32_t) remainder_mask;
    params.sse2.remainder_mask[1] = (int32_t) remainder_mask;
    params.sse2.remainder_mask[2] = (int32_t) remainder_mask;
    params.sse2.remainder_mask[3] = (int32_t) remainder_mask;
    params.sse2.remainder_threshold[0] = (int32_t) remainder_threshold;
    params.sse2.remainder_threshold[1] = (int32_t) remainder_threshold;
    params.sse2.remainder_threshold[2] = (int32_t) remainder_threshold;
    params.sse2.remainder_threshold[3] = (int32_t) remainder_threshold;
    params.sse2.shift[0] = (uint64_t) (uint32_t) shift;
    params.sse2.shift[1] = (uint64_t) (uint32_t) shift;
    for (uint32_t i = 0; i < 8; i++) {
      params.sse2.output_zero_point[i] = (int16_t) (uint16_t) output_zero_point;
    }
    for (uint32_t i = 0; i < 16; i++) {
      params.sse2.output_max[i] = output_max;
      params.sse2.output_min[i] = output_min;
    }
  #elif XNN_ARCH_ARM || XNN_ARCH_ARM64
    params.neon.input_zero_point = (int16_t) (uint16_t) input_zero_point;
    params.neon.kernel_zero_point = (int16_t) (uint16_t) kernel_zero_point;
    params.neon.multiplier = multiplier;
    params.neon.right_shift = -shift;
    params.neon.output_zero_point = (int16_t) (uint16_t) output_zero_point;
    params.neon.output_max = output_max;
    params.neon.output_min = output_min;
  #else
    const uint32_t remainder_mask = (UINT32_C(1) << shift) - UINT32_C(1);
    const uint32_t remainder_threshold = remainder_mask >> 1;
    params.scalar.input_zero_point = (int32_t) (uint32_t) input_zero_point;
    params.scalar.kernel_zero_point = (int32_t) (uint32_t) kernel_zero_point;
    params.scalar.multiplier = multiplier;
    params.scalar.remainder_mask = (int32_t) remainder_mask;
    params.scalar.remainder_threshold = (int32_t) remainder_threshold;
    params.scalar.shift = (uint32_t) shift;
    params.scalar.output_min_less_zero_point =
      (int32_t) (uint32_t) output_min - (int32_t) (uint32_t) output_zero_point;
    params.scalar.output_max_less_zero_point =
      (int32_t) (uint32_t) output_max - (int32_t) (uint32_t) output_zero_point;
    params.scalar.output_zero_point = (int32_t) (uint32_t) output_zero_point;
  #endif
  return params;
}

static inline union xnn_q8_avgpool_params xnn_compute_q8_avgpool_params(
  int32_t bias,
  float scale,
  uint8_t output_zero_point,
  uint8_t output_min,
  uint8_t output_max)
{
  // Compute requantization parameters.
  assert(scale >= 0x1.0p-32f);
  assert(scale < 256.0f);
  const uint32_t scale_bits = fp32_to_bits(scale);

  // Multiplier is in [0x00800000, 0x00FFFFFF] range.
  const int32_t multiplier = ((int32_t) scale_bits & INT32_C(0x007FFFFF)) | INT32_C(0x00800000);
  assert(multiplier >= INT32_C(0x00800000));
  assert(multiplier <= INT32_C(0x00FFFFFF));

  // Shift is in [16, 55] range.
  const int32_t shift = 127 + 23 - (scale_bits >> 23);
  assert(shift >= 16);
  assert(shift < 64);

  union xnn_q8_avgpool_params params;
  #if XNN_ARCH_X86 || XNN_ARCH_X86_64
    const uint32_t right_shift = (uint32_t) shift;
    const uint64_t rounding = UINT64_C(1) << (right_shift - 1);
    params.sse2.bias[0] = bias;
    params.sse2.bias[1] = bias;
    params.sse2.bias[2] = bias;
    params.sse2.bias[3] = bias;
    params.sse2.multiplier[0] = (uint32_t) multiplier;
    params.sse2.multiplier[1] = (uint32_t) multiplier;
    params.sse2.multiplier[2] = (uint32_t) multiplier;
    params.sse2.multiplier[3] = (uint32_t) multiplier;
    params.sse2.rounding[0] = rounding;
    params.sse2.rounding[1] = rounding;
    params.sse2.right_shift[0] = (uint64_t) right_shift;
    params.sse2.right_shift[1] = (uint64_t) right_shift;
    for (uint32_t i = 0; i < 8; i++) {
      params.sse2.output_zero_point[i] = (int16_t) (uint16_t) output_zero_point;
    }
    for (uint32_t i = 0; i < 16; i++) {
      params.sse2.output_max[i] = output_max;
      params.sse2.output_min[i] = output_min;
    }
  #elif XNN_ARCH_ARM || XNN_ARCH_ARM64
    params.neon.bias = bias;
    params.neon.multiplier = multiplier;
    params.neon.left_shift = (int64_t) -shift;
    params.neon.output_zero_point = (int16_t) (uint16_t) output_zero_point;
    params.neon.output_max = output_max;
    params.neon.output_min = output_min;
  #else
    const uint32_t right_shift = (uint32_t) shift;
    const int64_t rounding = INT64_C(1) << (right_shift - 1);
    params.scalar.bias = bias;
    params.scalar.multiplier = multiplier;
    params.scalar.rounding = rounding;
    params.scalar.right_shift = right_shift;
    params.scalar.output_min_less_zero_point =
      (int32_t) (uint32_t) output_min - (int32_t) (uint32_t) output_zero_point;
    params.scalar.output_max_less_zero_point =
      (int32_t) (uint32_t) output_max - (int32_t) (uint32_t) output_zero_point;
    params.scalar.output_zero_point = (int32_t) (uint32_t) output_zero_point;
  #endif
  return params;
}

static inline union xnn_q8_avgpool_params xnn_compute_scalar_q8_avgpool_params(
  int32_t bias,
  float scale,
  uint8_t output_zero_point,
  uint8_t output_min,
  uint8_t output_max)
{
  // Compute requantization parameters.
  assert(scale >= 0x1.0p-32f);
  assert(scale < 256.0f);
  const uint32_t scale_bits = fp32_to_bits(scale);

  // Multiplier is in [0x00800000, 0x00FFFFFF] range.
  const int32_t multiplier = ((int32_t) scale_bits & INT32_C(0x007FFFFF)) | INT32_C(0x00800000);
  assert(multiplier >= INT32_C(0x00800000));
  assert(multiplier <= INT32_C(0x00FFFFFF));

  // Shift is in [16, 55] range.
  const int32_t shift = 127 + 23 - (scale_bits >> 23);
  assert(shift >= 16);
  assert(shift < 64);

  union xnn_q8_avgpool_params params;
  const uint32_t right_shift = (uint32_t) shift;
  const int64_t rounding = INT64_C(1) << (right_shift - 1);
  params.scalar.bias = bias;
  params.scalar.rounding = rounding;
  params.scalar.multiplier = multiplier;
  params.scalar.right_shift = right_shift;
  params.scalar.output_min_less_zero_point =
    (int32_t) (uint32_t) output_min - (int32_t) (uint32_t) output_zero_point;
  params.scalar.output_max_less_zero_point =
    (int32_t) (uint32_t) output_max - (int32_t) (uint32_t) output_zero_point;
  params.scalar.output_zero_point = (int32_t) (uint32_t) output_zero_point;
  return params;
}

static inline void xnn_update_f32_avgpool_params(
  union xnn_f32_avgpool_params* params,
  float multiplier)
{
  #if XNN_ARCH_X86 || XNN_ARCH_X86_64
    for (uint32_t i = 0; i < 4; i++) {
      params->sse2.multiplier[i] = multiplier;
    }
  #else
    params->scalar.multiplier = multiplier;
  #endif
}

static inline union xnn_f32_avgpool_params xnn_compute_f32_avgpool_params(
  float multiplier,
  float output_min,
  float output_max)
{
  union xnn_f32_avgpool_params params;
#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  for (uint32_t i = 0; i < 4; i++) {
    params.sse2.multiplier[i] = multiplier;
    params.sse2.output_min[i] = output_min;
    params.sse2.output_max[i] = output_max;
  }
#else
  params.scalar.multiplier = multiplier;
  params.scalar.output_min = output_min;
  params.scalar.output_max = output_max;
#endif
return params;
}

static inline union xnn_f32_gavgpool_params xnn_compute_f32_gavgpool_params(
  float multiplier,
  float output_min,
  float output_max,
  uint32_t width)
{
  union xnn_f32_gavgpool_params params;
  #if XNN_ARCH_X86 || XNN_ARCH_X86_64
    for (uint32_t i = 0; i < 4; i++) {
      params.sse.multiplier[i] = multiplier;
      params.sse.output_min[i] = output_min;
      params.sse.output_max[i] = output_max;
    }
  switch (width % 4) {
    case 0:
      params.sse.mask[0] = UINT32_C(0xFFFFFFFF);
      params.sse.mask[1] = UINT32_C(0xFFFFFFFF);
      params.sse.mask[2] = UINT32_C(0xFFFFFFFF);
      params.sse.mask[3] = UINT32_C(0xFFFFFFFF);
      break;
    case 1:
      params.sse.mask[0] = UINT32_C(0xFFFFFFFF);
      params.sse.mask[1] = 0;
      params.sse.mask[2] = 0;
      params.sse.mask[3] = 0;
      break;
    case 2:
      params.sse.mask[0] = UINT32_C(0xFFFFFFFF);
      params.sse.mask[1] = UINT32_C(0xFFFFFFFF);
      params.sse.mask[2] = 0;
      params.sse.mask[3] = 0;
      break;
    case 3:
      params.sse.mask[0] = UINT32_C(0xFFFFFFFF);
      params.sse.mask[1] = UINT32_C(0xFFFFFFFF);
      params.sse.mask[2] = UINT32_C(0xFFFFFFFF);
      params.sse.mask[3] = 0;
      break;
  }
#elif XNN_ARCH_ARM || XNN_ARCH_ARM64
    switch (width % 4) {
      case 0:
        params.neon.mask[0] = UINT32_C(0xFFFFFFFF);
        params.neon.mask[1] = UINT32_C(0xFFFFFFFF);
        params.neon.mask[2] = UINT32_C(0xFFFFFFFF);
        params.neon.mask[3] = UINT32_C(0xFFFFFFFF);
        break;
      case 1:
        params.neon.mask[0] = UINT32_C(0xFFFFFFFF);
        params.neon.mask[1] = 0;
        params.neon.mask[2] = 0;
        params.neon.mask[3] = 0;
        break;
      case 2:
        params.neon.mask[0] = UINT32_C(0xFFFFFFFF);
        params.neon.mask[1] = UINT32_C(0xFFFFFFFF);
        params.neon.mask[2] = 0;
        params.neon.mask[3] = 0;
        break;
      case 3:
        params.neon.mask[0] = UINT32_C(0xFFFFFFFF);
        params.neon.mask[1] = UINT32_C(0xFFFFFFFF);
        params.neon.mask[2] = UINT32_C(0xFFFFFFFF);
        params.neon.mask[3] = 0;
        break;
    }
    params.neon.multiplier = multiplier;
    params.neon.output_min = output_min;
    params.neon.output_max = output_max;
  #else
    params.scalar.multiplier = multiplier;
    params.scalar.output_min = output_min;
    params.scalar.output_max = output_max;
  #endif
  return params;
}

static inline void xnn_update_f32_gavgpool_params(
  union xnn_f32_gavgpool_params* params,
  float multiplier,
  uint32_t width)
{
  #if XNN_ARCH_X86 || XNN_ARCH_X86_64
    for (uint32_t i = 0; i < 4; i++) {
      params->sse.multiplier[i] = multiplier;
    }
    switch (width % 4) {
      case 0:
        params->sse.mask[0] = UINT32_C(0xFFFFFFFF);
        params->sse.mask[1] = UINT32_C(0xFFFFFFFF);
        params->sse.mask[2] = UINT32_C(0xFFFFFFFF);
        params->sse.mask[3] = UINT32_C(0xFFFFFFFF);
        break;
      case 1:
        params->sse.mask[0] = UINT32_C(0xFFFFFFFF);
        params->sse.mask[1] = 0;
        params->sse.mask[2] = 0;
        params->sse.mask[3] = 0;
        break;
      case 2:
        params->sse.mask[0] = UINT32_C(0xFFFFFFFF);
        params->sse.mask[1] = UINT32_C(0xFFFFFFFF);
        params->sse.mask[2] = 0;
        params->sse.mask[3] = 0;
        break;
      case 3:
        params->sse.mask[0] = UINT32_C(0xFFFFFFFF);
        params->sse.mask[1] = UINT32_C(0xFFFFFFFF);
        params->sse.mask[2] = UINT32_C(0xFFFFFFFF);
        params->sse.mask[3] = 0;
        break;
    }
  #elif XNN_ARCH_ARM || XNN_ARCH_ARM64
    params->neon.multiplier = multiplier;
    switch (width % 4) {
      case 0:
        params->neon.mask[0] = UINT32_C(0xFFFFFFFF);
        params->neon.mask[1] = UINT32_C(0xFFFFFFFF);
        params->neon.mask[2] = UINT32_C(0xFFFFFFFF);
        params->neon.mask[3] = UINT32_C(0xFFFFFFFF);
        break;
      case 1:
        params->neon.mask[0] = UINT32_C(0xFFFFFFFF);
        params->neon.mask[1] = 0;
        params->neon.mask[2] = 0;
        params->neon.mask[3] = 0;
        break;
      case 2:
        params->neon.mask[0] = UINT32_C(0xFFFFFFFF);
        params->neon.mask[1] = UINT32_C(0xFFFFFFFF);
        params->neon.mask[2] = 0;
        params->neon.mask[3] = 0;
        break;
      case 3:
        params->neon.mask[0] = UINT32_C(0xFFFFFFFF);
        params->neon.mask[1] = UINT32_C(0xFFFFFFFF);
        params->neon.mask[2] = UINT32_C(0xFFFFFFFF);
        params->neon.mask[3] = 0;
        break;
    }
  #endif
}

static inline union xnn_f32_avgpool_params xnn_compute_scalar_f32_avgpool_params(
  float multiplier,
  float output_min,
  float output_max)
{
  union xnn_f32_avgpool_params params;
  params.scalar.multiplier = multiplier;
  params.scalar.output_min = output_min;
  params.scalar.output_max = output_max;
  return params;
}

static inline union xnn_f32_gavgpool_params xnn_compute_scalar_f32_gavgpool_params(
  float multiplier,
  float output_min,
  float output_max,
  uint32_t width)
{
  union xnn_f32_gavgpool_params params;
  params.scalar.multiplier = multiplier;
  params.scalar.output_min = output_min;
  params.scalar.output_max = output_max;
  return params;
}

static inline union xnn_f32_output_params xnn_compute_f32_output_params(
  float output_min,
  float output_max)
{
  union xnn_f32_output_params params;
#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  for (uint32_t i = 0; i < 4; i++) {
    params.sse.min[i] = output_min;
    params.sse.max[i] = output_max;
  }
#else
  params.scalar.min = output_min;
  params.scalar.max = output_max;
#endif
  return params;
}

static inline union xnn_f32_output_params xnn_compute_scalar_f32_output_params(
  float output_min,
  float output_max)
{
  union xnn_f32_output_params params;
  params.scalar.min = output_min;
  params.scalar.max = output_max;
  return params;
}

static inline union xnn_f32_hswish_params xnn_compute_f32_hswish_params(void)
{
  union xnn_f32_hswish_params params;
#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  for (uint32_t i = 0; i < 4; i++) {
    params.sse.sixth[i] = 0x1.555556p-3f;
    params.sse.half[i] = 0.5f;
    params.sse.one[i] = 1.0f;
  }
#else
  params.scalar.sixth = 0x1.555556p-3f;
  params.scalar.half = 0.5f;
  params.scalar.one = 1.0f;
#endif
  return params;
}

static inline union xnn_f32_hswish_params xnn_compute_scalar_f32_hswish_params(void)
{
  union xnn_f32_hswish_params params;
  params.scalar.sixth = 0x1.555556p-3f;
  params.scalar.half = 0.5f;
  params.scalar.one = 1.0f;
  return params;
}

static inline union xnn_f32_spchw_params xnn_compute_f32_spchw_params(
  uint32_t width,
  float output_min,
  float output_max)
{
  union xnn_f32_spchw_params params;
#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  switch (width % 4) {
    case 0:
      params.sse.mask[0] = UINT32_C(0xFFFFFFFF);
      params.sse.mask[1] = UINT32_C(0xFFFFFFFF);
      params.sse.mask[2] = UINT32_C(0xFFFFFFFF);
      params.sse.mask[3] = UINT32_C(0xFFFFFFFF);
      break;
    case 1:
      params.sse.mask[0] = UINT32_C(0xFFFFFFFF);
      params.sse.mask[1] = 0;
      params.sse.mask[2] = 0;
      params.sse.mask[3] = 0;
      break;
    case 2:
      params.sse.mask[0] = UINT32_C(0xFFFFFFFF);
      params.sse.mask[1] = UINT32_C(0xFFFFFFFF);
      params.sse.mask[2] = 0;
      params.sse.mask[3] = 0;
      break;
    case 3:
      params.sse.mask[0] = UINT32_C(0xFFFFFFFF);
      params.sse.mask[1] = UINT32_C(0xFFFFFFFF);
      params.sse.mask[2] = UINT32_C(0xFFFFFFFF);
      params.sse.mask[3] = 0;
      break;
  }
  switch (width % 8) {
    case 0:
      params.sse.mask_even[0] = UINT32_C(0xFFFFFFFF);
      params.sse.mask_even[1] = UINT32_C(0xFFFFFFFF);
      params.sse.mask_even[2] = UINT32_C(0xFFFFFFFF);
      params.sse.mask_even[3] = UINT32_C(0xFFFFFFFF);
      params.sse.mask_odd[0] = UINT32_C(0xFFFFFFFF);
      params.sse.mask_odd[1] = UINT32_C(0xFFFFFFFF);
      params.sse.mask_odd[2] = UINT32_C(0xFFFFFFFF);
      params.sse.mask_odd[3] = UINT32_C(0xFFFFFFFF);
      break;
    case 1:
      params.sse.mask_even[0] = UINT32_C(0xFFFFFFFF);
      params.sse.mask_even[1] = 0;
      params.sse.mask_even[2] = 0;
      params.sse.mask_even[3] = 0;
      params.sse.mask_odd[0] = 0;
      params.sse.mask_odd[1] = 0;
      params.sse.mask_odd[2] = 0;
      params.sse.mask_odd[3] = 0;
      break;
    case 2:
      params.sse.mask_even[0] = UINT32_C(0xFFFFFFFF);
      params.sse.mask_even[1] = 0;
      params.sse.mask_even[2] = 0;
      params.sse.mask_even[3] = 0;
      params.sse.mask_odd[0] = UINT32_C(0xFFFFFFFF);
      params.sse.mask_odd[1] = 0;
      params.sse.mask_odd[2] = 0;
      params.sse.mask_odd[3] = 0;
      break;
    case 3:
      params.sse.mask_even[0] = UINT32_C(0xFFFFFFFF);
      params.sse.mask_even[1] = UINT32_C(0xFFFFFFFF);
      params.sse.mask_even[2] = 0;
      params.sse.mask_even[3] = 0;
      params.sse.mask_odd[0] = UINT32_C(0xFFFFFFFF);
      params.sse.mask_odd[1] = 0;
      params.sse.mask_odd[2] = 0;
      params.sse.mask_odd[3] = 0;
      break;
    case 4:
      params.sse.mask_even[0] = UINT32_C(0xFFFFFFFF);
      params.sse.mask_even[1] = UINT32_C(0xFFFFFFFF);
      params.sse.mask_even[2] = 0;
      params.sse.mask_even[3] = 0;
      params.sse.mask_odd[0] = UINT32_C(0xFFFFFFFF);
      params.sse.mask_odd[1] = UINT32_C(0xFFFFFFFF);
      params.sse.mask_odd[2] = 0;
      params.sse.mask_odd[3] = 0;
      break;
    case 5:
      params.sse.mask_even[0] = UINT32_C(0xFFFFFFFF);
      params.sse.mask_even[1] = UINT32_C(0xFFFFFFFF);
      params.sse.mask_even[2] = UINT32_C(0xFFFFFFFF);
      params.sse.mask_even[3] = 0;
      params.sse.mask_odd[0] = UINT32_C(0xFFFFFFFF);
      params.sse.mask_odd[1] = UINT32_C(0xFFFFFFFF);
      params.sse.mask_odd[2] = 0;
      params.sse.mask_odd[3] = 0;
      break;
    case 6:
      params.sse.mask_even[0] = UINT32_C(0xFFFFFFFF);
      params.sse.mask_even[1] = UINT32_C(0xFFFFFFFF);
      params.sse.mask_even[2] = UINT32_C(0xFFFFFFFF);
      params.sse.mask_even[3] = 0;
      params.sse.mask_odd[0] = UINT32_C(0xFFFFFFFF);
      params.sse.mask_odd[1] = UINT32_C(0xFFFFFFFF);
      params.sse.mask_odd[2] = UINT32_C(0xFFFFFFFF);
      params.sse.mask_odd[3] = 0;
      break;
    case 7:
      params.sse.mask_even[0] = UINT32_C(0xFFFFFFFF);
      params.sse.mask_even[1] = UINT32_C(0xFFFFFFFF);
      params.sse.mask_even[2] = UINT32_C(0xFFFFFFFF);
      params.sse.mask_even[3] = UINT32_C(0xFFFFFFFF);
      params.sse.mask_odd[0] = UINT32_C(0xFFFFFFFF);
      params.sse.mask_odd[1] = UINT32_C(0xFFFFFFFF);
      params.sse.mask_odd[2] = UINT32_C(0xFFFFFFFF);
      params.sse.mask_odd[3] = 0;
      break;
  }
  for (uint32_t i = 0; i < 4; i++) {
    params.sse.max[i] = output_max;
    params.sse.min[i] = output_min;
  }
#elif XNN_ARCH_ARM || XNN_ARCH_ARM64
  switch (width % 4) {
    case 0:
      params.neon.mask[0] = UINT32_C(0xFFFFFFFF);
      params.neon.mask[1] = UINT32_C(0xFFFFFFFF);
      params.neon.mask[2] = UINT32_C(0xFFFFFFFF);
      params.neon.mask[3] = UINT32_C(0xFFFFFFFF);
      break;
    case 1:
      params.neon.mask[0] = UINT32_C(0xFFFFFFFF);
      params.neon.mask[1] = 0;
      params.neon.mask[2] = 0;
      params.neon.mask[3] = 0;
      break;
    case 2:
      params.neon.mask[0] = UINT32_C(0xFFFFFFFF);
      params.neon.mask[1] = UINT32_C(0xFFFFFFFF);
      params.neon.mask[2] = 0;
      params.neon.mask[3] = 0;
      break;
    case 3:
      params.neon.mask[0] = UINT32_C(0xFFFFFFFF);
      params.neon.mask[1] = UINT32_C(0xFFFFFFFF);
      params.neon.mask[2] = UINT32_C(0xFFFFFFFF);
      params.neon.mask[3] = 0;
      break;
  }
  switch (width % 8) {
    case 0:
      params.neon.mask_even[0] = UINT32_C(0xFFFFFFFF);
      params.neon.mask_even[1] = UINT32_C(0xFFFFFFFF);
      params.neon.mask_even[2] = UINT32_C(0xFFFFFFFF);
      params.neon.mask_even[3] = UINT32_C(0xFFFFFFFF);
      params.neon.mask_odd[0] = UINT32_C(0xFFFFFFFF);
      params.neon.mask_odd[1] = UINT32_C(0xFFFFFFFF);
      params.neon.mask_odd[2] = UINT32_C(0xFFFFFFFF);
      params.neon.mask_odd[3] = UINT32_C(0xFFFFFFFF);
      break;
    case 1:
      params.neon.mask_even[0] = UINT32_C(0xFFFFFFFF);
      params.neon.mask_even[1] = 0;
      params.neon.mask_even[2] = 0;
      params.neon.mask_even[3] = 0;
      params.neon.mask_odd[0] = 0;
      params.neon.mask_odd[1] = 0;
      params.neon.mask_odd[2] = 0;
      params.neon.mask_odd[3] = 0;
      break;
    case 2:
      params.neon.mask_even[0] = UINT32_C(0xFFFFFFFF);
      params.neon.mask_even[1] = 0;
      params.neon.mask_even[2] = 0;
      params.neon.mask_even[3] = 0;
      params.neon.mask_odd[0] = UINT32_C(0xFFFFFFFF);
      params.neon.mask_odd[1] = 0;
      params.neon.mask_odd[2] = 0;
      params.neon.mask_odd[3] = 0;
      break;
    case 3:
      params.neon.mask_even[0] = UINT32_C(0xFFFFFFFF);
      params.neon.mask_even[1] = UINT32_C(0xFFFFFFFF);
      params.neon.mask_even[2] = 0;
      params.neon.mask_even[3] = 0;
      params.neon.mask_odd[0] = UINT32_C(0xFFFFFFFF);
      params.neon.mask_odd[1] = 0;
      params.neon.mask_odd[2] = 0;
      params.neon.mask_odd[3] = 0;
      break;
    case 4:
      params.neon.mask_even[0] = UINT32_C(0xFFFFFFFF);
      params.neon.mask_even[1] = UINT32_C(0xFFFFFFFF);
      params.neon.mask_even[2] = 0;
      params.neon.mask_even[3] = 0;
      params.neon.mask_odd[0] = UINT32_C(0xFFFFFFFF);
      params.neon.mask_odd[1] = UINT32_C(0xFFFFFFFF);
      params.neon.mask_odd[2] = 0;
      params.neon.mask_odd[3] = 0;
      break;
    case 5:
      params.neon.mask_even[0] = UINT32_C(0xFFFFFFFF);
      params.neon.mask_even[1] = UINT32_C(0xFFFFFFFF);
      params.neon.mask_even[2] = UINT32_C(0xFFFFFFFF);
      params.neon.mask_even[3] = 0;
      params.neon.mask_odd[0] = UINT32_C(0xFFFFFFFF);
      params.neon.mask_odd[1] = UINT32_C(0xFFFFFFFF);
      params.neon.mask_odd[2] = 0;
      params.neon.mask_odd[3] = 0;
      break;
    case 6:
      params.neon.mask_even[0] = UINT32_C(0xFFFFFFFF);
      params.neon.mask_even[1] = UINT32_C(0xFFFFFFFF);
      params.neon.mask_even[2] = UINT32_C(0xFFFFFFFF);
      params.neon.mask_even[3] = 0;
      params.neon.mask_odd[0] = UINT32_C(0xFFFFFFFF);
      params.neon.mask_odd[1] = UINT32_C(0xFFFFFFFF);
      params.neon.mask_odd[2] = UINT32_C(0xFFFFFFFF);
      params.neon.mask_odd[3] = 0;
      break;
    case 7:
      params.neon.mask_even[0] = UINT32_C(0xFFFFFFFF);
      params.neon.mask_even[1] = UINT32_C(0xFFFFFFFF);
      params.neon.mask_even[2] = UINT32_C(0xFFFFFFFF);
      params.neon.mask_even[3] = UINT32_C(0xFFFFFFFF);
      params.neon.mask_odd[0] = UINT32_C(0xFFFFFFFF);
      params.neon.mask_odd[1] = UINT32_C(0xFFFFFFFF);
      params.neon.mask_odd[2] = UINT32_C(0xFFFFFFFF);
      params.neon.mask_odd[3] = 0;
      break;
  }
  params.neon.max = output_max;
  params.neon.min = output_min;
#else
  params.scalar.max = output_max;
  params.scalar.min = output_min;
#endif
  return params;
}

static inline void xnn_update_f32_spchw_params(
  union xnn_f32_spchw_params* params,
  uint32_t width)
{
  #if XNN_ARCH_X86 || XNN_ARCH_X86_64
    switch (width % 4) {
      case 0:
        params->sse.mask[0] = UINT32_C(0xFFFFFFFF);
        params->sse.mask[1] = UINT32_C(0xFFFFFFFF);
        params->sse.mask[2] = UINT32_C(0xFFFFFFFF);
        params->sse.mask[3] = UINT32_C(0xFFFFFFFF);
        break;
      case 1:
        params->sse.mask[0] = UINT32_C(0xFFFFFFFF);
        params->sse.mask[1] = 0;
        params->sse.mask[2] = 0;
        params->sse.mask[3] = 0;
        break;
      case 2:
        params->sse.mask[0] = UINT32_C(0xFFFFFFFF);
        params->sse.mask[1] = UINT32_C(0xFFFFFFFF);
        params->sse.mask[2] = 0;
        params->sse.mask[3] = 0;
        break;
      case 3:
        params->sse.mask[0] = UINT32_C(0xFFFFFFFF);
        params->sse.mask[1] = UINT32_C(0xFFFFFFFF);
        params->sse.mask[2] = UINT32_C(0xFFFFFFFF);
        params->sse.mask[3] = 0;
        break;
    }
    switch (width % 8) {
      case 0:
        params->sse.mask_even[0] = UINT32_C(0xFFFFFFFF);
        params->sse.mask_even[1] = UINT32_C(0xFFFFFFFF);
        params->sse.mask_even[2] = UINT32_C(0xFFFFFFFF);
        params->sse.mask_even[3] = UINT32_C(0xFFFFFFFF);
        params->sse.mask_odd[0] = UINT32_C(0xFFFFFFFF);
        params->sse.mask_odd[1] = UINT32_C(0xFFFFFFFF);
        params->sse.mask_odd[2] = UINT32_C(0xFFFFFFFF);
        params->sse.mask_odd[3] = UINT32_C(0xFFFFFFFF);
        break;
      case 1:
        params->sse.mask_even[0] = UINT32_C(0xFFFFFFFF);
        params->sse.mask_even[1] = 0;
        params->sse.mask_even[2] = 0;
        params->sse.mask_even[3] = 0;
        params->sse.mask_odd[0] = 0;
        params->sse.mask_odd[1] = 0;
        params->sse.mask_odd[2] = 0;
        params->sse.mask_odd[3] = 0;
        break;
      case 2:
        params->sse.mask_even[0] = UINT32_C(0xFFFFFFFF);
        params->sse.mask_even[1] = 0;
        params->sse.mask_even[2] = 0;
        params->sse.mask_even[3] = 0;
        params->sse.mask_odd[0] = UINT32_C(0xFFFFFFFF);
        params->sse.mask_odd[1] = 0;
        params->sse.mask_odd[2] = 0;
        params->sse.mask_odd[3] = 0;
        break;
      case 3:
        params->sse.mask_even[0] = UINT32_C(0xFFFFFFFF);
        params->sse.mask_even[1] = UINT32_C(0xFFFFFFFF);
        params->sse.mask_even[2] = 0;
        params->sse.mask_even[3] = 0;
        params->sse.mask_odd[0] = UINT32_C(0xFFFFFFFF);
        params->sse.mask_odd[1] = 0;
        params->sse.mask_odd[2] = 0;
        params->sse.mask_odd[3] = 0;
        break;
      case 4:
        params->sse.mask_even[0] = UINT32_C(0xFFFFFFFF);
        params->sse.mask_even[1] = UINT32_C(0xFFFFFFFF);
        params->sse.mask_even[2] = 0;
        params->sse.mask_even[3] = 0;
        params->sse.mask_odd[0] = UINT32_C(0xFFFFFFFF);
        params->sse.mask_odd[1] = UINT32_C(0xFFFFFFFF);
        params->sse.mask_odd[2] = 0;
        params->sse.mask_odd[3] = 0;
        break;
      case 5:
        params->sse.mask_even[0] = UINT32_C(0xFFFFFFFF);
        params->sse.mask_even[1] = UINT32_C(0xFFFFFFFF);
        params->sse.mask_even[2] = UINT32_C(0xFFFFFFFF);
        params->sse.mask_even[3] = 0;
        params->sse.mask_odd[0] = UINT32_C(0xFFFFFFFF);
        params->sse.mask_odd[1] = UINT32_C(0xFFFFFFFF);
        params->sse.mask_odd[2] = 0;
        params->sse.mask_odd[3] = 0;
        break;
      case 6:
        params->sse.mask_even[0] = UINT32_C(0xFFFFFFFF);
        params->sse.mask_even[1] = UINT32_C(0xFFFFFFFF);
        params->sse.mask_even[2] = UINT32_C(0xFFFFFFFF);
        params->sse.mask_even[3] = 0;
        params->sse.mask_odd[0] = UINT32_C(0xFFFFFFFF);
        params->sse.mask_odd[1] = UINT32_C(0xFFFFFFFF);
        params->sse.mask_odd[2] = UINT32_C(0xFFFFFFFF);
        params->sse.mask_odd[3] = 0;
        break;
      case 7:
        params->sse.mask_even[0] = UINT32_C(0xFFFFFFFF);
        params->sse.mask_even[1] = UINT32_C(0xFFFFFFFF);
        params->sse.mask_even[2] = UINT32_C(0xFFFFFFFF);
        params->sse.mask_even[3] = UINT32_C(0xFFFFFFFF);
        params->sse.mask_odd[0] = UINT32_C(0xFFFFFFFF);
        params->sse.mask_odd[1] = UINT32_C(0xFFFFFFFF);
        params->sse.mask_odd[2] = UINT32_C(0xFFFFFFFF);
        params->sse.mask_odd[3] = 0;
        break;
    }
  #elif XNN_ARCH_ARM || XNN_ARCH_ARM64
    switch (width % 4) {
      case 0:
        params->neon.mask[0] = UINT32_C(0xFFFFFFFF);
        params->neon.mask[1] = UINT32_C(0xFFFFFFFF);
        params->neon.mask[2] = UINT32_C(0xFFFFFFFF);
        params->neon.mask[3] = UINT32_C(0xFFFFFFFF);
        break;
      case 1:
        params->neon.mask[0] = UINT32_C(0xFFFFFFFF);
        params->neon.mask[1] = 0;
        params->neon.mask[2] = 0;
        params->neon.mask[3] = 0;
        break;
      case 2:
        params->neon.mask[0] = UINT32_C(0xFFFFFFFF);
        params->neon.mask[1] = UINT32_C(0xFFFFFFFF);
        params->neon.mask[2] = 0;
        params->neon.mask[3] = 0;
        break;
      case 3:
        params->neon.mask[0] = UINT32_C(0xFFFFFFFF);
        params->neon.mask[1] = UINT32_C(0xFFFFFFFF);
        params->neon.mask[2] = UINT32_C(0xFFFFFFFF);
        params->neon.mask[3] = 0;
        break;
    }
    switch (width % 8) {
      case 0:
        params->neon.mask_even[0] = UINT32_C(0xFFFFFFFF);
        params->neon.mask_even[1] = UINT32_C(0xFFFFFFFF);
        params->neon.mask_even[2] = UINT32_C(0xFFFFFFFF);
        params->neon.mask_even[3] = UINT32_C(0xFFFFFFFF);
        params->neon.mask_odd[0] = UINT32_C(0xFFFFFFFF);
        params->neon.mask_odd[1] = UINT32_C(0xFFFFFFFF);
        params->neon.mask_odd[2] = UINT32_C(0xFFFFFFFF);
        params->neon.mask_odd[3] = UINT32_C(0xFFFFFFFF);
        break;
      case 1:
        params->neon.mask_even[0] = UINT32_C(0xFFFFFFFF);
        params->neon.mask_even[1] = 0;
        params->neon.mask_even[2] = 0;
        params->neon.mask_even[3] = 0;
        params->neon.mask_odd[0] = 0;
        params->neon.mask_odd[1] = 0;
        params->neon.mask_odd[2] = 0;
        params->neon.mask_odd[3] = 0;
        break;
      case 2:
        params->neon.mask_even[0] = UINT32_C(0xFFFFFFFF);
        params->neon.mask_even[1] = 0;
        params->neon.mask_even[2] = 0;
        params->neon.mask_even[3] = 0;
        params->neon.mask_odd[0] = UINT32_C(0xFFFFFFFF);
        params->neon.mask_odd[1] = 0;
        params->neon.mask_odd[2] = 0;
        params->neon.mask_odd[3] = 0;
        break;
      case 3:
        params->neon.mask_even[0] = UINT32_C(0xFFFFFFFF);
        params->neon.mask_even[1] = UINT32_C(0xFFFFFFFF);
        params->neon.mask_even[2] = 0;
        params->neon.mask_even[3] = 0;
        params->neon.mask_odd[0] = UINT32_C(0xFFFFFFFF);
        params->neon.mask_odd[1] = 0;
        params->neon.mask_odd[2] = 0;
        params->neon.mask_odd[3] = 0;
        break;
      case 4:
        params->neon.mask_even[0] = UINT32_C(0xFFFFFFFF);
        params->neon.mask_even[1] = UINT32_C(0xFFFFFFFF);
        params->neon.mask_even[2] = 0;
        params->neon.mask_even[3] = 0;
        params->neon.mask_odd[0] = UINT32_C(0xFFFFFFFF);
        params->neon.mask_odd[1] = UINT32_C(0xFFFFFFFF);
        params->neon.mask_odd[2] = 0;
        params->neon.mask_odd[3] = 0;
        break;
      case 5:
        params->neon.mask_even[0] = UINT32_C(0xFFFFFFFF);
        params->neon.mask_even[1] = UINT32_C(0xFFFFFFFF);
        params->neon.mask_even[2] = UINT32_C(0xFFFFFFFF);
        params->neon.mask_even[3] = 0;
        params->neon.mask_odd[0] = UINT32_C(0xFFFFFFFF);
        params->neon.mask_odd[1] = UINT32_C(0xFFFFFFFF);
        params->neon.mask_odd[2] = 0;
        params->neon.mask_odd[3] = 0;
        break;
      case 6:
        params->neon.mask_even[0] = UINT32_C(0xFFFFFFFF);
        params->neon.mask_even[1] = UINT32_C(0xFFFFFFFF);
        params->neon.mask_even[2] = UINT32_C(0xFFFFFFFF);
        params->neon.mask_even[3] = 0;
        params->neon.mask_odd[0] = UINT32_C(0xFFFFFFFF);
        params->neon.mask_odd[1] = UINT32_C(0xFFFFFFFF);
        params->neon.mask_odd[2] = UINT32_C(0xFFFFFFFF);
        params->neon.mask_odd[3] = 0;
        break;
      case 7:
        params->neon.mask_even[0] = UINT32_C(0xFFFFFFFF);
        params->neon.mask_even[1] = UINT32_C(0xFFFFFFFF);
        params->neon.mask_even[2] = UINT32_C(0xFFFFFFFF);
        params->neon.mask_even[3] = UINT32_C(0xFFFFFFFF);
        params->neon.mask_odd[0] = UINT32_C(0xFFFFFFFF);
        params->neon.mask_odd[1] = UINT32_C(0xFFFFFFFF);
        params->neon.mask_odd[2] = UINT32_C(0xFFFFFFFF);
        params->neon.mask_odd[3] = 0;
        break;
    }
  #endif
}

static inline union xnn_f32_spchw_params xnn_compute_scalar_f32_spchw_params(
  uint32_t width,
  float output_min,
  float output_max)
{
  union xnn_f32_spchw_params params;
  params.scalar.max = output_max;
  params.scalar.min = output_min;
  return params;
}

static inline union xnn_u8_output_params xnn_compute_u8_output_params(
  uint8_t output_min,
  uint8_t output_max)
{
  assert(output_min < output_max);

  union xnn_u8_output_params params;
  #if XNN_ARCH_X86 || XNN_ARCH_X86_64
    for (uint32_t i = 0; i < 16; i++) {
      params.sse2.max[i] = output_max;
      params.sse2.min[i] = output_min;
    }
  #elif XNN_ARCH_ARM || XNN_ARCH_ARM64
    params.neon.max = output_max;
    params.neon.min = output_min;
  #else
    params.scalar.min = (int32_t) (uint32_t) output_min;
    params.scalar.max = (int32_t) (uint32_t) output_max;
  #endif
  return params;
}

static inline union xnn_u8_output_params xnn_compute_scalar_u8_output_params(
  uint8_t output_min,
  uint8_t output_max)
{
  assert(output_min < output_max);

  union xnn_u8_output_params params;
  params.scalar.min = (int32_t) (uint32_t) output_min;
  params.scalar.max = (int32_t) (uint32_t) output_max;
  return params;
}

static inline union xnn_q8_add_params xnn_compute_q8_add_params(
  uint8_t a_zero_point,
  uint8_t b_zero_point,
  uint8_t output_zero_point,
  float a_output_scale,
  float b_output_scale,
  uint8_t output_min,
  uint8_t output_max)
{
  assert(a_output_scale >= 0x1.0p-14f);
  assert(b_output_scale >= 0x1.0p-14f);
  assert(a_output_scale < 0x1.0p+8f);
  assert(b_output_scale < 0x1.0p+8f);

  // Compute requantization parameters.
  const float max_output_scale = a_output_scale > b_output_scale ? a_output_scale : b_output_scale;
  assert(max_output_scale >= 0x1.0p-14f);
  assert(max_output_scale < 0x1.0p+8f);
  const uint32_t max_scale_bits = fp32_to_bits(max_output_scale);
  const int32_t max_scale_exponent = (int32_t) (max_scale_bits >> 23) - 127;
  // Shift is in [13, 31] range.
  const uint32_t shift = (uint32_t) (21 - max_scale_exponent);
  assert(shift < 32);
  assert(shift >= 13);

  const float scale_multiplier = fp32_from_bits((uint32_t) (21 - max_scale_exponent + 127) << 23);

  // Multipliers are in [0, 2**22) range, largest multiplier is in [2**21, 2**22) range.
  const uint32_t a_multiplier = (uint32_t) (int32_t) __builtin_lrintf(a_output_scale * scale_multiplier);
  const uint32_t b_multiplier = (uint32_t) (int32_t) __builtin_lrintf(b_output_scale * scale_multiplier);
  assert((a_multiplier > b_multiplier ? a_multiplier : b_multiplier) >= UINT32_C(0x00200000));
  assert(a_multiplier < UINT32_C(0x00400000));
  assert(b_multiplier < UINT32_C(0x00400000));

  union xnn_q8_add_params params;
  #if XNN_ARCH_X86 || XNN_ARCH_X86_64
    const uint32_t remainder_mask = (UINT32_C(1) << shift) - UINT32_C(1);
    const uint32_t remainder_threshold = remainder_mask >> 1;
    const int32_t zero_point_product =
      (int32_t) -(a_multiplier * (uint32_t) a_zero_point + b_multiplier * (uint32_t) b_zero_point);
    for (uint32_t i = 0; i < 4; i++) {
      params.sse2.zero_point_product[i] = zero_point_product;
    }
    for (uint32_t i = 0; i < 8; i++) {
      params.sse2.y_zero_point[i] = (int16_t) (uint16_t) output_zero_point;
    }
    for (uint32_t i = 0; i < 8; i++) {
      params.sse2.a_multiplier_lo[i] = (uint16_t) (uint32_t) a_multiplier;
      params.sse2.a_multiplier_hi[i] = (uint16_t) ((uint32_t) a_multiplier >> 16);
      params.sse2.b_multiplier_lo[i] = (uint16_t) (uint32_t) b_multiplier;
      params.sse2.b_multiplier_hi[i] = (uint16_t) ((uint32_t) b_multiplier >> 16);
    }
    params.sse2.a_multiplier = a_multiplier;
    params.sse2.b_multiplier = b_multiplier;
    for (uint32_t i = 0; i < 4; i++) {
      params.sse2.remainder_mask[i] = remainder_mask;
      params.sse2.remainder_threshold[i] = remainder_threshold;
    }
    params.sse2.shift = shift;
    for (uint32_t i = 0; i < 16; i++) {
      params.sse2.y_max[i] = output_max;
      params.sse2.y_min[i] = output_min;
    }
  #elif XNN_ARCH_ARM || XNN_ARCH_ARM64
    params.neon.a_zero_point = a_zero_point;
    params.neon.b_zero_point = b_zero_point;
    params.neon.y_zero_point = (int16_t) (uint16_t) output_zero_point;
    params.neon.a_multiplier = (int32_t) a_multiplier;
    params.neon.b_multiplier = (int32_t) b_multiplier;
    params.neon.right_shift = (int32_t) -shift;
    params.neon.y_max = output_max;
    params.neon.y_min = output_min;
  #else
    const uint32_t remainder_mask = (UINT32_C(1) << shift) - UINT32_C(1);
    const uint32_t remainder_threshold = remainder_mask >> 1;
    params.scalar.zero_point_product =
      (int32_t) -(a_multiplier * (uint32_t) a_zero_point + b_multiplier * (uint32_t) b_zero_point);
    params.scalar.a_multiplier = a_multiplier;
    params.scalar.b_multiplier = b_multiplier;
    params.scalar.remainder_mask = (int32_t) remainder_mask;
    params.scalar.remainder_threshold = (int32_t) remainder_threshold;
    params.scalar.shift = shift;
    params.scalar.y_zero_point = (int32_t) (uint32_t) output_zero_point;
    params.scalar.y_max = (int32_t) (uint32_t) output_max;
    params.scalar.y_min = (int32_t) (uint32_t) output_min;
  #endif
  return params;
}

static inline union xnn_q8_add_params xnn_compute_scalar_q8_add_params(
  uint8_t a_zero_point,
  uint8_t b_zero_point,
  uint8_t output_zero_point,
  float a_output_scale,
  float b_output_scale,
  uint8_t output_min,
  uint8_t output_max)
{
  assert(a_output_scale >= 0x1.0p-10f);
  assert(b_output_scale >= 0x1.0p-10f);
  assert(a_output_scale < 0x1.0p+8f);
  assert(b_output_scale < 0x1.0p+8f);

  // Compute requantization parameters.
  const float max_output_scale = a_output_scale > b_output_scale ? a_output_scale : b_output_scale;
  assert(max_output_scale >= 0x1.0p-10f);
  assert(max_output_scale < 0x1.0p+8f);
  const uint32_t max_scale_bits = fp32_to_bits(max_output_scale);
  const int32_t max_scale_exponent = (int32_t) (max_scale_bits >> 23) - 127;
  // Shift is in [13, 31] range.
  const uint32_t shift = (uint32_t) (21 - max_scale_exponent);
  assert(shift < 32);
  assert(shift >= 13);

  // Multipliers are in [0, 2**22) range, largest multiplier is in [2**21, 2**22) range.
  const uint32_t a_multiplier = (uint32_t) (int32_t) __builtin_lrintf(fp32_from_bits(fp32_to_bits(a_output_scale) + (shift << 23)));
  const uint32_t b_multiplier = (uint32_t) (int32_t) __builtin_lrintf(fp32_from_bits(fp32_to_bits(b_output_scale) + (shift << 23)));
  assert((a_multiplier > b_multiplier ? a_multiplier : b_multiplier) >= UINT32_C(0x00200000));
  assert(a_multiplier < UINT32_C(0x00400000));
  assert(b_multiplier < UINT32_C(0x00400000));

  union xnn_q8_add_params params;
  const uint32_t remainder_mask = (UINT32_C(1) << shift) - UINT32_C(1);
  const uint32_t remainder_threshold = remainder_mask >> 1;
  params.scalar.zero_point_product =
    (int32_t) -(a_multiplier * (uint32_t) a_zero_point + b_multiplier * (uint32_t) b_zero_point);
  params.scalar.a_multiplier = a_multiplier;
  params.scalar.b_multiplier = b_multiplier;
  params.scalar.remainder_mask = (int32_t) remainder_mask;
  params.scalar.remainder_threshold = (int32_t) remainder_threshold;
  params.scalar.shift = shift;
  params.scalar.y_zero_point = (int32_t) (uint32_t) output_zero_point;
  params.scalar.y_max = (int32_t) (uint32_t) output_max;
  params.scalar.y_min = (int32_t) (uint32_t) output_min;
  return params;
}

static inline union xnn_q31_requantization_params xnn_compute_scalar_requantization_params(
  float scale,
  uint8_t zero_point,
  uint8_t min,
  uint8_t max)
{
  // Compute requantization parameters.
  assert(scale < 1.0f);
  assert(scale >= 0x1.0p-32f);
  const uint32_t scale_bits = fp32_to_bits(scale);

  // Multiplier is in [0x40000000, 0x7FFFFF80] range.
  const int32_t multiplier = (int32_t)(((scale_bits & UINT32_C(0x007FFFFF)) | UINT32_C(0x00800000)) << 7);
  assert(multiplier >= INT32_C(0x40000000));
  assert(multiplier <= INT32_C(0x7FFFFF80));

  // Shift is in [0, 31] range.
  const int32_t shift = 127 + 31 - 32 - (fp32_to_bits(scale) >> 23);
  assert(shift >= 0);
  assert(shift < 32);

  union xnn_q31_requantization_params params;
  const uint32_t remainder_mask = (UINT32_C(1) << shift) - UINT32_C(1);
  const uint32_t remainder_threshold = remainder_mask >> 1;
  params.scalar.multiplier = multiplier;
  params.scalar.remainder_mask = (int32_t) remainder_mask;
  params.scalar.remainder_threshold = (int32_t) remainder_threshold;
  params.scalar.shift = (uint32_t) shift;
  params.scalar.min_less_zero_point = (int32_t) (uint32_t) min - (int32_t) (uint32_t) zero_point;
  params.scalar.max_less_zero_point = (int32_t) (uint32_t) max - (int32_t) (uint32_t) zero_point;
  params.scalar.zero_point = (int32_t) (uint32_t) zero_point;
  return params;
}

static inline union xnn_q31_requantization_params xnn_compute_requantization_params(
  float scale,
  uint8_t zero_point,
  uint8_t min,
  uint8_t max)
{
  // Compute requantization parameters.
  const uint32_t scale_bits = fp32_to_bits(scale);

  // Multiplier is in [0x40000000, 0x7FFFFF80] range.
  const int32_t multiplier = (int32_t)(((scale_bits & UINT32_C(0x007FFFFF)) | UINT32_C(0x00800000)) << 7);
  assert(multiplier >= INT32_C(0x40000000));
  assert(multiplier <= INT32_C(0x7FFFFF80));

  // Shift is in [0, 31] range.
  const int32_t shift = 127 + 31 - 32 - (fp32_to_bits(scale) >> 23);
  assert(shift >= 0);
  assert(shift < 32);

  union xnn_q31_requantization_params params;
  #if XNN_ARCH_X86 || XNN_ARCH_X86_64
    const uint32_t remainder_mask = (UINT32_C(1) << shift) - UINT32_C(1);
    const uint32_t remainder_threshold = remainder_mask >> 1;
    params.sse2.multiplier[0] = multiplier;
    params.sse2.multiplier[1] = multiplier;
    params.sse2.multiplier[2] = multiplier;
    params.sse2.multiplier[3] = multiplier;
    params.sse2.rounding[0] = UINT64_C(0x40000000);
    params.sse2.rounding[1] = UINT64_C(0x40000000);
    params.sse2.remainder_mask[0] = (int32_t) remainder_mask;
    params.sse2.remainder_mask[1] = (int32_t) remainder_mask;
    params.sse2.remainder_mask[2] = (int32_t) remainder_mask;
    params.sse2.remainder_mask[3] = (int32_t) remainder_mask;
    params.sse2.remainder_threshold[0] = (int32_t) remainder_threshold;
    params.sse2.remainder_threshold[1] = (int32_t) remainder_threshold;
    params.sse2.remainder_threshold[2] = (int32_t) remainder_threshold;
    params.sse2.remainder_threshold[3] = (int32_t) remainder_threshold;
    params.sse2.shift[0] = (uint64_t) (uint32_t) shift;
    params.sse2.shift[1] = (uint64_t) (uint32_t) shift;
    for (uint32_t i = 0; i < 8; i++) {
      params.sse2.zero_point[i] = (int16_t) (uint16_t) zero_point;
    }
    for (uint32_t i = 0; i < 16; i++) {
      params.sse2.max[i] = max;
      params.sse2.min[i] = min;
    }
  #elif XNN_ARCH_ARM || XNN_ARCH_ARM64
    params.neon.multiplier = multiplier;
    params.neon.right_shift = -shift;
    params.neon.zero_point = (int16_t) (uint16_t) zero_point;
    params.neon.max = max;
    params.neon.min = min;
  #else
    const uint32_t remainder_mask = (UINT32_C(1) << shift) - UINT32_C(1);
    const uint32_t remainder_threshold = remainder_mask >> 1;
    params.scalar.multiplier = multiplier;
    params.scalar.remainder_mask = (int32_t) remainder_mask;
    params.scalar.remainder_threshold = (int32_t) remainder_threshold;
    params.scalar.shift = (uint32_t) shift;
    params.scalar.min_less_zero_point = (int32_t) (uint32_t) min - (int32_t) (uint32_t) zero_point;
    params.scalar.max_less_zero_point = (int32_t) (uint32_t) max - (int32_t) (uint32_t) zero_point;
    params.scalar.zero_point = (int32_t) (uint32_t) zero_point;
  #endif
  return params;
}

static inline uint8_t xnn_q31_requantize(
  int32_t n,
  union xnn_q31_requantization_params params)
{
  const int64_t product = (int64_t) n * (int64_t) params.scalar.multiplier;
  const int32_t q31product = (int32_t) (uint32_t) ((uint64_t) (product + INT64_C(0x40000000)) >> 31);
  const int32_t remainder = (q31product & params.scalar.remainder_mask) - (int32_t) (n < 0);
  n = asr_s32(q31product, params.scalar.shift) + (int32_t) (remainder > params.scalar.remainder_threshold);
  if (n < params.scalar.min_less_zero_point) {
    n = params.scalar.min_less_zero_point;
  }
  if (n > params.scalar.max_less_zero_point) {
    n = params.scalar.max_less_zero_point;
  }

  return (uint8_t) (n + params.scalar.zero_point);
}

static inline uint8_t xnn_avgpool_quantize(
  int32_t n,
  union xnn_q8_avgpool_params params)
{
  const int64_t product = (int64_t) n * (int64_t) params.scalar.multiplier;
  const int64_t adjusted_product = product - (int64_t) (n < 0);

  n = (int32_t) asr_s64(adjusted_product + params.scalar.rounding, params.scalar.right_shift);
  if (n < params.scalar.output_min_less_zero_point) {
    n = params.scalar.output_min_less_zero_point;
  }
  if (n > params.scalar.output_max_less_zero_point) {
    n = params.scalar.output_max_less_zero_point;
  }

  return (uint8_t) (n + params.scalar.output_zero_point);
}

static inline uint8_t xnn_add_quantize(
  uint8_t a, uint8_t b,
  union xnn_q8_add_params params)
{
  // Multiply by factors and accumulate products.
  int32_t acc = params.scalar.zero_point_product +
    (int32_t) ((uint32_t) a * params.scalar.a_multiplier) +
    (int32_t) ((uint32_t) b * params.scalar.b_multiplier);

  // Shift right and round.
  const int32_t rem = (acc & params.scalar.remainder_mask) - (int32_t) (acc < 0);
  acc = asr_s32(acc, params.scalar.shift) + (int32_t) (rem > params.scalar.remainder_threshold);

  // Clamp and add output zero point.
  int32_t y = acc + params.scalar.y_zero_point;
  if (y >= params.scalar.y_max) {
    y = params.scalar.y_max;
  }
  if (y <= params.scalar.y_min) {
    y = params.scalar.y_min;
  }
  return (uint8_t) y;
}

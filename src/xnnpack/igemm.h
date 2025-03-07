// Copyright (c) Facebook, Inc. and its affiliates.
// All rights reserved.
//
// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <stddef.h>
#include <stdint.h>

#include <xnnpack/params.h>
#include <xnnpack/common.h>

#ifdef __cplusplus
extern "C" {
#endif


#define DECLARE_F32_IGEMM_UKERNEL_FUNCTION(fn_name) \
  XNN_INTERNAL void fn_name(                        \
      size_t mr,                                    \
      size_t nr,                                    \
      size_t kc,                                    \
      size_t ks,                                    \
      const float** a,                              \
      const float* w,                               \
      float* c,                                     \
      size_t cm_stride,                             \
      size_t cn_stride,                             \
      size_t a_offset,                              \
      const float* zero,                            \
      const union xnn_f32_output_params* params);

DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_1x12__aarch64_neonfma_cortex_a53)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_1x4__scalar)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_1x8__aarch64_neonfma_cortex_a57)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_1x8__aarch64_neonfma_cortex_a75)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_1x8__neon_ld64)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_1x8__neonfma_ld64)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_1x8__psimd_loadsplat)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_1x8__psimd_splat)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_1x8__sse_dup)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_1x8__sse_load1)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_1x8s4__psimd)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_1x8s4__sse)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_2x4__scalar)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_4x12__aarch64_neonfma_cortex_a53)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_4x12__neon_ld64)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_4x12__neonfma_ld64)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_4x2__neon_ld64)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_4x2__neonfma_ld64)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_4x2__scalar)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_4x2c4__psimd)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_4x2c4__sse)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_4x4__neon_ld64)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_4x4__neonfma_ld64)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_4x4__scalar)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_4x8__aarch64_neonfma_cortex_a75)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_4x8__neon_ld128)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_4x8__neon_ld64)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_4x8__neonfma_ld128)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_4x8__neonfma_ld64)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_4x8__psimd_loadsplat)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_4x8__psimd_splat)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_4x8__sse_dup)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_4x8__sse_load1)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_4x8s4__psimd)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_4x8s4__sse)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_5x8__aarch64_neonfma_cortex_a75)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_6x8__aarch64_neonfma_cortex_a57)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_6x8__aarch64_neonfma_cortex_a73)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_6x8__aarch64_neonfma_cortex_a75)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_6x8__neon_ld64)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_6x8__neonfma_ld64)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_6x8__psimd_loadsplat)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_6x8__psimd_splat)
DECLARE_F32_IGEMM_UKERNEL_FUNCTION(xnn_f32_igemm_ukernel_6x8s4__psimd)


#define DECLARE_Q8_IGEMM_UKERNEL_FUNCTION(fn_name) \
  XNN_INTERNAL void fn_name(                       \
      size_t mr,                                   \
      size_t nr,                                   \
      size_t kc,                                   \
      size_t ks,                                   \
      const uint8_t** a,                           \
      const void* w,                               \
      uint8_t* c,                                  \
      size_t cm_stride,                            \
      size_t cn_stride,                            \
      size_t a_offset,                             \
      const uint8_t* zero,                         \
      const union xnn_q8_gemm_params* params);

DECLARE_Q8_IGEMM_UKERNEL_FUNCTION(xnn_q8_igemm_ukernel_2x2__scalar)
DECLARE_Q8_IGEMM_UKERNEL_FUNCTION(xnn_q8_igemm_ukernel_4x4c2__sse2)
DECLARE_Q8_IGEMM_UKERNEL_FUNCTION(xnn_q8_igemm_ukernel_4x8__neon)
DECLARE_Q8_IGEMM_UKERNEL_FUNCTION(xnn_q8_igemm_ukernel_8x8__neon)


#ifdef __cplusplus
}  // extern "C"
#endif

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


#define DECLARE_F32_CLAMP_UKERNEL_FUNCTION(fn_name)   \
  XNN_INTERNAL void fn_name(                          \
      size_t n,                                       \
      const float* x,                                 \
      float* y,                                       \
      const union xnn_f32_output_params* params);

DECLARE_F32_CLAMP_UKERNEL_FUNCTION(xnn_f32_clamp_ukernel__psimd)
DECLARE_F32_CLAMP_UKERNEL_FUNCTION(xnn_f32_clamp_ukernel__neon)
DECLARE_F32_CLAMP_UKERNEL_FUNCTION(xnn_f32_clamp_ukernel__sse)
DECLARE_F32_CLAMP_UKERNEL_FUNCTION(xnn_f32_clamp_ukernel__scalar)


#define DECLARE_U8_CLAMP_UKERNEL_FUNCTION(fn_name) \
  XNN_INTERNAL void fn_name(                       \
      size_t n,                                    \
      const uint8_t* x,                            \
      uint8_t* y,                                  \
      const union xnn_u8_output_params* params);

DECLARE_U8_CLAMP_UKERNEL_FUNCTION(xnn_u8_clamp_ukernel__neon)
DECLARE_U8_CLAMP_UKERNEL_FUNCTION(xnn_u8_clamp_ukernel__sse2)
DECLARE_U8_CLAMP_UKERNEL_FUNCTION(xnn_u8_clamp_ukernel__scalar)


#ifdef __cplusplus
}  // extern "C"
#endif

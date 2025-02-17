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


#define DECLARE_F32_VMULCADDC_UKERNEL_FUNCTION(fn_name) \
  XNN_INTERNAL void fn_name(                            \
      size_t m,                                         \
      size_t c,                                         \
      const float* x,                                   \
      size_t x_stride,                                  \
      const float* w,                                   \
      float* y,                                         \
      size_t y_stride,                                  \
      const union xnn_f32_output_params* params);

DECLARE_F32_VMULCADDC_UKERNEL_FUNCTION(xnn_f32_vmulcaddc_ukernel_c1__scalar_x2)
DECLARE_F32_VMULCADDC_UKERNEL_FUNCTION(xnn_f32_vmulcaddc_ukernel_c4__neon_x2)
DECLARE_F32_VMULCADDC_UKERNEL_FUNCTION(xnn_f32_vmulcaddc_ukernel_c4__neonfma_x2)
DECLARE_F32_VMULCADDC_UKERNEL_FUNCTION(xnn_f32_vmulcaddc_ukernel_c4__psimd_x2)
DECLARE_F32_VMULCADDC_UKERNEL_FUNCTION(xnn_f32_vmulcaddc_ukernel_c4__sse_x2)


#ifdef __cplusplus
}  // extern "C"
#endif

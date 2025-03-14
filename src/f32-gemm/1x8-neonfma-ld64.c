// Auto-generated file. Do not edit!
//   Template: src/f32-gemm/neon-ld64.c.in
//   Generator: tools/xngen
//
// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <arm_neon.h>

#include <xnnpack/gemm.h>


void xnn_f32_gemm_ukernel_1x8__neonfma_ld64(
    size_t mr,
    size_t nc,
    size_t kc,
    const float* restrict a,
    size_t a_stride,
    const float* restrict w,
    float* restrict c,
    size_t cm_stride,
    size_t cn_stride,
    const union xnn_f32_output_params params[restrict static 1])
{
  assert(mr != 0);
  assert(mr <= 1);
  assert(nc != 0);
  assert(kc != 0);
  assert(kc % sizeof(float) == 0);
  assert(a != NULL);
  assert(w != NULL);
  assert(c != NULL);

  const float* a0 = a;
  float* c0 = c;

  do {
    float32x4_t vacc0x0123 = vld1q_f32(w); w += 4;
    float32x4_t vacc0x4567 = vld1q_f32(w); w += 4;

    size_t k = kc;
    for (; k >= 2 * sizeof(float); k -= 2 * sizeof(float)) {
      const float32x2_t va0 = vld1_f32(a0); a0 += 2;

      const float32x4_t vb0123c0 = vld1q_f32(w); w += 4;
      const float32x4_t vb4567c0 = vld1q_f32(w); w += 4;

      #if defined(__aarch64__)
        vacc0x0123 = vfmaq_lane_f32(vacc0x0123,   vb0123c0, va0, 0);
        vacc0x4567 = vfmaq_lane_f32(vacc0x4567,   vb4567c0, va0, 0);
      #else
        const float32x4_t va0c0 = vdupq_lane_f32(va0, 0);
        vacc0x0123 = vfmaq_f32(vacc0x0123,   va0c0, vb0123c0);
        vacc0x4567 = vfmaq_f32(vacc0x4567,   va0c0, vb4567c0);
      #endif
      const float32x4_t vb0123c1 = vld1q_f32(w); w += 4;
      const float32x4_t vb4567c1 = vld1q_f32(w); w += 4;

      #if defined(__aarch64__)
        vacc0x0123 = vfmaq_lane_f32(vacc0x0123,   vb0123c1, va0, 1);
        vacc0x4567 = vfmaq_lane_f32(vacc0x4567,   vb4567c1, va0, 1);
      #else
        const float32x4_t va0c1 = vdupq_lane_f32(va0, 1);
        vacc0x0123 = vfmaq_f32(vacc0x0123,   va0c1, vb0123c1);
        vacc0x4567 = vfmaq_f32(vacc0x4567,   va0c1, vb4567c1);
      #endif
    }
    if XNN_UNLIKELY(k != 0) {
      const float32x4_t va0 = vld1q_dup_f32(a0); a0 += 1;

      const float32x4_t vb0123 = vld1q_f32(w); w += 4;
      const float32x4_t vb4567 = vld1q_f32(w); w += 4;

      vacc0x0123 = vfmaq_f32(vacc0x0123, va0,   vb0123);
      vacc0x4567 = vfmaq_f32(vacc0x4567, va0,   vb4567);
    }
    const float32x4_t vmax = vld1q_dup_f32(&params->scalar.max);
    vacc0x0123 = vminq_f32(vacc0x0123, vmax);
    vacc0x4567 = vminq_f32(vacc0x4567, vmax);

    const float32x4_t vmin = vld1q_dup_f32(&params->scalar.min);
    vacc0x0123 = vmaxq_f32(vacc0x0123, vmin);
    vacc0x4567 = vmaxq_f32(vacc0x4567, vmin);

    if XNN_LIKELY(nc >= 8) {
      vst1q_f32(c0, vacc0x0123);
      vst1q_f32(c0 + 4, vacc0x4567);
      c0 = (float*) ((uintptr_t) c0 + cn_stride);

      a0 = (const float*) ((uintptr_t) a0 - kc);

      nc -= 8;

    } else {
      if (nc & 4) {
        vst1q_f32(c0, vacc0x0123); c0 += 4;

        vacc0x0123 = vacc0x4567;
      }
      float32x2_t vacc0x01 = vget_low_f32(vacc0x0123);
      if (nc & 2) {
        vst1_f32(c0, vacc0x01); c0 += 2;

        vacc0x01 = vget_high_f32(vacc0x0123);
      }
      if (nc & 1) {
        vst1_lane_f32(c0, vacc0x01, 0);
      }

      nc = 0;
    }
  } while (nc != 0);
}

// Auto-generated file. Do not edit!
//   Template: src/f32-igemm/psimd-s4.c.in
//   Generator: tools/xngen
//
// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <psimd.h>

#include <xnnpack/igemm.h>


void xnn_f32_igemm_ukernel_1x8s4__psimd(
    size_t mr,
    size_t nc,
    size_t kc,
    size_t ks,
    const float**restrict a,
    const float*restrict w,
    float*restrict c,
    size_t cm_stride,
    size_t cn_stride,
    size_t a_offset,
    const float* zero,
    const union xnn_f32_output_params params[restrict static 1])
{
  assert(mr != 0);
  assert(mr <= 1);
  assert(nc != 0);
  assert(kc != 0);
  assert(kc % sizeof(float) == 0);
  assert(ks != 0);
  assert(ks % (1 * sizeof(void*)) == 0);
  assert(a_offset % sizeof(float) == 0);

  float* c0 = c;

  do {
    psimd_f32 vacc0x0123 = psimd_load_f32(w);
    psimd_f32 vacc0x4567 = psimd_load_f32(w + 4);
    w += 8;

    size_t p = ks;
    do {
      const float* restrict a0 = a[0];
      if XNN_UNPREDICTABLE(a0 != zero) {
        a0 = (const float*) ((uintptr_t) a0 + a_offset);
      }
      a += 1;

      size_t k = kc;
      while (k >= 4 * sizeof(float)) {
        psimd_f32 va0 = psimd_load_f32(a0);
        a0 += 4;


        const psimd_f32 vb0123c0 = psimd_load_f32(w + 0);
        const psimd_f32 vb4567c0 = psimd_load_f32(w + 4);

        vacc0x0123 = psimd_qfma_f32(vacc0x0123, va0, vb0123c0);
        vacc0x4567 = psimd_qfma_f32(vacc0x4567, va0, vb4567c0);

        #ifdef __clang__
        va0 = __builtin_shufflevector(va0, va0, 1, 2, 3, 0);
        #else
        va0 = __builtin_shuffle(va0, va0, (psimd_s32) { 1, 2, 3, 0 });
        #endif

        const psimd_f32 vb0123c1 = psimd_load_f32(w + 8);
        const psimd_f32 vb4567c1 = psimd_load_f32(w + 12);

        vacc0x0123 = psimd_qfma_f32(vacc0x0123, va0, vb0123c1);
        vacc0x4567 = psimd_qfma_f32(vacc0x4567, va0, vb4567c1);

        #ifdef __clang__
        va0 = __builtin_shufflevector(va0, va0, 1, 2, 3, 0);
        #else
        va0 = __builtin_shuffle(va0, va0, (psimd_s32) { 1, 2, 3, 0 });
        #endif

        const psimd_f32 vb0123c2 = psimd_load_f32(w + 16);
        const psimd_f32 vb4567c2 = psimd_load_f32(w + 20);

        vacc0x0123 = psimd_qfma_f32(vacc0x0123, va0, vb0123c2);
        vacc0x4567 = psimd_qfma_f32(vacc0x4567, va0, vb4567c2);

        #ifdef __clang__
        va0 = __builtin_shufflevector(va0, va0, 1, 2, 3, 0);
        #else
        va0 = __builtin_shuffle(va0, va0, (psimd_s32) { 1, 2, 3, 0 });
        #endif

        const psimd_f32 vb0123c3 = psimd_load_f32(w + 24);
        const psimd_f32 vb4567c3 = psimd_load_f32(w + 28);

        vacc0x0123 = psimd_qfma_f32(vacc0x0123, va0, vb0123c3);
        vacc0x4567 = psimd_qfma_f32(vacc0x4567, va0, vb4567c3);


        w += 32;
        k -= 4 * sizeof(float);
      }
      if XNN_UNLIKELY(k != 0) {
        do {
          const psimd_f32 vb0123 = psimd_load_f32(w);
          const psimd_f32 vb4567 = psimd_load_f32(w + 4);
          w += 8;

          const psimd_f32 va0 = psimd_load_splat_f32(a0);
          a0 += 1;

          vacc0x0123 = psimd_qfma_f32(vacc0x0123, va0, vb0123);
          vacc0x4567 = psimd_qfma_f32(vacc0x4567, va0, vb4567);
          k -= sizeof(float);
        } while (k != 0);
      }
      p -= 1 * sizeof(void*);
    } while (p != 0);

    const psimd_f32 vmax = psimd_load_splat_f32(&params->scalar.max);
    vacc0x0123 = psimd_min_f32(vacc0x0123, vmax);
    vacc0x4567 = psimd_min_f32(vacc0x4567, vmax);

    const psimd_f32 vmin = psimd_load_splat_f32(&params->scalar.min);
    vacc0x0123 = psimd_max_f32(vacc0x0123, vmin);
    vacc0x4567 = psimd_max_f32(vacc0x4567, vmin);

    if XNN_LIKELY(nc >= 8) {
      psimd_store_f32(c0, vacc0x0123);
      psimd_store_f32(c0 + 4, vacc0x4567);
      c0 = (float*) ((uintptr_t) c0 + cn_stride);

      a = (const float**restrict) ((uintptr_t) a - ks);
      nc -= 8;
    } else {
      if (nc & 4) {
        psimd_store_f32(c0, vacc0x0123);

        vacc0x0123 = vacc0x4567;

        c0 += 4;
      }
      if (nc & 2) {
        psimd_store2_f32(c0, vacc0x0123);

        vacc0x0123 = psimd_concat_hi_f32(vacc0x0123, vacc0x0123);

        c0 += 2;
      }
      if (nc & 1) {
        psimd_store1_f32(c0, vacc0x0123);
      }

      nc = 0;
    }
  } while (nc != 0);
}

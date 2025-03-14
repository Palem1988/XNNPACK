// Auto-generated file. Do not edit!
//   Template: src/f32-dwconv/up-neon.c.in
//   Generator: tools/xngen
//
// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <arm_neon.h>

#include <xnnpack/dwconv.h>


void xnn_f32_dwconv_ukernel_up4x9__neon(
    size_t channels,
    size_t output_width,
    const float** input,
    const float* weights,
    float* output,
    size_t input_stride,
    size_t output_increment,
    const union xnn_f32_output_params params[restrict static 1])
{
  assert(channels != 0);
  assert(output_width != 0);

  const float32x4_t vmax = vld1q_dup_f32(&params->scalar.max);
  const float32x4_t vmin = vld1q_dup_f32(&params->scalar.min);
  do {
    const float* i0 = input[0];
    const float* i1 = input[1];
    const float* i2 = input[2];
    const float* i3 = input[3];
    const float* i4 = input[4];
    const float* i5 = input[5];
    const float* i6 = input[6];
    const float* i7 = input[7];
    const float* i8 = input[8];
    input = (const float**) ((uintptr_t) input + input_stride);

    size_t c = channels;
    const float* w = weights;
    for (; c >= 4; c -= 4) {
      float32x4_t vacc0123p0 = vld1q_f32(w); w += 4;


      const float32x4_t vi0x0123 = vld1q_f32(i0); i0 += 4;
      const float32x4_t vk0x0123 = vld1q_f32(w); w += 4;
      vacc0123p0 = vmlaq_f32(vacc0123p0, vi0x0123, vk0x0123);

      const float32x4_t vi1x0123 = vld1q_f32(i1); i1 += 4;
      const float32x4_t vk1x0123 = vld1q_f32(w); w += 4;
      vacc0123p0 = vmlaq_f32(vacc0123p0, vi1x0123, vk1x0123);

      const float32x4_t vi2x0123 = vld1q_f32(i2); i2 += 4;
      const float32x4_t vk2x0123 = vld1q_f32(w); w += 4;
      vacc0123p0 = vmlaq_f32(vacc0123p0, vi2x0123, vk2x0123);

      const float32x4_t vi3x0123 = vld1q_f32(i3); i3 += 4;
      const float32x4_t vk3x0123 = vld1q_f32(w); w += 4;
      vacc0123p0 = vmlaq_f32(vacc0123p0, vi3x0123, vk3x0123);

      const float32x4_t vi4x0123 = vld1q_f32(i4); i4 += 4;
      const float32x4_t vk4x0123 = vld1q_f32(w); w += 4;
      vacc0123p0 = vmlaq_f32(vacc0123p0, vi4x0123, vk4x0123);

      const float32x4_t vi5x0123 = vld1q_f32(i5); i5 += 4;
      const float32x4_t vk5x0123 = vld1q_f32(w); w += 4;
      vacc0123p0 = vmlaq_f32(vacc0123p0, vi5x0123, vk5x0123);

      const float32x4_t vi6x0123 = vld1q_f32(i6); i6 += 4;
      const float32x4_t vk6x0123 = vld1q_f32(w); w += 4;
      vacc0123p0 = vmlaq_f32(vacc0123p0, vi6x0123, vk6x0123);

      const float32x4_t vi7x0123 = vld1q_f32(i7); i7 += 4;
      const float32x4_t vk7x0123 = vld1q_f32(w); w += 4;
      vacc0123p0 = vmlaq_f32(vacc0123p0, vi7x0123, vk7x0123);

      const float32x4_t vi8x0123 = vld1q_f32(i8); i8 += 4;
      const float32x4_t vk8x0123 = vld1q_f32(w); w += 4;
      vacc0123p0 = vmlaq_f32(vacc0123p0, vi8x0123, vk8x0123);


      float32x4_t vacc0123 = vmaxq_f32(vacc0123p0, vmin);
      vacc0123 = vminq_f32(vacc0123, vmax);

      vst1q_f32(output, vacc0123); output += 4;
    }
    if XNN_UNLIKELY(c != 0) {
      float32x4_t vacc0123 = vld1q_f32(w); w += 4;


      const float32x4_t vi0x0123 = vld1q_f32(i0); i0 += 4;
      const float32x4_t vk0x0123 = vld1q_f32(w); w += 4;
      vacc0123 = vmlaq_f32(vacc0123, vi0x0123, vk0x0123);

      const float32x4_t vi1x0123 = vld1q_f32(i1); i1 += 4;
      const float32x4_t vk1x0123 = vld1q_f32(w); w += 4;
      vacc0123 = vmlaq_f32(vacc0123, vi1x0123, vk1x0123);

      const float32x4_t vi2x0123 = vld1q_f32(i2); i2 += 4;
      const float32x4_t vk2x0123 = vld1q_f32(w); w += 4;
      vacc0123 = vmlaq_f32(vacc0123, vi2x0123, vk2x0123);

      const float32x4_t vi3x0123 = vld1q_f32(i3); i3 += 4;
      const float32x4_t vk3x0123 = vld1q_f32(w); w += 4;
      vacc0123 = vmlaq_f32(vacc0123, vi3x0123, vk3x0123);

      const float32x4_t vi4x0123 = vld1q_f32(i4); i4 += 4;
      const float32x4_t vk4x0123 = vld1q_f32(w); w += 4;
      vacc0123 = vmlaq_f32(vacc0123, vi4x0123, vk4x0123);

      const float32x4_t vi5x0123 = vld1q_f32(i5); i5 += 4;
      const float32x4_t vk5x0123 = vld1q_f32(w); w += 4;
      vacc0123 = vmlaq_f32(vacc0123, vi5x0123, vk5x0123);

      const float32x4_t vi6x0123 = vld1q_f32(i6); i6 += 4;
      const float32x4_t vk6x0123 = vld1q_f32(w); w += 4;
      vacc0123 = vmlaq_f32(vacc0123, vi6x0123, vk6x0123);

      const float32x4_t vi7x0123 = vld1q_f32(i7); i7 += 4;
      const float32x4_t vk7x0123 = vld1q_f32(w); w += 4;
      vacc0123 = vmlaq_f32(vacc0123, vi7x0123, vk7x0123);

      const float32x4_t vi8x0123 = vld1q_f32(i8); i8 += 4;
      const float32x4_t vk8x0123 = vld1q_f32(w); w += 4;
      vacc0123 = vmlaq_f32(vacc0123, vi8x0123, vk8x0123);

      vacc0123 = vmaxq_f32(vacc0123, vmin);
      vacc0123 = vminq_f32(vacc0123, vmax);

      float32x2_t vacc01 = vget_low_f32(vacc0123);
      if (c & 2) {
        vst1_f32(output, vacc01); output += 2;
        vacc01 = vget_high_f32(vacc0123);
      }
      if (c & 1) {
        vst1_lane_f32(output, vacc01, 0); output += 1;
      }
    }

    output = (float*) ((uintptr_t) output + output_increment);
  } while (--output_width != 0);
}

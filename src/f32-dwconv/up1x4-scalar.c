// Auto-generated file. Do not edit!
//   Template: src/f32-dwconv/up-scalar.c.in
//   Generator: tools/xngen
//
// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <xnnpack/dwconv.h>
#include <xnnpack/math.h>


void xnn_f32_dwconv_ukernel_up1x4__scalar(
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

  const float vmin = params->scalar.min;
  const float vmax = params->scalar.max;
  do {
    const float* i0 = input[0];
    const float* i1 = input[1];
    const float* i2 = input[2];
    const float* i3 = input[3];
    input = (const float**) ((uintptr_t) input + input_stride);

    size_t c = channels;
    const float* w = weights;
    do {
      float vacc0 = w[0];

      const float vi0 = *i0++;
      const float vk0 = w[1];
      vacc0 += vi0 * vk0;

      const float vi1 = *i1++;
      const float vk1 = w[2];
      float vacc1 = vi1 * vk1;

      const float vi2 = *i2++;
      const float vk2 = w[3];
      vacc0 += vi2 * vk2;

      const float vi3 = *i3++;
      const float vk3 = w[4];
      vacc1 += vi3 * vk3;

      w += 5;

      vacc0 += vacc1;

      vacc0 = math_max_f32(vacc0, vmin);
      vacc0 = math_min_f32(vacc0, vmax);

      *output++ = vacc0;
    } while (--c != 0);

    output = (float*) ((uintptr_t) output + output_increment);
  } while (--output_width != 0);
}

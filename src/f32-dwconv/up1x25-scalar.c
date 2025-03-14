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


void xnn_f32_dwconv_ukernel_up1x25__scalar(
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
    const float* i4 = input[4];
    const float* i5 = input[5];
    const float* i6 = input[6];
    const float* i7 = input[7];
    const float* i8 = input[8];
    const float* i9 = input[9];
    const float* i10 = input[10];
    const float* i11 = input[11];
    const float* i12 = input[12];
    const float* i13 = input[13];
    const float* i14 = input[14];
    const float* i15 = input[15];
    const float* i16 = input[16];
    const float* i17 = input[17];
    const float* i18 = input[18];
    const float* i19 = input[19];
    const float* i20 = input[20];
    const float* i21 = input[21];
    const float* i22 = input[22];
    const float* i23 = input[23];
    const float* i24 = input[24];
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

      const float vi4 = *i4++;
      const float vk4 = w[5];
      vacc0 += vi4 * vk4;

      const float vi5 = *i5++;
      const float vk5 = w[6];
      vacc1 += vi5 * vk5;

      const float vi6 = *i6++;
      const float vk6 = w[7];
      vacc0 += vi6 * vk6;

      const float vi7 = *i7++;
      const float vk7 = w[8];
      vacc1 += vi7 * vk7;

      const float vi8 = *i8++;
      const float vk8 = w[9];
      vacc0 += vi8 * vk8;

      const float vi9 = *i9++;
      const float vk9 = w[10];
      vacc1 += vi9 * vk9;

      const float vi10 = *i10++;
      const float vk10 = w[11];
      vacc0 += vi10 * vk10;

      const float vi11 = *i11++;
      const float vk11 = w[12];
      vacc1 += vi11 * vk11;

      const float vi12 = *i12++;
      const float vk12 = w[13];
      vacc0 += vi12 * vk12;

      const float vi13 = *i13++;
      const float vk13 = w[14];
      vacc1 += vi13 * vk13;

      const float vi14 = *i14++;
      const float vk14 = w[15];
      vacc0 += vi14 * vk14;

      const float vi15 = *i15++;
      const float vk15 = w[16];
      vacc1 += vi15 * vk15;

      const float vi16 = *i16++;
      const float vk16 = w[17];
      vacc0 += vi16 * vk16;

      const float vi17 = *i17++;
      const float vk17 = w[18];
      vacc1 += vi17 * vk17;

      const float vi18 = *i18++;
      const float vk18 = w[19];
      vacc0 += vi18 * vk18;

      const float vi19 = *i19++;
      const float vk19 = w[20];
      vacc1 += vi19 * vk19;

      const float vi20 = *i20++;
      const float vk20 = w[21];
      vacc0 += vi20 * vk20;

      const float vi21 = *i21++;
      const float vk21 = w[22];
      vacc1 += vi21 * vk21;

      const float vi22 = *i22++;
      const float vk22 = w[23];
      vacc0 += vi22 * vk22;

      const float vi23 = *i23++;
      const float vk23 = w[24];
      vacc1 += vi23 * vk23;

      const float vi24 = *i24++;
      const float vk24 = w[25];
      vacc0 += vi24 * vk24;

      w += 26;

      vacc0 += vacc1;

      vacc0 = math_max_f32(vacc0, vmin);
      vacc0 = math_min_f32(vacc0, vmax);

      *output++ = vacc0;
    } while (--c != 0);

    output = (float*) ((uintptr_t) output + output_increment);
  } while (--output_width != 0);
}

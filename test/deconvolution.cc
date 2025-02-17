// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <gtest/gtest.h>

#include <xnnpack/params.h>

#include "deconvolution-operator-tester.h"


/**************************** Future GEMM path ****************************/

TEST(DECONVOLUTION_OP_Q8, 1x1) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(27, 29)
    .kernel_size(1, 1)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, 1x1_varying_input_width) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_width = 25; input_width <= 31; input_width++) {
    DeconvolutionOperatorTester()
      .input_size(input_width, 29)
      .kernel_size(1, 1)
      .group_input_channels(23)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, 1x1_varying_input_height) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_height = 27; input_height <= 33; input_height++) {
    DeconvolutionOperatorTester()
      .input_size(27, input_height)
      .kernel_size(1, 1)
      .group_input_channels(23)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, 1x1_varying_input_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_channels = 1; input_channels <= 16; input_channels *= 4) {
    DeconvolutionOperatorTester()
      .input_size(27, 29)
      .kernel_size(1, 1)
      .group_input_channels(input_channels)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, 1x1_varying_output_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t output_channels = 1; output_channels <= xnn_params.q8.gemm.nr * 2; output_channels *= 2) {
    DeconvolutionOperatorTester()
      .input_size(27, 29)
      .kernel_size(1, 1)
      .group_input_channels(23)
      .group_output_channels(output_channels)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, 1x1_with_input_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(27, 29)
    .kernel_size(1, 1)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .input_pixel_stride(28)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, 1x1_with_output_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(27, 29)
    .kernel_size(1, 1)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .output_pixel_stride(xnn_params.q8.gemm.nr * 2 + 13)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, 1x1_with_qmin) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(27, 29)
    .kernel_size(1, 1)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, 1x1_with_qmax) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(27, 29)
    .kernel_size(1, 1)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestQ8();
}

/**************************** Future GEMM path, grouped ****************************/

TEST(DECONVOLUTION_OP_Q8, grouped_1x1) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(27, 29)
    .kernel_size(1, 1)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, grouped_1x1_varying_input_width) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_width = 25; input_width <= 31; input_width++) {
    DeconvolutionOperatorTester()
      .input_size(input_width, 29)
      .kernel_size(1, 1)
      .groups(2)
      .group_input_channels(23)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, grouped_1x1_varying_input_height) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_height = 27; input_height <= 33; input_height++) {
    DeconvolutionOperatorTester()
      .input_size(27, input_height)
      .kernel_size(1, 1)
      .groups(2)
      .group_input_channels(23)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, grouped_1x1_varying_input_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_channels = 1; input_channels <= 16; input_channels *= 4) {
    DeconvolutionOperatorTester()
      .input_size(27, 29)
      .kernel_size(1, 1)
      .groups(2)
      .group_input_channels(input_channels)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, grouped_1x1_varying_output_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t output_channels = 1; output_channels <= xnn_params.q8.gemm.nr * 2; output_channels *= 2) {
    DeconvolutionOperatorTester()
      .input_size(27, 29)
      .kernel_size(1, 1)
      .groups(2)
      .group_input_channels(23)
      .group_output_channels(output_channels)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, grouped_1x1_with_input_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(27, 29)
    .kernel_size(1, 1)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .input_pixel_stride(47)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, grouped_1x1_with_output_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(27, 29)
    .kernel_size(1, 1)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr + 3)
    .output_pixel_stride(xnn_params.q8.gemm.nr * 2 + 13)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, grouped_1x1_with_qmin) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(27, 29)
    .kernel_size(1, 1)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, grouped_1x1_with_qmax) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(27, 29)
    .kernel_size(1, 1)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestQ8();
}

/**************************** Future GEMM path, batched ****************************/

TEST(DECONVOLUTION_OP_Q8, batched_1x1) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(27, 29)
    .kernel_size(1, 1)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, batched_1x1_varying_input_width) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_width = 25; input_width <= 31; input_width++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(input_width, 29)
      .kernel_size(1, 1)
      .group_input_channels(23)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_1x1_varying_input_height) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_height = 27; input_height <= 33; input_height++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(27, input_height)
      .kernel_size(1, 1)
      .group_input_channels(23)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_1x1_varying_input_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_channels = 1; input_channels <= 16; input_channels *= 4) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(27, 29)
      .kernel_size(1, 1)
      .group_input_channels(input_channels)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_1x1_varying_output_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t output_channels = 1; output_channels <= xnn_params.q8.gemm.nr * 2; output_channels *= 2) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(27, 29)
      .kernel_size(1, 1)
      .group_input_channels(23)
      .group_output_channels(output_channels)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_1x1_with_input_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(27, 29)
    .kernel_size(1, 1)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .input_pixel_stride(28)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, batched_1x1_with_output_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(27, 29)
    .kernel_size(1, 1)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .output_pixel_stride(xnn_params.q8.gemm.nr * 2 + 13)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, batched_1x1_with_qmin) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(27, 29)
    .kernel_size(1, 1)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, batched_1x1_with_qmax) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(27, 29)
    .kernel_size(1, 1)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestQ8();
}

/**************************** Future GEMM path, batched, grouped ****************************/

TEST(DECONVOLUTION_OP_Q8, batched_grouped_1x1) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(27, 29)
    .kernel_size(1, 1)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_1x1_varying_input_width) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_width = 25; input_width <= 31; input_width++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(input_width, 29)
      .kernel_size(1, 1)
      .groups(2)
      .group_input_channels(23)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_1x1_varying_input_height) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_height = 27; input_height <= 33; input_height++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(27, input_height)
      .kernel_size(1, 1)
      .groups(2)
      .group_input_channels(23)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_1x1_varying_input_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_channels = 1; input_channels <= 16; input_channels *= 4) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(27, 29)
      .kernel_size(1, 1)
      .groups(2)
      .group_input_channels(input_channels)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_1x1_varying_output_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t output_channels = 1; output_channels <= xnn_params.q8.gemm.nr * 2; output_channels *= 2) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(27, 29)
      .kernel_size(1, 1)
      .groups(2)
      .group_input_channels(23)
      .group_output_channels(output_channels)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_1x1_with_input_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(27, 29)
    .kernel_size(1, 1)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .input_pixel_stride(47)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_1x1_with_output_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(27, 29)
    .kernel_size(1, 1)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr + 3)
    .output_pixel_stride(xnn_params.q8.gemm.nr * 2 + 13)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_1x1_with_qmin) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(27, 29)
    .kernel_size(1, 1)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_1x1_with_qmax) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(27, 29)
    .kernel_size(1, 1)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestQ8();
}

/**************************** CONV path ****************************/

TEST(DECONVOLUTION_OP_Q8, 3x3) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .group_input_channels(15)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, Kx3) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t kernel_height = 1; kernel_height <= 4; kernel_height *= 2) {
    DeconvolutionOperatorTester()
      .input_size(13, 12)
      .padding_width(1)
      .kernel_size(kernel_height, 3)
      .group_input_channels(17)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(3)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, 3xK) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t kernel_width = 1; kernel_width <= 4; kernel_width *= 2) {
    DeconvolutionOperatorTester()
      .input_size(13, 12)
      .padding_height(1)
      .kernel_size(3, kernel_width)
      .group_input_channels(17)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(3)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, 3x3_varying_height_padding) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t padding_top = 0; padding_top <= 2; padding_top++) {
    for (size_t padding_bottom = 0; padding_bottom <= 2; padding_bottom++) {
      DeconvolutionOperatorTester()
        .input_size(13, 12)
        .padding_width(1)
        .padding_top(padding_top)
        .padding_bottom(padding_bottom)
        .kernel_size(3, 3)
        .group_input_channels(15)
        .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
        .iterations(1)
        .TestQ8();
    }
  }
}

TEST(DECONVOLUTION_OP_Q8, 3x3_varying_width_padding) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t padding_left = 0; padding_left <= 2; padding_left++) {
    for (size_t padding_right = 0; padding_right <= 2; padding_right++) {
      DeconvolutionOperatorTester()
        .input_size(13, 12)
        .padding_height(1)
        .padding_left(padding_left)
        .padding_right(padding_right)
        .kernel_size(3, 3)
        .group_input_channels(15)
        .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
        .iterations(1)
        .TestQ8();
    }
  }
}

TEST(DECONVOLUTION_OP_Q8, 3x3_varying_height_adjustment) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t adjustment_height = 1; adjustment_height <= 2; adjustment_height++) {
    DeconvolutionOperatorTester()
      .input_size(13, 12)
      .padding(1)
      .adjustment_height(adjustment_height)
      .kernel_size(3, 3)
      .group_input_channels(15)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, 3x3_varying_width_adjustment) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t adjustment_width = 1; adjustment_width <= 2; adjustment_width++) {
    DeconvolutionOperatorTester()
      .input_size(13, 12)
      .padding(1)
      .adjustment_width(adjustment_width)
      .kernel_size(3, 3)
      .group_input_channels(15)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, 3x3_varying_input_height) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_height = 10; input_height <= 15; input_height++) {
    DeconvolutionOperatorTester()
      .input_size(input_height, 12)
      .padding(1)
      .kernel_size(3, 3)
      .group_input_channels(15)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, 3x3_varying_input_width) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_width = 9; input_width <= 14; input_width++) {
    DeconvolutionOperatorTester()
      .input_size(13, input_width)
      .padding(1)
      .kernel_size(3, 3)
      .group_input_channels(15)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, 3x3_varying_input_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_channels = 1; input_channels <= 16; input_channels *= 4) {
    DeconvolutionOperatorTester()
      .input_size(13, 12)
      .padding(1)
      .kernel_size(3, 3)
      .group_input_channels(input_channels)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, 3x3_varying_output_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t output_channels = 1; output_channels <= xnn_params.q8.gemm.nr * 2; output_channels *= 2) {
    DeconvolutionOperatorTester()
      .input_size(13, 12)
      .padding(1)
      .kernel_size(3, 3)
      .group_input_channels(23)
      .group_output_channels(output_channels)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, 3x3_with_height_dilation) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t dilation_height = 2; dilation_height <= 3; dilation_height++) {
    DeconvolutionOperatorTester()
      .input_size(13, 12)
      .padding(1)
      .kernel_size(3, 3)
      .dilation_height(dilation_height)
      .group_input_channels(23)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(3)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, 3x3_with_width_dilation) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t dilation_width = 2; dilation_width <= 3; dilation_width++) {
    DeconvolutionOperatorTester()
      .input_size(13, 12)
      .padding(1)
      .kernel_size(3, 3)
      .dilation_width(dilation_width)
      .group_input_channels(23)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(3)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, 3x3_with_height_dilation_and_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .dilation_height(3)
    .stride_height(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, 3x3_with_width_dilation_and_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .dilation_width(3)
    .stride_width(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, 3x3_with_input_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .input_pixel_stride(28)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, 3x3_with_output_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .output_pixel_stride(xnn_params.q8.gemm.nr * 2 + 13)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, 3x3_with_qmin) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, 3x3_with_qmax) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestQ8();
}

/**************************** CONV path, grouped ****************************/

TEST(DECONVOLUTION_OP_Q8, grouped_3x3) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .groups(2)
    .group_input_channels(15)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, grouped_Kx3) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t kernel_height = 1; kernel_height <= 4; kernel_height *= 2) {
    DeconvolutionOperatorTester()
      .input_size(13, 12)
      .padding_width(1)
      .kernel_size(kernel_height, 3)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(3)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, grouped_3xK) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t kernel_width = 1; kernel_width <= 4; kernel_width *= 2) {
    DeconvolutionOperatorTester()
      .input_size(13, 12)
      .padding_height(1)
      .kernel_size(3, kernel_width)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(3)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, grouped_3x3_varying_height_padding) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t padding_top = 0; padding_top <= 2; padding_top++) {
    for (size_t padding_bottom = 0; padding_bottom <= 2; padding_bottom++) {
      DeconvolutionOperatorTester()
        .input_size(13, 12)
        .padding_width(1)
        .padding_top(padding_top)
        .padding_bottom(padding_bottom)
        .kernel_size(3, 3)
        .groups(2)
        .group_input_channels(15)
        .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
        .iterations(1)
        .TestQ8();
    }
  }
}

TEST(DECONVOLUTION_OP_Q8, grouped_3x3_varying_width_padding) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t padding_left = 0; padding_left <= 2; padding_left++) {
    for (size_t padding_right = 0; padding_right <= 2; padding_right++) {
      DeconvolutionOperatorTester()
        .input_size(13, 12)
        .padding_height(1)
        .padding_left(padding_left)
        .padding_right(padding_right)
        .kernel_size(3, 3)
        .groups(2)
        .group_input_channels(15)
        .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
        .iterations(1)
        .TestQ8();
    }
  }
}

TEST(DECONVOLUTION_OP_Q8, grouped_3x3_varying_height_adjustment) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t adjustment_height = 1; adjustment_height <= 2; adjustment_height++) {
    DeconvolutionOperatorTester()
      .input_size(13, 12)
      .padding(1)
      .adjustment_height(adjustment_height)
      .kernel_size(3, 3)
      .groups(2)
      .group_input_channels(15)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, grouped_3x3_varying_width_adjustment) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t adjustment_width = 1; adjustment_width <= 2; adjustment_width++) {
    DeconvolutionOperatorTester()
      .input_size(13, 12)
      .padding(1)
      .adjustment_width(adjustment_width)
      .kernel_size(3, 3)
      .groups(2)
      .group_input_channels(15)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, grouped_3x3_varying_input_height) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_height = 10; input_height <= 15; input_height++) {
    DeconvolutionOperatorTester()
      .input_size(input_height, 12)
      .padding(1)
      .kernel_size(3, 3)
      .groups(2)
      .group_input_channels(15)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, grouped_3x3_varying_input_width) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_width = 9; input_width <= 14; input_width++) {
    DeconvolutionOperatorTester()
      .input_size(13, input_width)
      .padding(1)
      .kernel_size(3, 3)
      .groups(2)
      .group_input_channels(15)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, grouped_3x3_varying_input_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_channels = 1; input_channels <= 16; input_channels *= 4) {
    DeconvolutionOperatorTester()
      .input_size(13, 12)
      .padding(1)
      .kernel_size(3, 3)
      .groups(2)
      .group_input_channels(input_channels)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, grouped_3x3_varying_output_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t output_channels = 1; output_channels <= xnn_params.q8.gemm.nr * 2; output_channels *= 2) {
    DeconvolutionOperatorTester()
      .input_size(13, 12)
      .padding(1)
      .kernel_size(3, 3)
      .groups(2)
      .group_input_channels(23)
      .group_output_channels(output_channels)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, grouped_3x3_with_height_dilation) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t dilation_height = 2; dilation_height <= 3; dilation_height++) {
    DeconvolutionOperatorTester()
      .input_size(13, 12)
      .padding(1)
      .kernel_size(3, 3)
      .dilation_height(dilation_height)
      .groups(2)
      .group_input_channels(23)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(3)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, grouped_3x3_with_width_dilation) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t dilation_width = 2; dilation_width <= 3; dilation_width++) {
    DeconvolutionOperatorTester()
      .input_size(13, 12)
      .padding(1)
      .kernel_size(3, 3)
      .dilation_width(dilation_width)
      .groups(2)
      .group_input_channels(23)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(3)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, grouped_3x3_with_height_dilation_and_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .dilation_height(3)
    .stride_height(2)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, grouped_3x3_with_width_dilation_and_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .dilation_width(3)
    .stride_width(2)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, grouped_3x3_with_input_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .input_pixel_stride(47)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, grouped_3x3_with_output_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr + 3)
    .output_pixel_stride(xnn_params.q8.gemm.nr * 2 + 13)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, grouped_3x3_with_qmin) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, grouped_3x3_with_qmax) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestQ8();
}

/**************************** CONV path, batched ****************************/

TEST(DECONVOLUTION_OP_Q8, batched_3x3) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .group_input_channels(15)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, batched_Kx3) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t kernel_height = 1; kernel_height <= 4; kernel_height *= 2) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, 12)
      .padding_width(1)
      .kernel_size(kernel_height, 3)
      .group_input_channels(17)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(3)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_3xK) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t kernel_width = 1; kernel_width <= 4; kernel_width *= 2) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, 12)
      .padding_height(1)
      .kernel_size(3, kernel_width)
      .group_input_channels(17)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(3)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_3x3_varying_height_padding) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t padding_top = 0; padding_top <= 2; padding_top++) {
    for (size_t padding_bottom = 0; padding_bottom <= 2; padding_bottom++) {
      DeconvolutionOperatorTester()
        .batch_size(2)
        .input_size(13, 12)
        .padding_width(1)
        .padding_top(padding_top)
        .padding_bottom(padding_bottom)
        .kernel_size(3, 3)
        .group_input_channels(15)
        .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
        .iterations(1)
        .TestQ8();
    }
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_3x3_varying_width_padding) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t padding_left = 0; padding_left <= 2; padding_left++) {
    for (size_t padding_right = 0; padding_right <= 2; padding_right++) {
      DeconvolutionOperatorTester()
        .batch_size(2)
        .input_size(13, 12)
        .padding_height(1)
        .padding_left(padding_left)
        .padding_right(padding_right)
        .kernel_size(3, 3)
        .group_input_channels(15)
        .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
        .iterations(1)
        .TestQ8();
    }
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_3x3_varying_height_adjustment) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t adjustment_height = 1; adjustment_height <= 2; adjustment_height++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, 12)
      .padding(1)
      .adjustment_height(adjustment_height)
      .kernel_size(3, 3)
      .group_input_channels(15)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_3x3_varying_width_adjustment) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t adjustment_width = 1; adjustment_width <= 2; adjustment_width++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, 12)
      .padding(1)
      .adjustment_width(adjustment_width)
      .kernel_size(3, 3)
      .group_input_channels(15)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_3x3_varying_input_height) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_height = 10; input_height <= 15; input_height++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(input_height, 12)
      .padding(1)
      .kernel_size(3, 3)
      .group_input_channels(15)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_3x3_varying_input_width) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_width = 9; input_width <= 14; input_width++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, input_width)
      .padding(1)
      .kernel_size(3, 3)
      .group_input_channels(15)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_3x3_varying_input_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_channels = 1; input_channels <= 16; input_channels *= 4) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, 12)
      .padding(1)
      .kernel_size(3, 3)
      .group_input_channels(input_channels)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_3x3_varying_output_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t output_channels = 1; output_channels <= xnn_params.q8.gemm.nr * 2; output_channels *= 2) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, 12)
      .padding(1)
      .kernel_size(3, 3)
      .group_input_channels(23)
      .group_output_channels(output_channels)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_3x3_with_height_dilation) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t dilation_height = 2; dilation_height <= 3; dilation_height++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, 12)
      .padding(1)
      .kernel_size(3, 3)
      .dilation_height(dilation_height)
      .group_input_channels(23)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(3)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_3x3_with_width_dilation) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t dilation_width = 2; dilation_width <= 3; dilation_width++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, 12)
      .padding(1)
      .kernel_size(3, 3)
      .dilation_width(dilation_width)
      .group_input_channels(23)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(3)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_3x3_with_height_dilation_and_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .dilation_height(3)
    .stride_height(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, batched_3x3_with_width_dilation_and_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .dilation_width(3)
    .stride_width(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, batched_3x3_with_input_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .input_pixel_stride(28)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, batched_3x3_with_output_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .output_pixel_stride(xnn_params.q8.gemm.nr * 2 + 13)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, batched_3x3_with_qmin) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, batched_3x3_with_qmax) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestQ8();
}

/**************************** CONV path, grouped, batched ****************************/

TEST(DECONVOLUTION_OP_Q8, batched_grouped_3x3) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .groups(2)
    .group_input_channels(15)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_Kx3) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t kernel_height = 1; kernel_height <= 4; kernel_height *= 2) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, 12)
      .padding_width(1)
      .kernel_size(kernel_height, 3)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(3)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_3xK) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t kernel_width = 1; kernel_width <= 4; kernel_width *= 2) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, 12)
      .padding_height(1)
      .kernel_size(3, kernel_width)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(3)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_3x3_varying_height_padding) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t padding_top = 0; padding_top <= 2; padding_top++) {
    for (size_t padding_bottom = 0; padding_bottom <= 2; padding_bottom++) {
      DeconvolutionOperatorTester()
        .batch_size(2)
        .input_size(13, 12)
        .padding_width(1)
        .padding_top(padding_top)
        .padding_bottom(padding_bottom)
        .kernel_size(3, 3)
        .groups(2)
        .group_input_channels(15)
        .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
        .iterations(1)
        .TestQ8();
    }
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_3x3_varying_width_padding) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t padding_left = 0; padding_left <= 2; padding_left++) {
    for (size_t padding_right = 0; padding_right <= 2; padding_right++) {
      DeconvolutionOperatorTester()
        .batch_size(2)
        .input_size(13, 12)
        .padding_height(1)
        .padding_left(padding_left)
        .padding_right(padding_right)
        .kernel_size(3, 3)
        .groups(2)
        .group_input_channels(15)
        .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
        .iterations(1)
        .TestQ8();
    }
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_3x3_varying_height_adjustment) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t adjustment_height = 1; adjustment_height <= 2; adjustment_height++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, 12)
      .padding(1)
      .adjustment_height(adjustment_height)
      .kernel_size(3, 3)
      .groups(2)
      .group_input_channels(15)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_3x3_varying_width_adjustment) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t adjustment_width = 1; adjustment_width <= 2; adjustment_width++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, 12)
      .padding(1)
      .adjustment_width(adjustment_width)
      .kernel_size(3, 3)
      .groups(2)
      .group_input_channels(15)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_3x3_varying_input_height) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_height = 10; input_height <= 15; input_height++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(input_height, 12)
      .padding(1)
      .kernel_size(3, 3)
      .groups(2)
      .group_input_channels(15)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_3x3_varying_input_width) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_width = 9; input_width <= 14; input_width++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, input_width)
      .padding(1)
      .kernel_size(3, 3)
      .groups(2)
      .group_input_channels(15)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_3x3_varying_input_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_channels = 1; input_channels <= 16; input_channels *= 4) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, 12)
      .padding(1)
      .kernel_size(3, 3)
      .groups(2)
      .group_input_channels(input_channels)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_3x3_varying_output_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t output_channels = 1; output_channels <= xnn_params.q8.gemm.nr * 2; output_channels *= 2) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, 12)
      .padding(1)
      .kernel_size(3, 3)
      .groups(2)
      .group_input_channels(23)
      .group_output_channels(output_channels)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_3x3_with_height_dilation) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t dilation_height = 2; dilation_height <= 3; dilation_height++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, 12)
      .padding(1)
      .kernel_size(3, 3)
      .dilation_height(dilation_height)
      .groups(2)
      .group_input_channels(23)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(3)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_3x3_with_width_dilation) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t dilation_width = 2; dilation_width <= 3; dilation_width++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, 12)
      .padding(1)
      .kernel_size(3, 3)
      .dilation_width(dilation_width)
      .groups(2)
      .group_input_channels(23)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(3)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_3x3_with_height_dilation_and_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .dilation_height(3)
    .stride_width(2)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_3x3_with_width_dilation_and_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .dilation_width(3)
    .stride_width(2)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_3x3_with_input_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .input_pixel_stride(47)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_3x3_with_output_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr + 3)
    .output_pixel_stride(xnn_params.q8.gemm.nr * 2 + 13)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_3x3_with_qmin) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_3x3_with_qmax) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestQ8();
}

/**************************** CONV path, setup ****************************/

TEST(DECONVOLUTION_OP_Q8, 3x3_setup_changing_batch) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .next_batch_size(5)
    .input_height(12)
    .input_width(13)
    .kernel_height(3)
    .kernel_width(5)
    .groups(2)
    .group_input_channels(15)
    .group_output_channels(17)
    .TestSetupQ8();
}

TEST(DECONVOLUTION_OP_Q8, 3x3_setup_changing_height) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_height(12)
    .input_width(13)
    .next_input_height(14)
    .kernel_height(3)
    .kernel_width(5)
    .groups(2)
    .group_input_channels(15)
    .group_output_channels(17)
    .TestSetupQ8();
}

TEST(DECONVOLUTION_OP_Q8, 3x3_setup_changing_width) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_height(12)
    .input_width(13)
    .next_input_width(14)
    .kernel_height(3)
    .kernel_width(5)
    .groups(2)
    .group_input_channels(15)
    .group_output_channels(17)
    .TestSetupQ8();
}

/**************************** SUBCONV2D path ****************************/

TEST(DECONVOLUTION_OP_Q8, 3x3s2) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .group_input_channels(15)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, Kx3s2) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t kernel_height = 2; kernel_height <= 5; kernel_height++) {
    DeconvolutionOperatorTester()
      .input_size(10, 9)
      .padding_width(1)
      .kernel_size(kernel_height, 3)
      .stride(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(3)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, 3xKs2) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t kernel_width = 2; kernel_width <= 5; kernel_width++) {
    DeconvolutionOperatorTester()
      .input_size(10, 9)
      .padding_height(1)
      .kernel_size(3, kernel_width)
      .stride(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(3)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, 3x3sSx1) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t stride_height = 2; stride_height <= 3; stride_height++) {
    DeconvolutionOperatorTester()
      .input_size(10, 9)
      .padding(1)
      .padding_width(1)
      .kernel_size(3, 3)
      .stride_height(stride_height)
      .group_input_channels(17)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(3)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, 3x3s1xS) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t stride_width = 2; stride_width <= 3; stride_width++) {
    DeconvolutionOperatorTester()
      .input_size(10, 9)
      .padding(1)
      .padding_width(1)
      .kernel_size(3, 3)
      .stride_width(stride_width)
      .group_input_channels(17)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(3)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, 3x3s2_varying_height_padding) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t padding_top = 0; padding_top <= 2; padding_top++) {
    for (size_t padding_bottom = 0; padding_bottom <= 2; padding_bottom++) {
      DeconvolutionOperatorTester()
        .input_size(10, 9)
        .padding_width(1)
        .padding_top(padding_top)
        .padding_bottom(padding_bottom)
        .kernel_size(3, 3)
        .stride(2)
        .group_input_channels(15)
        .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
        .iterations(1)
        .TestQ8();
    }
  }
}

TEST(DECONVOLUTION_OP_Q8, 3x3s2_varying_width_padding) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t padding_left = 0; padding_left <= 2; padding_left++) {
    for (size_t padding_right = 0; padding_right <= 2; padding_right++) {
      DeconvolutionOperatorTester()
        .input_size(10, 9)
        .padding_height(1)
        .padding_left(padding_left)
        .padding_right(padding_right)
        .kernel_size(3, 3)
        .stride(2)
        .group_input_channels(15)
        .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
        .iterations(1)
        .TestQ8();
    }
  }
}

TEST(DECONVOLUTION_OP_Q8, 3x3s2_varying_height_adjustment) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t adjustment_height = 1; adjustment_height <= 2; adjustment_height++) {
    DeconvolutionOperatorTester()
      .input_size(10, 9)
      .padding(1)
      .adjustment_height(adjustment_height)
      .kernel_size(3, 3)
      .stride(2)
      .group_input_channels(15)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, 3x3s2_varying_width_adjustment) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t adjustment_width = 1; adjustment_width <= 2; adjustment_width++) {
    DeconvolutionOperatorTester()
      .input_size(10, 9)
      .padding(1)
      .adjustment_width(adjustment_width)
      .kernel_size(3, 3)
      .stride(2)
      .group_input_channels(15)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, 3x3s2_varying_input_height) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_height = 8; input_height <= 12; input_height++) {
    DeconvolutionOperatorTester()
      .input_size(input_height, 9)
      .padding(1)
      .kernel_size(3, 3)
      .stride(2)
      .group_input_channels(15)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, 3x3s2_varying_input_width) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_width = 7; input_width <= 11; input_width++) {
    DeconvolutionOperatorTester()
      .input_size(10, input_width)
      .padding(1)
      .kernel_size(3, 3)
      .stride(2)
      .group_input_channels(15)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, 3x3s2_varying_input_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_channels = 1; input_channels <= 16; input_channels *= 4) {
    DeconvolutionOperatorTester()
      .input_size(10, 9)
      .padding(1)
      .kernel_size(3, 3)
      .stride(2)
      .group_input_channels(input_channels)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, 3x3s2_varying_output_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t output_channels = 1; output_channels <= xnn_params.q8.gemm.nr * 2; output_channels *= 2) {
    DeconvolutionOperatorTester()
      .input_size(10, 9)
      .padding(1)
      .kernel_size(3, 3)
      .stride(2)
      .group_input_channels(23)
      .group_output_channels(output_channels)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, 3x3s2_with_input_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .input_pixel_stride(28)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, 3x3s2_with_output_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .output_pixel_stride(xnn_params.q8.gemm.nr * 2 + 13)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, 3x3s2_with_qmin) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, 3x3s2_with_qmax) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestQ8();
}

/**************************** SUBCONV2D path, grouped ****************************/

TEST(DECONVOLUTION_OP_Q8, grouped_3x3s2) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .groups(2)
    .group_input_channels(17)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, grouped_Kx3s2) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t kernel_height = 2; kernel_height <= 5; kernel_height++) {
    DeconvolutionOperatorTester()
      .input_size(10, 9)
      .padding_width(1)
      .kernel_size(kernel_height, 3)
      .stride(2)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(3)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, grouped_3xKs2) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t kernel_width = 2; kernel_width <= 5; kernel_width++) {
    DeconvolutionOperatorTester()
      .input_size(10, 9)
      .padding_height(1)
      .kernel_size(3, kernel_width)
      .stride(2)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(3)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, grouped_3x3sSx1) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t stride_height = 2; stride_height <= 3; stride_height++) {
    DeconvolutionOperatorTester()
      .input_size(10, 9)
      .padding(1)
      .padding_width(1)
      .kernel_size(3, 3)
      .stride_height(stride_height)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(3)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, grouped_3x3s1xS) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t stride_width = 2; stride_width <= 3; stride_width++) {
    DeconvolutionOperatorTester()
      .input_size(10, 9)
      .padding(1)
      .padding_width(1)
      .kernel_size(3, 3)
      .stride_width(stride_width)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(3)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, grouped_3x3s2_varying_height_padding) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t padding_top = 0; padding_top <= 2; padding_top++) {
    for (size_t padding_bottom = 0; padding_bottom <= 2; padding_bottom++) {
      DeconvolutionOperatorTester()
        .input_size(10, 9)
        .padding_width(1)
        .padding_top(padding_top)
        .padding_bottom(padding_bottom)
        .kernel_size(3, 3)
        .stride(2)
        .groups(2)
        .group_input_channels(17)
        .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
        .iterations(1)
        .TestQ8();
    }
  }
}

TEST(DECONVOLUTION_OP_Q8, grouped_3x3s2_varying_width_padding) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t padding_left = 0; padding_left <= 2; padding_left++) {
    for (size_t padding_right = 0; padding_right <= 2; padding_right++) {
      DeconvolutionOperatorTester()
        .input_size(10, 9)
        .padding_height(1)
        .padding_left(padding_left)
        .padding_right(padding_right)
        .kernel_size(3, 3)
        .stride(2)
        .groups(2)
        .group_input_channels(17)
        .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
        .iterations(1)
        .TestQ8();
    }
  }
}

TEST(DECONVOLUTION_OP_Q8, grouped_3x3s2_varying_height_adjustment) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t adjustment_height = 1; adjustment_height <= 2; adjustment_height++) {
    DeconvolutionOperatorTester()
      .input_size(10, 9)
      .padding(1)
      .adjustment_height(adjustment_height)
      .kernel_size(3, 3)
      .stride(2)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, grouped_3x3s2_varying_width_adjustment) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t adjustment_width = 1; adjustment_width <= 2; adjustment_width++) {
    DeconvolutionOperatorTester()
      .input_size(10, 9)
      .padding(1)
      .adjustment_width(adjustment_width)
      .kernel_size(3, 3)
      .stride(2)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, grouped_3x3s2_varying_input_height) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_height = 8; input_height <= 12; input_height++) {
    DeconvolutionOperatorTester()
      .input_size(input_height, 9)
      .padding(1)
      .kernel_size(3, 3)
      .stride(2)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, grouped_3x3s2_varying_input_width) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_width = 7; input_width <= 11; input_width++) {
    DeconvolutionOperatorTester()
      .input_size(10, input_width)
      .padding(1)
      .kernel_size(3, 3)
      .stride(2)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, grouped_3x3s2_varying_input_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_channels = 14; input_channels <= 20; input_channels++) {
    DeconvolutionOperatorTester()
      .input_size(10, 9)
      .padding(1)
      .kernel_size(3, 3)
      .stride(2)
      .groups(2)
      .group_input_channels(input_channels)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, grouped_3x3s2_varying_output_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t output_channels = 1; output_channels <= xnn_params.q8.gemm.nr * 2; output_channels *= 2) {
    DeconvolutionOperatorTester()
      .input_size(10, 9)
      .padding(1)
      .kernel_size(3, 3)
      .stride(2)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(output_channels)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, grouped_3x3s2_with_input_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .groups(2)
    .group_input_channels(17)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .input_pixel_stride(37)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, grouped_3x3s2_with_output_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .groups(2)
    .group_input_channels(17)
    .group_output_channels(xnn_params.q8.gemm.nr + 3)
    .output_pixel_stride(xnn_params.q8.gemm.nr * 2 + 13)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, grouped_3x3s2_with_qmin) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .groups(2)
    .group_input_channels(17)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, grouped_3x3s2_with_qmax) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .groups(2)
    .group_input_channels(17)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestQ8();
}

/**************************** SUBCONV2D path, batched ****************************/

TEST(DECONVOLUTION_OP_Q8, batched_3x3s2) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .group_input_channels(15)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, batched_Kx3s2) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t kernel_height = 2; kernel_height <= 5; kernel_height++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, 9)
      .padding_width(1)
      .kernel_size(kernel_height, 3)
      .stride(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(3)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_3xKs2) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t kernel_width = 2; kernel_width <= 5; kernel_width++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, 9)
      .padding_height(1)
      .kernel_size(3, kernel_width)
      .stride(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(3)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_3x3sSx1) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t stride_height = 2; stride_height <= 3; stride_height++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, 9)
      .padding(1)
      .padding_width(1)
      .kernel_size(3, 3)
      .stride_height(stride_height)
      .group_input_channels(17)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(3)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_3x3s1xS) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t stride_width = 2; stride_width <= 3; stride_width++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, 9)
      .padding(1)
      .padding_width(1)
      .kernel_size(3, 3)
      .stride_width(stride_width)
      .group_input_channels(17)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(3)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_3x3s2_varying_height_padding) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t padding_top = 0; padding_top <= 2; padding_top++) {
    for (size_t padding_bottom = 0; padding_bottom <= 2; padding_bottom++) {
      DeconvolutionOperatorTester()
        .batch_size(2)
        .input_size(10, 9)
        .padding_width(1)
        .padding_top(padding_top)
        .padding_bottom(padding_bottom)
        .kernel_size(3, 3)
        .stride(2)
        .group_input_channels(15)
        .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
        .iterations(1)
        .TestQ8();
    }
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_3x3s2_varying_width_padding) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t padding_left = 0; padding_left <= 2; padding_left++) {
    for (size_t padding_right = 0; padding_right <= 2; padding_right++) {
      DeconvolutionOperatorTester()
        .batch_size(2)
        .input_size(10, 9)
        .padding_height(1)
        .padding_left(padding_left)
        .padding_right(padding_right)
        .kernel_size(3, 3)
        .stride(2)
        .group_input_channels(15)
        .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
        .iterations(1)
        .TestQ8();
    }
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_3x3s2_varying_height_adjustment) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t adjustment_height = 1; adjustment_height <= 2; adjustment_height++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, 9)
      .padding(1)
      .adjustment_height(adjustment_height)
      .kernel_size(3, 3)
      .stride(2)
      .group_input_channels(15)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_3x3s2_varying_width_adjustment) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t adjustment_width = 1; adjustment_width <= 2; adjustment_width++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, 9)
      .padding(1)
      .adjustment_width(adjustment_width)
      .kernel_size(3, 3)
      .stride(2)
      .group_input_channels(15)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_3x3s2_varying_input_height) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_height = 8; input_height <= 12; input_height++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(input_height, 9)
      .padding(1)
      .kernel_size(3, 3)
      .stride(2)
      .group_input_channels(15)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_3x3s2_varying_input_width) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_width = 7; input_width <= 11; input_width++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, input_width)
      .padding(1)
      .kernel_size(3, 3)
      .stride(2)
      .group_input_channels(15)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_3x3s2_varying_input_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_channels = 1; input_channels <= 16; input_channels *= 4) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, 9)
      .padding(1)
      .kernel_size(3, 3)
      .stride(2)
      .group_input_channels(input_channels)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_3x3s2_varying_output_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t output_channels = 1; output_channels <= xnn_params.q8.gemm.nr * 2; output_channels *= 2) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, 9)
      .padding(1)
      .kernel_size(3, 3)
      .stride(2)
      .group_input_channels(23)
      .group_output_channels(output_channels)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_3x3s2_with_input_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .input_pixel_stride(28)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, batched_3x3s2_with_output_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .output_pixel_stride(xnn_params.q8.gemm.nr * 2 + 13)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, batched_3x3s2_with_qmin) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, batched_3x3s2_with_qmax) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestQ8();
}

/**************************** SUBCONV2D path, grouped, batched ****************************/

TEST(DECONVOLUTION_OP_Q8, batched_grouped_3x3s2) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .groups(2)
    .group_input_channels(17)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_Kx3s2) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t kernel_height = 2; kernel_height <= 5; kernel_height++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, 9)
      .padding_width(1)
      .kernel_size(kernel_height, 3)
      .stride(2)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(3)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_3xKs2) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t kernel_width = 2; kernel_width <= 5; kernel_width++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, 9)
      .padding_height(1)
      .kernel_size(3, kernel_width)
      .stride(2)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(3)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_3x3sSx1) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t stride_height = 2; stride_height <= 3; stride_height++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, 9)
      .padding(1)
      .padding_width(1)
      .kernel_size(3, 3)
      .stride_height(stride_height)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(3)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_3x3s1xS) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t stride_width = 2; stride_width <= 3; stride_width++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, 9)
      .padding(1)
      .padding_width(1)
      .kernel_size(3, 3)
      .stride_width(stride_width)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(3)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_3x3s2_varying_height_padding) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t padding_top = 0; padding_top <= 2; padding_top++) {
    for (size_t padding_bottom = 0; padding_bottom <= 2; padding_bottom++) {
      DeconvolutionOperatorTester()
        .batch_size(2)
        .input_size(10, 9)
        .padding_width(1)
        .padding_top(padding_top)
        .padding_bottom(padding_bottom)
        .kernel_size(3, 3)
        .stride(2)
        .groups(2)
        .group_input_channels(17)
        .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
        .iterations(1)
        .TestQ8();
    }
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_3x3s2_varying_width_padding) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t padding_left = 0; padding_left <= 2; padding_left++) {
    for (size_t padding_right = 0; padding_right <= 2; padding_right++) {
      DeconvolutionOperatorTester()
        .batch_size(2)
        .input_size(10, 9)
        .padding_height(1)
        .padding_left(padding_left)
        .padding_right(padding_right)
        .kernel_size(3, 3)
        .stride(2)
        .groups(2)
        .group_input_channels(17)
        .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
        .iterations(1)
        .TestQ8();
    }
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_3x3s2_varying_height_adjustment) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t adjustment_height = 1; adjustment_height <= 2; adjustment_height++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, 9)
      .padding(1)
      .adjustment_height(adjustment_height)
      .kernel_size(3, 3)
      .stride(2)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_3x3s2_varying_width_adjustment) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t adjustment_width = 1; adjustment_width <= 2; adjustment_width++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, 9)
      .padding(1)
      .adjustment_width(adjustment_width)
      .kernel_size(3, 3)
      .stride(2)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_3x3s2_varying_input_height) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_height = 8; input_height <= 12; input_height++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(input_height, 9)
      .padding(1)
      .kernel_size(3, 3)
      .stride(2)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_3x3s2_varying_input_width) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_width = 7; input_width <= 11; input_width++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, input_width)
      .padding(1)
      .kernel_size(3, 3)
      .stride(2)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_3x3s2_varying_input_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_channels = 14; input_channels <= 20; input_channels++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, 9)
      .padding(1)
      .kernel_size(3, 3)
      .stride(2)
      .groups(2)
      .group_input_channels(input_channels)
      .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_3x3s2_varying_output_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t output_channels = 1; output_channels <= xnn_params.q8.gemm.nr * 2; output_channels *= 2) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, 9)
      .padding(1)
      .kernel_size(3, 3)
      .stride(2)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(output_channels)
      .iterations(1)
      .TestQ8();
  }
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_3x3s2_with_input_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .groups(2)
    .group_input_channels(17)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .input_pixel_stride(37)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_3x3s2_with_output_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .groups(2)
    .group_input_channels(17)
    .group_output_channels(xnn_params.q8.gemm.nr + 3)
    .output_pixel_stride(xnn_params.q8.gemm.nr * 2 + 13)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_3x3s2_with_qmin) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .groups(2)
    .group_input_channels(17)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestQ8();
}

TEST(DECONVOLUTION_OP_Q8, batched_grouped_3x3s2_with_qmax) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .groups(2)
    .group_input_channels(17)
    .group_output_channels(xnn_params.q8.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestQ8();
}

/**************************** SUBCONV2D path, setup ****************************/

TEST(DECONVOLUTION_OP_Q8, 3x3s2_setup_changing_batch) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .next_batch_size(5)
    .input_height(8)
    .input_width(9)
    .kernel_height(3)
    .kernel_width(5)
    .stride(2)
    .groups(2)
    .group_input_channels(15)
    .group_output_channels(17)
    .TestSetupQ8();
}

TEST(DECONVOLUTION_OP_Q8, 3x3s2_setup_changing_height) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_height(8)
    .input_width(9)
    .next_input_height(10)
    .kernel_height(3)
    .kernel_width(5)
    .stride(2)
    .groups(2)
    .group_input_channels(15)
    .group_output_channels(17)
    .TestSetupQ8();
}

TEST(DECONVOLUTION_OP_Q8, 3x3s2_setup_changing_width) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_height(8)
    .input_width(9)
    .next_input_width(10)
    .kernel_height(3)
    .kernel_width(5)
    .stride(2)
    .groups(2)
    .group_input_channels(15)
    .group_output_channels(17)
    .TestSetupQ8();
}

/**************************** Future GEMM path ****************************/

TEST(DECONVOLUTION_OP_F32, 1x1) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(27, 29)
    .kernel_size(1, 1)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, 1x1_varying_input_width) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_width = 25; input_width <= 31; input_width++) {
    DeconvolutionOperatorTester()
      .input_size(input_width, 29)
      .kernel_size(1, 1)
      .group_input_channels(23)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, 1x1_varying_input_height) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_height = 27; input_height <= 33; input_height++) {
    DeconvolutionOperatorTester()
      .input_size(27, input_height)
      .kernel_size(1, 1)
      .group_input_channels(23)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, 1x1_varying_input_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_channels = 1; input_channels <= 16; input_channels *= 4) {
    DeconvolutionOperatorTester()
      .input_size(27, 29)
      .kernel_size(1, 1)
      .group_input_channels(input_channels)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, 1x1_varying_output_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t output_channels = 1; output_channels <= xnn_params.f32.gemm.nr * 2; output_channels *= 2) {
    DeconvolutionOperatorTester()
      .input_size(27, 29)
      .kernel_size(1, 1)
      .group_input_channels(23)
      .group_output_channels(output_channels)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, 1x1_with_input_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(27, 29)
    .kernel_size(1, 1)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .input_pixel_stride(28)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, 1x1_with_output_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(27, 29)
    .kernel_size(1, 1)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .output_pixel_stride(xnn_params.f32.gemm.nr * 2 + 13)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, 1x1_with_qmin) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(27, 29)
    .kernel_size(1, 1)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, 1x1_with_qmax) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(27, 29)
    .kernel_size(1, 1)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestF32();
}

/**************************** Future GEMM path, grouped ****************************/

TEST(DECONVOLUTION_OP_F32, grouped_1x1) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(27, 29)
    .kernel_size(1, 1)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, grouped_1x1_varying_input_width) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_width = 25; input_width <= 31; input_width++) {
    DeconvolutionOperatorTester()
      .input_size(input_width, 29)
      .kernel_size(1, 1)
      .groups(2)
      .group_input_channels(23)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, grouped_1x1_varying_input_height) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_height = 27; input_height <= 33; input_height++) {
    DeconvolutionOperatorTester()
      .input_size(27, input_height)
      .kernel_size(1, 1)
      .groups(2)
      .group_input_channels(23)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, grouped_1x1_varying_input_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_channels = 1; input_channels <= 16; input_channels *= 4) {
    DeconvolutionOperatorTester()
      .input_size(27, 29)
      .kernel_size(1, 1)
      .groups(2)
      .group_input_channels(input_channels)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, grouped_1x1_varying_output_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t output_channels = 1; output_channels <= xnn_params.f32.gemm.nr * 2; output_channels *= 2) {
    DeconvolutionOperatorTester()
      .input_size(27, 29)
      .kernel_size(1, 1)
      .groups(2)
      .group_input_channels(23)
      .group_output_channels(output_channels)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, grouped_1x1_with_input_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(27, 29)
    .kernel_size(1, 1)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .input_pixel_stride(47)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, grouped_1x1_with_output_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(27, 29)
    .kernel_size(1, 1)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr + 3)
    .output_pixel_stride(xnn_params.f32.gemm.nr * 2 + 13)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, grouped_1x1_with_qmin) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(27, 29)
    .kernel_size(1, 1)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, grouped_1x1_with_qmax) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(27, 29)
    .kernel_size(1, 1)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestF32();
}

/**************************** Future GEMM path, batched ****************************/

TEST(DECONVOLUTION_OP_F32, batched_1x1) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(27, 29)
    .kernel_size(1, 1)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, batched_1x1_varying_input_width) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_width = 25; input_width <= 31; input_width++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(input_width, 29)
      .kernel_size(1, 1)
      .group_input_channels(23)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_1x1_varying_input_height) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_height = 27; input_height <= 33; input_height++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(27, input_height)
      .kernel_size(1, 1)
      .group_input_channels(23)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_1x1_varying_input_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_channels = 1; input_channels <= 16; input_channels *= 4) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(27, 29)
      .kernel_size(1, 1)
      .group_input_channels(input_channels)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_1x1_varying_output_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t output_channels = 1; output_channels <= xnn_params.f32.gemm.nr * 2; output_channels *= 2) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(27, 29)
      .kernel_size(1, 1)
      .group_input_channels(23)
      .group_output_channels(output_channels)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_1x1_with_input_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(27, 29)
    .kernel_size(1, 1)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .input_pixel_stride(28)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, batched_1x1_with_output_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(27, 29)
    .kernel_size(1, 1)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .output_pixel_stride(xnn_params.f32.gemm.nr * 2 + 13)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, batched_1x1_with_qmin) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(27, 29)
    .kernel_size(1, 1)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, batched_1x1_with_qmax) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(27, 29)
    .kernel_size(1, 1)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestF32();
}

/**************************** Future GEMM path, batched, grouped ****************************/

TEST(DECONVOLUTION_OP_F32, batched_grouped_1x1) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(27, 29)
    .kernel_size(1, 1)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_1x1_varying_input_width) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_width = 25; input_width <= 31; input_width++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(input_width, 29)
      .kernel_size(1, 1)
      .groups(2)
      .group_input_channels(23)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_1x1_varying_input_height) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_height = 27; input_height <= 33; input_height++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(27, input_height)
      .kernel_size(1, 1)
      .groups(2)
      .group_input_channels(23)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_1x1_varying_input_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_channels = 1; input_channels <= 16; input_channels *= 4) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(27, 29)
      .kernel_size(1, 1)
      .groups(2)
      .group_input_channels(input_channels)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_1x1_varying_output_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t output_channels = 1; output_channels <= xnn_params.f32.gemm.nr * 2; output_channels *= 2) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(27, 29)
      .kernel_size(1, 1)
      .groups(2)
      .group_input_channels(23)
      .group_output_channels(output_channels)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_1x1_with_input_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(27, 29)
    .kernel_size(1, 1)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .input_pixel_stride(47)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_1x1_with_output_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(27, 29)
    .kernel_size(1, 1)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr + 3)
    .output_pixel_stride(xnn_params.f32.gemm.nr * 2 + 13)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_1x1_with_qmin) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(27, 29)
    .kernel_size(1, 1)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_1x1_with_qmax) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(27, 29)
    .kernel_size(1, 1)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestF32();
}

/**************************** CONV path ****************************/

TEST(DECONVOLUTION_OP_F32, 3x3) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .group_input_channels(15)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, Kx3) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t kernel_height = 1; kernel_height <= 4; kernel_height *= 2) {
    DeconvolutionOperatorTester()
      .input_size(13, 12)
      .padding_width(1)
      .kernel_size(kernel_height, 3)
      .group_input_channels(17)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(3)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, 3xK) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t kernel_width = 1; kernel_width <= 4; kernel_width *= 2) {
    DeconvolutionOperatorTester()
      .input_size(13, 12)
      .padding_height(1)
      .kernel_size(3, kernel_width)
      .group_input_channels(17)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(3)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, 3x3_varying_height_padding) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t padding_top = 0; padding_top <= 2; padding_top++) {
    for (size_t padding_bottom = 0; padding_bottom <= 2; padding_bottom++) {
      DeconvolutionOperatorTester()
        .input_size(13, 12)
        .padding_width(1)
        .padding_top(padding_top)
        .padding_bottom(padding_bottom)
        .kernel_size(3, 3)
        .group_input_channels(15)
        .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
        .iterations(1)
        .TestF32();
    }
  }
}

TEST(DECONVOLUTION_OP_F32, 3x3_varying_width_padding) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t padding_left = 0; padding_left <= 2; padding_left++) {
    for (size_t padding_right = 0; padding_right <= 2; padding_right++) {
      DeconvolutionOperatorTester()
        .input_size(13, 12)
        .padding_height(1)
        .padding_left(padding_left)
        .padding_right(padding_right)
        .kernel_size(3, 3)
        .group_input_channels(15)
        .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
        .iterations(1)
        .TestF32();
    }
  }
}

TEST(DECONVOLUTION_OP_F32, 3x3_varying_height_adjustment) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t adjustment_height = 1; adjustment_height <= 2; adjustment_height++) {
    DeconvolutionOperatorTester()
      .input_size(13, 12)
      .padding(1)
      .adjustment_height(adjustment_height)
      .kernel_size(3, 3)
      .group_input_channels(15)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, 3x3_varying_width_adjustment) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t adjustment_width = 1; adjustment_width <= 2; adjustment_width++) {
    DeconvolutionOperatorTester()
      .input_size(13, 12)
      .padding(1)
      .adjustment_width(adjustment_width)
      .kernel_size(3, 3)
      .group_input_channels(15)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, 3x3_varying_input_height) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_height = 10; input_height <= 15; input_height++) {
    DeconvolutionOperatorTester()
      .input_size(input_height, 12)
      .padding(1)
      .kernel_size(3, 3)
      .group_input_channels(15)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, 3x3_varying_input_width) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_width = 9; input_width <= 14; input_width++) {
    DeconvolutionOperatorTester()
      .input_size(13, input_width)
      .padding(1)
      .kernel_size(3, 3)
      .group_input_channels(15)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, 3x3_varying_input_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_channels = 1; input_channels <= 16; input_channels *= 4) {
    DeconvolutionOperatorTester()
      .input_size(13, 12)
      .padding(1)
      .kernel_size(3, 3)
      .group_input_channels(input_channels)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, 3x3_varying_output_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t output_channels = 1; output_channels <= xnn_params.f32.gemm.nr * 2; output_channels *= 2) {
    DeconvolutionOperatorTester()
      .input_size(13, 12)
      .padding(1)
      .kernel_size(3, 3)
      .group_input_channels(23)
      .group_output_channels(output_channels)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, 3x3_with_height_dilation) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t dilation_height = 2; dilation_height <= 3; dilation_height++) {
    DeconvolutionOperatorTester()
      .input_size(13, 12)
      .padding(1)
      .kernel_size(3, 3)
      .dilation_height(dilation_height)
      .group_input_channels(23)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(3)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, 3x3_with_width_dilation) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t dilation_width = 2; dilation_width <= 3; dilation_width++) {
    DeconvolutionOperatorTester()
      .input_size(13, 12)
      .padding(1)
      .kernel_size(3, 3)
      .dilation_width(dilation_width)
      .group_input_channels(23)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(3)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, 3x3_with_height_dilation_and_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .dilation_height(3)
    .stride_height(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, 3x3_with_width_dilation_and_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .dilation_width(3)
    .stride_width(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, 3x3_with_input_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .input_pixel_stride(28)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, 3x3_with_output_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .output_pixel_stride(xnn_params.f32.gemm.nr * 2 + 13)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, 3x3_with_qmin) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, 3x3_with_qmax) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestF32();
}

/**************************** CONV path, grouped ****************************/

TEST(DECONVOLUTION_OP_F32, grouped_3x3) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .groups(2)
    .group_input_channels(15)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, grouped_Kx3) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t kernel_height = 1; kernel_height <= 4; kernel_height *= 2) {
    DeconvolutionOperatorTester()
      .input_size(13, 12)
      .padding_width(1)
      .kernel_size(kernel_height, 3)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(3)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, grouped_3xK) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t kernel_width = 1; kernel_width <= 4; kernel_width *= 2) {
    DeconvolutionOperatorTester()
      .input_size(13, 12)
      .padding_height(1)
      .kernel_size(3, kernel_width)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(3)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, grouped_3x3_varying_height_padding) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t padding_top = 0; padding_top <= 2; padding_top++) {
    for (size_t padding_bottom = 0; padding_bottom <= 2; padding_bottom++) {
      DeconvolutionOperatorTester()
        .input_size(13, 12)
        .padding_width(1)
        .padding_top(padding_top)
        .padding_bottom(padding_bottom)
        .kernel_size(3, 3)
        .groups(2)
        .group_input_channels(15)
        .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
        .iterations(1)
        .TestF32();
    }
  }
}

TEST(DECONVOLUTION_OP_F32, grouped_3x3_varying_width_padding) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t padding_left = 0; padding_left <= 2; padding_left++) {
    for (size_t padding_right = 0; padding_right <= 2; padding_right++) {
      DeconvolutionOperatorTester()
        .input_size(13, 12)
        .padding_height(1)
        .padding_left(padding_left)
        .padding_right(padding_right)
        .kernel_size(3, 3)
        .groups(2)
        .group_input_channels(15)
        .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
        .iterations(1)
        .TestF32();
    }
  }
}

TEST(DECONVOLUTION_OP_F32, grouped_3x3_varying_height_adjustment) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t adjustment_height = 1; adjustment_height <= 2; adjustment_height++) {
    DeconvolutionOperatorTester()
      .input_size(13, 12)
      .padding(1)
      .adjustment_height(adjustment_height)
      .kernel_size(3, 3)
      .groups(2)
      .group_input_channels(15)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, grouped_3x3_varying_width_adjustment) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t adjustment_width = 1; adjustment_width <= 2; adjustment_width++) {
    DeconvolutionOperatorTester()
      .input_size(13, 12)
      .padding(1)
      .adjustment_width(adjustment_width)
      .kernel_size(3, 3)
      .groups(2)
      .group_input_channels(15)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, grouped_3x3_varying_input_height) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_height = 10; input_height <= 15; input_height++) {
    DeconvolutionOperatorTester()
      .input_size(input_height, 12)
      .padding(1)
      .kernel_size(3, 3)
      .groups(2)
      .group_input_channels(15)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, grouped_3x3_varying_input_width) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_width = 9; input_width <= 14; input_width++) {
    DeconvolutionOperatorTester()
      .input_size(13, input_width)
      .padding(1)
      .kernel_size(3, 3)
      .groups(2)
      .group_input_channels(15)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, grouped_3x3_varying_input_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_channels = 1; input_channels <= 16; input_channels *= 4) {
    DeconvolutionOperatorTester()
      .input_size(13, 12)
      .padding(1)
      .kernel_size(3, 3)
      .groups(2)
      .group_input_channels(input_channels)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, grouped_3x3_varying_output_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t output_channels = 1; output_channels <= xnn_params.f32.gemm.nr * 2; output_channels *= 2) {
    DeconvolutionOperatorTester()
      .input_size(13, 12)
      .padding(1)
      .kernel_size(3, 3)
      .groups(2)
      .group_input_channels(23)
      .group_output_channels(output_channels)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, grouped_3x3_with_height_dilation) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t dilation_height = 2; dilation_height <= 3; dilation_height++) {
    DeconvolutionOperatorTester()
      .input_size(13, 12)
      .padding(1)
      .kernel_size(3, 3)
      .dilation_height(dilation_height)
      .groups(2)
      .group_input_channels(23)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(3)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, grouped_3x3_with_width_dilation) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t dilation_width = 2; dilation_width <= 3; dilation_width++) {
    DeconvolutionOperatorTester()
      .input_size(13, 12)
      .padding(1)
      .kernel_size(3, 3)
      .dilation_width(dilation_width)
      .groups(2)
      .group_input_channels(23)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(3)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, grouped_3x3_with_height_dilation_and_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .dilation_height(3)
    .stride_height(2)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, grouped_3x3_with_width_dilation_and_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .dilation_width(3)
    .stride_width(2)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, grouped_3x3_with_input_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .input_pixel_stride(47)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, grouped_3x3_with_output_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr + 3)
    .output_pixel_stride(xnn_params.f32.gemm.nr * 2 + 13)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, grouped_3x3_with_qmin) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, grouped_3x3_with_qmax) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestF32();
}

/**************************** CONV path, batched ****************************/

TEST(DECONVOLUTION_OP_F32, batched_3x3) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .group_input_channels(15)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, batched_Kx3) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t kernel_height = 1; kernel_height <= 4; kernel_height *= 2) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, 12)
      .padding_width(1)
      .kernel_size(kernel_height, 3)
      .group_input_channels(17)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(3)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_3xK) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t kernel_width = 1; kernel_width <= 4; kernel_width *= 2) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, 12)
      .padding_height(1)
      .kernel_size(3, kernel_width)
      .group_input_channels(17)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(3)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_3x3_varying_height_padding) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t padding_top = 0; padding_top <= 2; padding_top++) {
    for (size_t padding_bottom = 0; padding_bottom <= 2; padding_bottom++) {
      DeconvolutionOperatorTester()
        .batch_size(2)
        .input_size(13, 12)
        .padding_width(1)
        .padding_top(padding_top)
        .padding_bottom(padding_bottom)
        .kernel_size(3, 3)
        .group_input_channels(15)
        .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
        .iterations(1)
        .TestF32();
    }
  }
}

TEST(DECONVOLUTION_OP_F32, batched_3x3_varying_width_padding) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t padding_left = 0; padding_left <= 2; padding_left++) {
    for (size_t padding_right = 0; padding_right <= 2; padding_right++) {
      DeconvolutionOperatorTester()
        .batch_size(2)
        .input_size(13, 12)
        .padding_height(1)
        .padding_left(padding_left)
        .padding_right(padding_right)
        .kernel_size(3, 3)
        .group_input_channels(15)
        .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
        .iterations(1)
        .TestF32();
    }
  }
}

TEST(DECONVOLUTION_OP_F32, batched_3x3_varying_height_adjustment) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t adjustment_height = 1; adjustment_height <= 2; adjustment_height++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, 12)
      .padding(1)
      .adjustment_height(adjustment_height)
      .kernel_size(3, 3)
      .group_input_channels(15)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_3x3_varying_width_adjustment) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t adjustment_width = 1; adjustment_width <= 2; adjustment_width++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, 12)
      .padding(1)
      .adjustment_width(adjustment_width)
      .kernel_size(3, 3)
      .group_input_channels(15)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_3x3_varying_input_height) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_height = 10; input_height <= 15; input_height++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(input_height, 12)
      .padding(1)
      .kernel_size(3, 3)
      .group_input_channels(15)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_3x3_varying_input_width) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_width = 9; input_width <= 14; input_width++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, input_width)
      .padding(1)
      .kernel_size(3, 3)
      .group_input_channels(15)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_3x3_varying_input_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_channels = 1; input_channels <= 16; input_channels *= 4) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, 12)
      .padding(1)
      .kernel_size(3, 3)
      .group_input_channels(input_channels)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_3x3_varying_output_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t output_channels = 1; output_channels <= xnn_params.f32.gemm.nr * 2; output_channels *= 2) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, 12)
      .padding(1)
      .kernel_size(3, 3)
      .group_input_channels(23)
      .group_output_channels(output_channels)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_3x3_with_height_dilation) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t dilation_height = 2; dilation_height <= 3; dilation_height++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, 12)
      .padding(1)
      .kernel_size(3, 3)
      .dilation_height(dilation_height)
      .group_input_channels(23)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(3)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_3x3_with_width_dilation) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t dilation_width = 2; dilation_width <= 3; dilation_width++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, 12)
      .padding(1)
      .kernel_size(3, 3)
      .dilation_width(dilation_width)
      .group_input_channels(23)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(3)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_3x3_with_height_dilation_and_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .dilation_height(3)
    .stride_height(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, batched_3x3_with_width_dilation_and_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .dilation_width(3)
    .stride_width(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, batched_3x3_with_input_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .input_pixel_stride(28)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, batched_3x3_with_output_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .output_pixel_stride(xnn_params.f32.gemm.nr * 2 + 13)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, batched_3x3_with_qmin) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, batched_3x3_with_qmax) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestF32();
}

/**************************** CONV path, grouped, batched ****************************/

TEST(DECONVOLUTION_OP_F32, batched_grouped_3x3) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .groups(2)
    .group_input_channels(15)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_Kx3) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t kernel_height = 1; kernel_height <= 4; kernel_height *= 2) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, 12)
      .padding_width(1)
      .kernel_size(kernel_height, 3)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(3)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_3xK) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t kernel_width = 1; kernel_width <= 4; kernel_width *= 2) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, 12)
      .padding_height(1)
      .kernel_size(3, kernel_width)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(3)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_3x3_varying_height_padding) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t padding_top = 0; padding_top <= 2; padding_top++) {
    for (size_t padding_bottom = 0; padding_bottom <= 2; padding_bottom++) {
      DeconvolutionOperatorTester()
        .batch_size(2)
        .input_size(13, 12)
        .padding_width(1)
        .padding_top(padding_top)
        .padding_bottom(padding_bottom)
        .kernel_size(3, 3)
        .groups(2)
        .group_input_channels(15)
        .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
        .iterations(1)
        .TestF32();
    }
  }
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_3x3_varying_width_padding) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t padding_left = 0; padding_left <= 2; padding_left++) {
    for (size_t padding_right = 0; padding_right <= 2; padding_right++) {
      DeconvolutionOperatorTester()
        .batch_size(2)
        .input_size(13, 12)
        .padding_height(1)
        .padding_left(padding_left)
        .padding_right(padding_right)
        .kernel_size(3, 3)
        .groups(2)
        .group_input_channels(15)
        .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
        .iterations(1)
        .TestF32();
    }
  }
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_3x3_varying_height_adjustment) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t adjustment_height = 1; adjustment_height <= 2; adjustment_height++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, 12)
      .padding(1)
      .adjustment_height(adjustment_height)
      .kernel_size(3, 3)
      .groups(2)
      .group_input_channels(15)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_3x3_varying_width_adjustment) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t adjustment_width = 1; adjustment_width <= 2; adjustment_width++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, 12)
      .padding(1)
      .adjustment_width(adjustment_width)
      .kernel_size(3, 3)
      .groups(2)
      .group_input_channels(15)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_3x3_varying_input_height) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_height = 10; input_height <= 15; input_height++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(input_height, 12)
      .padding(1)
      .kernel_size(3, 3)
      .groups(2)
      .group_input_channels(15)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_3x3_varying_input_width) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_width = 9; input_width <= 14; input_width++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, input_width)
      .padding(1)
      .kernel_size(3, 3)
      .groups(2)
      .group_input_channels(15)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_3x3_varying_input_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_channels = 1; input_channels <= 16; input_channels *= 4) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, 12)
      .padding(1)
      .kernel_size(3, 3)
      .groups(2)
      .group_input_channels(input_channels)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_3x3_varying_output_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t output_channels = 1; output_channels <= xnn_params.f32.gemm.nr * 2; output_channels *= 2) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, 12)
      .padding(1)
      .kernel_size(3, 3)
      .groups(2)
      .group_input_channels(23)
      .group_output_channels(output_channels)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_3x3_with_height_dilation) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t dilation_height = 2; dilation_height <= 3; dilation_height++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, 12)
      .padding(1)
      .kernel_size(3, 3)
      .dilation_height(dilation_height)
      .groups(2)
      .group_input_channels(23)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(3)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_3x3_with_width_dilation) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t dilation_width = 2; dilation_width <= 3; dilation_width++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(13, 12)
      .padding(1)
      .kernel_size(3, 3)
      .dilation_width(dilation_width)
      .groups(2)
      .group_input_channels(23)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(3)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_3x3_with_height_dilation_and_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .dilation_height(3)
    .stride_width(2)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_3x3_with_width_dilation_and_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .dilation_width(3)
    .stride_width(2)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_3x3_with_input_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .input_pixel_stride(47)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_3x3_with_output_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr + 3)
    .output_pixel_stride(xnn_params.f32.gemm.nr * 2 + 13)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_3x3_with_qmin) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_3x3_with_qmax) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(13, 12)
    .padding(1)
    .kernel_size(3, 3)
    .groups(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestF32();
}

/**************************** CONV path, setup ****************************/

TEST(DECONVOLUTION_OP_F32, 3x3_setup_changing_batch) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .next_batch_size(5)
    .input_height(12)
    .input_width(13)
    .kernel_height(3)
    .kernel_width(5)
    .groups(2)
    .group_input_channels(15)
    .group_output_channels(17)
    .TestSetupF32();
}

TEST(DECONVOLUTION_OP_F32, 3x3_setup_changing_height) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_height(12)
    .input_width(13)
    .next_input_height(14)
    .kernel_height(3)
    .kernel_width(5)
    .groups(2)
    .group_input_channels(15)
    .group_output_channels(17)
    .TestSetupF32();
}

TEST(DECONVOLUTION_OP_F32, 3x3_setup_changing_width) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_height(12)
    .input_width(13)
    .next_input_width(14)
    .kernel_height(3)
    .kernel_width(5)
    .groups(2)
    .group_input_channels(15)
    .group_output_channels(17)
    .TestSetupF32();
}

/**************************** SUBCONV2D path ****************************/

TEST(DECONVOLUTION_OP_F32, 3x3s2) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .group_input_channels(15)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, Kx3s2) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t kernel_height = 2; kernel_height <= 5; kernel_height++) {
    DeconvolutionOperatorTester()
      .input_size(10, 9)
      .padding_width(1)
      .kernel_size(kernel_height, 3)
      .stride(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(3)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, 3xKs2) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t kernel_width = 2; kernel_width <= 5; kernel_width++) {
    DeconvolutionOperatorTester()
      .input_size(10, 9)
      .padding_height(1)
      .kernel_size(3, kernel_width)
      .stride(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(3)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, 3x3sSx1) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t stride_height = 2; stride_height <= 3; stride_height++) {
    DeconvolutionOperatorTester()
      .input_size(10, 9)
      .padding(1)
      .padding_width(1)
      .kernel_size(3, 3)
      .stride_height(stride_height)
      .group_input_channels(17)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(3)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, 3x3s1xS) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t stride_width = 2; stride_width <= 3; stride_width++) {
    DeconvolutionOperatorTester()
      .input_size(10, 9)
      .padding(1)
      .padding_width(1)
      .kernel_size(3, 3)
      .stride_width(stride_width)
      .group_input_channels(17)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(3)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, 3x3s2_varying_height_padding) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t padding_top = 0; padding_top <= 2; padding_top++) {
    for (size_t padding_bottom = 0; padding_bottom <= 2; padding_bottom++) {
      DeconvolutionOperatorTester()
        .input_size(10, 9)
        .padding_width(1)
        .padding_top(padding_top)
        .padding_bottom(padding_bottom)
        .kernel_size(3, 3)
        .stride(2)
        .group_input_channels(15)
        .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
        .iterations(1)
        .TestF32();
    }
  }
}

TEST(DECONVOLUTION_OP_F32, 3x3s2_varying_width_padding) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t padding_left = 0; padding_left <= 2; padding_left++) {
    for (size_t padding_right = 0; padding_right <= 2; padding_right++) {
      DeconvolutionOperatorTester()
        .input_size(10, 9)
        .padding_height(1)
        .padding_left(padding_left)
        .padding_right(padding_right)
        .kernel_size(3, 3)
        .stride(2)
        .group_input_channels(15)
        .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
        .iterations(1)
        .TestF32();
    }
  }
}

TEST(DECONVOLUTION_OP_F32, 3x3s2_varying_height_adjustment) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t adjustment_height = 1; adjustment_height <= 2; adjustment_height++) {
    DeconvolutionOperatorTester()
      .input_size(10, 9)
      .padding(1)
      .adjustment_height(adjustment_height)
      .kernel_size(3, 3)
      .stride(2)
      .group_input_channels(15)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, 3x3s2_varying_width_adjustment) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t adjustment_width = 1; adjustment_width <= 2; adjustment_width++) {
    DeconvolutionOperatorTester()
      .input_size(10, 9)
      .padding(1)
      .adjustment_width(adjustment_width)
      .kernel_size(3, 3)
      .stride(2)
      .group_input_channels(15)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, 3x3s2_varying_input_height) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_height = 8; input_height <= 12; input_height++) {
    DeconvolutionOperatorTester()
      .input_size(input_height, 9)
      .padding(1)
      .kernel_size(3, 3)
      .stride(2)
      .group_input_channels(15)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, 3x3s2_varying_input_width) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_width = 7; input_width <= 11; input_width++) {
    DeconvolutionOperatorTester()
      .input_size(10, input_width)
      .padding(1)
      .kernel_size(3, 3)
      .stride(2)
      .group_input_channels(15)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, 3x3s2_varying_input_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_channels = 1; input_channels <= 16; input_channels *= 4) {
    DeconvolutionOperatorTester()
      .input_size(10, 9)
      .padding(1)
      .kernel_size(3, 3)
      .stride(2)
      .group_input_channels(input_channels)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, 3x3s2_varying_output_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t output_channels = 1; output_channels <= xnn_params.f32.gemm.nr * 2; output_channels *= 2) {
    DeconvolutionOperatorTester()
      .input_size(10, 9)
      .padding(1)
      .kernel_size(3, 3)
      .stride(2)
      .group_input_channels(23)
      .group_output_channels(output_channels)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, 3x3s2_with_input_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .input_pixel_stride(28)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, 3x3s2_with_output_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .output_pixel_stride(xnn_params.f32.gemm.nr * 2 + 13)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, 3x3s2_with_qmin) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, 3x3s2_with_qmax) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestF32();
}

/**************************** SUBCONV2D path, grouped ****************************/

TEST(DECONVOLUTION_OP_F32, grouped_3x3s2) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .groups(2)
    .group_input_channels(17)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, grouped_Kx3s2) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t kernel_height = 2; kernel_height <= 5; kernel_height++) {
    DeconvolutionOperatorTester()
      .input_size(10, 9)
      .padding_width(1)
      .kernel_size(kernel_height, 3)
      .stride(2)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(3)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, grouped_3xKs2) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t kernel_width = 2; kernel_width <= 5; kernel_width++) {
    DeconvolutionOperatorTester()
      .input_size(10, 9)
      .padding_height(1)
      .kernel_size(3, kernel_width)
      .stride(2)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(3)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, grouped_3x3sSx1) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t stride_height = 2; stride_height <= 3; stride_height++) {
    DeconvolutionOperatorTester()
      .input_size(10, 9)
      .padding(1)
      .padding_width(1)
      .kernel_size(3, 3)
      .stride_height(stride_height)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(3)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, grouped_3x3s1xS) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t stride_width = 2; stride_width <= 3; stride_width++) {
    DeconvolutionOperatorTester()
      .input_size(10, 9)
      .padding(1)
      .padding_width(1)
      .kernel_size(3, 3)
      .stride_width(stride_width)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(3)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, grouped_3x3s2_varying_height_padding) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t padding_top = 0; padding_top <= 2; padding_top++) {
    for (size_t padding_bottom = 0; padding_bottom <= 2; padding_bottom++) {
      DeconvolutionOperatorTester()
        .input_size(10, 9)
        .padding_width(1)
        .padding_top(padding_top)
        .padding_bottom(padding_bottom)
        .kernel_size(3, 3)
        .stride(2)
        .groups(2)
        .group_input_channels(17)
        .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
        .iterations(1)
        .TestF32();
    }
  }
}

TEST(DECONVOLUTION_OP_F32, grouped_3x3s2_varying_width_padding) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t padding_left = 0; padding_left <= 2; padding_left++) {
    for (size_t padding_right = 0; padding_right <= 2; padding_right++) {
      DeconvolutionOperatorTester()
        .input_size(10, 9)
        .padding_height(1)
        .padding_left(padding_left)
        .padding_right(padding_right)
        .kernel_size(3, 3)
        .stride(2)
        .groups(2)
        .group_input_channels(17)
        .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
        .iterations(1)
        .TestF32();
    }
  }
}

TEST(DECONVOLUTION_OP_F32, grouped_3x3s2_varying_height_adjustment) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t adjustment_height = 1; adjustment_height <= 2; adjustment_height++) {
    DeconvolutionOperatorTester()
      .input_size(10, 9)
      .padding(1)
      .adjustment_height(adjustment_height)
      .kernel_size(3, 3)
      .stride(2)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, grouped_3x3s2_varying_width_adjustment) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t adjustment_width = 1; adjustment_width <= 2; adjustment_width++) {
    DeconvolutionOperatorTester()
      .input_size(10, 9)
      .padding(1)
      .adjustment_width(adjustment_width)
      .kernel_size(3, 3)
      .stride(2)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, grouped_3x3s2_varying_input_height) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_height = 8; input_height <= 12; input_height++) {
    DeconvolutionOperatorTester()
      .input_size(input_height, 9)
      .padding(1)
      .kernel_size(3, 3)
      .stride(2)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, grouped_3x3s2_varying_input_width) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_width = 7; input_width <= 11; input_width++) {
    DeconvolutionOperatorTester()
      .input_size(10, input_width)
      .padding(1)
      .kernel_size(3, 3)
      .stride(2)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, grouped_3x3s2_varying_input_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_channels = 14; input_channels <= 20; input_channels++) {
    DeconvolutionOperatorTester()
      .input_size(10, 9)
      .padding(1)
      .kernel_size(3, 3)
      .stride(2)
      .groups(2)
      .group_input_channels(input_channels)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, grouped_3x3s2_varying_output_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t output_channels = 1; output_channels <= xnn_params.f32.gemm.nr * 2; output_channels *= 2) {
    DeconvolutionOperatorTester()
      .input_size(10, 9)
      .padding(1)
      .kernel_size(3, 3)
      .stride(2)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(output_channels)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, grouped_3x3s2_with_input_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .groups(2)
    .group_input_channels(17)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .input_pixel_stride(37)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, grouped_3x3s2_with_output_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .groups(2)
    .group_input_channels(17)
    .group_output_channels(xnn_params.f32.gemm.nr + 3)
    .output_pixel_stride(xnn_params.f32.gemm.nr * 2 + 13)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, grouped_3x3s2_with_qmin) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .groups(2)
    .group_input_channels(17)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, grouped_3x3s2_with_qmax) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .groups(2)
    .group_input_channels(17)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestF32();
}

/**************************** SUBCONV2D path, batched ****************************/

TEST(DECONVOLUTION_OP_F32, batched_3x3s2) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .group_input_channels(15)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, batched_Kx3s2) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t kernel_height = 2; kernel_height <= 5; kernel_height++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, 9)
      .padding_width(1)
      .kernel_size(kernel_height, 3)
      .stride(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(3)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_3xKs2) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t kernel_width = 2; kernel_width <= 5; kernel_width++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, 9)
      .padding_height(1)
      .kernel_size(3, kernel_width)
      .stride(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(3)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_3x3sSx1) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t stride_height = 2; stride_height <= 3; stride_height++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, 9)
      .padding(1)
      .padding_width(1)
      .kernel_size(3, 3)
      .stride_height(stride_height)
      .group_input_channels(17)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(3)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_3x3s1xS) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t stride_width = 2; stride_width <= 3; stride_width++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, 9)
      .padding(1)
      .padding_width(1)
      .kernel_size(3, 3)
      .stride_width(stride_width)
      .group_input_channels(17)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(3)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_3x3s2_varying_height_padding) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t padding_top = 0; padding_top <= 2; padding_top++) {
    for (size_t padding_bottom = 0; padding_bottom <= 2; padding_bottom++) {
      DeconvolutionOperatorTester()
        .batch_size(2)
        .input_size(10, 9)
        .padding_width(1)
        .padding_top(padding_top)
        .padding_bottom(padding_bottom)
        .kernel_size(3, 3)
        .stride(2)
        .group_input_channels(15)
        .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
        .iterations(1)
        .TestF32();
    }
  }
}

TEST(DECONVOLUTION_OP_F32, batched_3x3s2_varying_width_padding) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t padding_left = 0; padding_left <= 2; padding_left++) {
    for (size_t padding_right = 0; padding_right <= 2; padding_right++) {
      DeconvolutionOperatorTester()
        .batch_size(2)
        .input_size(10, 9)
        .padding_height(1)
        .padding_left(padding_left)
        .padding_right(padding_right)
        .kernel_size(3, 3)
        .stride(2)
        .group_input_channels(15)
        .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
        .iterations(1)
        .TestF32();
    }
  }
}

TEST(DECONVOLUTION_OP_F32, batched_3x3s2_varying_height_adjustment) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t adjustment_height = 1; adjustment_height <= 2; adjustment_height++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, 9)
      .padding(1)
      .adjustment_height(adjustment_height)
      .kernel_size(3, 3)
      .stride(2)
      .group_input_channels(15)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_3x3s2_varying_width_adjustment) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t adjustment_width = 1; adjustment_width <= 2; adjustment_width++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, 9)
      .padding(1)
      .adjustment_width(adjustment_width)
      .kernel_size(3, 3)
      .stride(2)
      .group_input_channels(15)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_3x3s2_varying_input_height) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_height = 8; input_height <= 12; input_height++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(input_height, 9)
      .padding(1)
      .kernel_size(3, 3)
      .stride(2)
      .group_input_channels(15)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_3x3s2_varying_input_width) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_width = 7; input_width <= 11; input_width++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, input_width)
      .padding(1)
      .kernel_size(3, 3)
      .stride(2)
      .group_input_channels(15)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_3x3s2_varying_input_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_channels = 1; input_channels <= 16; input_channels *= 4) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, 9)
      .padding(1)
      .kernel_size(3, 3)
      .stride(2)
      .group_input_channels(input_channels)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_3x3s2_varying_output_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t output_channels = 1; output_channels <= xnn_params.f32.gemm.nr * 2; output_channels *= 2) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, 9)
      .padding(1)
      .kernel_size(3, 3)
      .stride(2)
      .group_input_channels(23)
      .group_output_channels(output_channels)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_3x3s2_with_input_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .input_pixel_stride(28)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, batched_3x3s2_with_output_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .output_pixel_stride(xnn_params.f32.gemm.nr * 2 + 13)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, batched_3x3s2_with_qmin) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, batched_3x3s2_with_qmax) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .group_input_channels(23)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestF32();
}

/**************************** SUBCONV2D path, grouped, batched ****************************/

TEST(DECONVOLUTION_OP_F32, batched_grouped_3x3s2) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .groups(2)
    .group_input_channels(17)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_Kx3s2) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t kernel_height = 2; kernel_height <= 5; kernel_height++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, 9)
      .padding_width(1)
      .kernel_size(kernel_height, 3)
      .stride(2)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(3)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_3xKs2) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t kernel_width = 2; kernel_width <= 5; kernel_width++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, 9)
      .padding_height(1)
      .kernel_size(3, kernel_width)
      .stride(2)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(3)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_3x3sSx1) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t stride_height = 2; stride_height <= 3; stride_height++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, 9)
      .padding(1)
      .padding_width(1)
      .kernel_size(3, 3)
      .stride_height(stride_height)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(3)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_3x3s1xS) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t stride_width = 2; stride_width <= 3; stride_width++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, 9)
      .padding(1)
      .padding_width(1)
      .kernel_size(3, 3)
      .stride_width(stride_width)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(3)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_3x3s2_varying_height_padding) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t padding_top = 0; padding_top <= 2; padding_top++) {
    for (size_t padding_bottom = 0; padding_bottom <= 2; padding_bottom++) {
      DeconvolutionOperatorTester()
        .batch_size(2)
        .input_size(10, 9)
        .padding_width(1)
        .padding_top(padding_top)
        .padding_bottom(padding_bottom)
        .kernel_size(3, 3)
        .stride(2)
        .groups(2)
        .group_input_channels(17)
        .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
        .iterations(1)
        .TestF32();
    }
  }
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_3x3s2_varying_width_padding) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t padding_left = 0; padding_left <= 2; padding_left++) {
    for (size_t padding_right = 0; padding_right <= 2; padding_right++) {
      DeconvolutionOperatorTester()
        .batch_size(2)
        .input_size(10, 9)
        .padding_height(1)
        .padding_left(padding_left)
        .padding_right(padding_right)
        .kernel_size(3, 3)
        .stride(2)
        .groups(2)
        .group_input_channels(17)
        .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
        .iterations(1)
        .TestF32();
    }
  }
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_3x3s2_varying_height_adjustment) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t adjustment_height = 1; adjustment_height <= 2; adjustment_height++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, 9)
      .padding(1)
      .adjustment_height(adjustment_height)
      .kernel_size(3, 3)
      .stride(2)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_3x3s2_varying_width_adjustment) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t adjustment_width = 1; adjustment_width <= 2; adjustment_width++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, 9)
      .padding(1)
      .adjustment_width(adjustment_width)
      .kernel_size(3, 3)
      .stride(2)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_3x3s2_varying_input_height) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_height = 8; input_height <= 12; input_height++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(input_height, 9)
      .padding(1)
      .kernel_size(3, 3)
      .stride(2)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_3x3s2_varying_input_width) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_width = 7; input_width <= 11; input_width++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, input_width)
      .padding(1)
      .kernel_size(3, 3)
      .stride(2)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_3x3s2_varying_input_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t input_channels = 14; input_channels <= 20; input_channels++) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, 9)
      .padding(1)
      .kernel_size(3, 3)
      .stride(2)
      .groups(2)
      .group_input_channels(input_channels)
      .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_3x3s2_varying_output_channels) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  for (size_t output_channels = 1; output_channels <= xnn_params.f32.gemm.nr * 2; output_channels *= 2) {
    DeconvolutionOperatorTester()
      .batch_size(2)
      .input_size(10, 9)
      .padding(1)
      .kernel_size(3, 3)
      .stride(2)
      .groups(2)
      .group_input_channels(17)
      .group_output_channels(output_channels)
      .iterations(1)
      .TestF32();
  }
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_3x3s2_with_input_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .groups(2)
    .group_input_channels(17)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .input_pixel_stride(37)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_3x3s2_with_output_stride) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .groups(2)
    .group_input_channels(17)
    .group_output_channels(xnn_params.f32.gemm.nr + 3)
    .output_pixel_stride(xnn_params.f32.gemm.nr * 2 + 13)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_3x3s2_with_qmin) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .groups(2)
    .group_input_channels(17)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestF32();
}

TEST(DECONVOLUTION_OP_F32, batched_grouped_3x3s2_with_qmax) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_size(10, 9)
    .padding(1)
    .kernel_size(3, 3)
    .stride(2)
    .groups(2)
    .group_input_channels(17)
    .group_output_channels(xnn_params.f32.gemm.nr * 2 + 3)
    .qmin(128)
    .iterations(3)
    .TestF32();
}

/**************************** SUBCONV2D path, setup ****************************/

TEST(DECONVOLUTION_OP_F32, 3x3s2_setup_changing_batch) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .next_batch_size(5)
    .input_height(8)
    .input_width(9)
    .kernel_height(3)
    .kernel_width(5)
    .stride(2)
    .groups(2)
    .group_input_channels(15)
    .group_output_channels(17)
    .TestSetupF32();
}

TEST(DECONVOLUTION_OP_F32, 3x3s2_setup_changing_height) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_height(8)
    .input_width(9)
    .next_input_height(10)
    .kernel_height(3)
    .kernel_width(5)
    .stride(2)
    .groups(2)
    .group_input_channels(15)
    .group_output_channels(17)
    .TestSetupF32();
}

TEST(DECONVOLUTION_OP_F32, 3x3s2_setup_changing_width) {
  ASSERT_EQ(xnn_status_success, xnn_initialize());
  DeconvolutionOperatorTester()
    .batch_size(2)
    .input_height(8)
    .input_width(9)
    .next_input_width(10)
    .kernel_height(3)
    .kernel_width(5)
    .stride(2)
    .groups(2)
    .group_input_channels(15)
    .group_output_channels(17)
    .TestSetupF32();
}

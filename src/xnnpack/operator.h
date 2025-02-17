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

#include <pthreadpool.h>

#include <xnnpack/requantization.h>
#include <xnnpack/compute.h>


enum xnn_ukernel_type {
  xnn_ukernel_type_none = 0,
  xnn_ukernel_type_add,
  xnn_ukernel_type_argmax_pooling,
  xnn_ukernel_type_average_pooling,
  xnn_ukernel_type_channel_shuffle,
  xnn_ukernel_type_clamp,
  xnn_ukernel_type_igemm,
  xnn_ukernel_type_dconv2d_hwc2spchw,
  xnn_ukernel_type_dwconv,
  xnn_ukernel_type_gemm,
  xnn_ukernel_type_global_average_pooling,
  xnn_ukernel_type_hswish,
  xnn_ukernel_type_lut,
  xnn_ukernel_type_max_pooling,
  xnn_ukernel_type_pad,
  xnn_ukernel_type_pixelwise_average_pooling,
  xnn_ukernel_type_prelu,
  xnn_ukernel_type_softargmax,
  xnn_ukernel_type_spmm,
  xnn_ukernel_type_subconv2d,
  xnn_ukernel_type_unpooling,
  xnn_ukernel_type_vmulcaddc,
};

enum xnn_operator_type {
  xnn_operator_type_none = 0,
  xnn_operator_type_add_f32,
  xnn_operator_type_add_q8,
  xnn_operator_type_argmax_pooling_f32,
  xnn_operator_type_average_pooling_f32,
  xnn_operator_type_average_pooling_q8,
  xnn_operator_type_channel_pad_x32,
  xnn_operator_type_channel_shuffle_x8,
  xnn_operator_type_channel_shuffle_x32,
  xnn_operator_type_clamp_f32,
  xnn_operator_type_clamp_u8,
  xnn_operator_type_convolution_f32,
  xnn_operator_type_convolution_spnchw_f32,
  xnn_operator_type_convolution_q8,
  xnn_operator_type_deconvolution_f32,
  xnn_operator_type_deconvolution_q8,
  xnn_operator_type_fully_connected_f32,
  xnn_operator_type_fully_connected_q8,
  xnn_operator_type_global_average_pooling_f32,
  xnn_operator_type_global_average_pooling_q8,
  xnn_operator_type_global_average_pooling_spnchw_f32,
  xnn_operator_type_hswish_f32,
  xnn_operator_type_leaky_relu_q8,
  xnn_operator_type_max_pooling_f32,
  xnn_operator_type_max_pooling_u8,
  xnn_operator_type_prelu_f32,
  xnn_operator_type_sigmoid_q8,
  xnn_operator_type_softargmax_q8,
  xnn_operator_type_unpooling_x32,
};

struct xnn_ukernel_dconv2d {
  union {
    xnn_conv_hwc2spchw_ukernel_function hwc2spchw_function;
    xnn_conv_hwc_ukernel_function hwc_function;
  };
  uint8_t output_height_tile;
  uint8_t output_channel_tile;
};

struct xnn_ukernel_dwconv {
  union {
    xnn_dwconv_up_ukernel_function unipass_function;
    xnn_dwconv_mp_ukernel_function multipass_function;
  };
  uint8_t mr;
  uint8_t qr;
};

// Direct 2D Depthwise Convolution
struct xnn_ukernel_dwconv2d {
  union {
    xnn_dwconv_spchw_ukernel_function spchw_function;
  };
  uint8_t input_width_tile;
  uint8_t output_width_tile;
};

struct xnn_ukernel_gemm {
  xnn_gemm_ukernel_function default_function;
  xnn_gemm_ukernel_function mr1_function;
  uint8_t mr;
  uint8_t nr;
  uint8_t kr;
};

struct xnn_ukernel_igemm {
  xnn_igemm_ukernel_function default_function;
  xnn_igemm_ukernel_function mr1_function;
  uint8_t mr;
  uint8_t nr;
  uint8_t kr;
};

struct xnn_ukernel_spmm {
  xnn_spmm_ukernel_function function;
  uint8_t mr;
};

struct xnn_ukernel_vmulcaddc {
  xnn_vmulcaddc_ukernel_function function;
  uint8_t mr;
};

struct xnn_ukernel {
  enum xnn_ukernel_type type;
  union {
    struct xnn_ukernel_dconv2d dconv2d;
    struct xnn_ukernel_dwconv dwconv;
    struct xnn_ukernel_dwconv2d dwconv2d;
    struct xnn_ukernel_gemm gemm;
    struct xnn_ukernel_igemm igemm;
    struct xnn_ukernel_spmm spmm;
    struct xnn_ukernel_vmulcaddc vmulcaddc;
  };
};

enum xnn_run_state {
  xnn_run_state_invalid = 0,
  xnn_run_state_ready,
  xnn_run_state_skip,
};

struct subconvolution_params {
  void* weights;
  size_t w_stride;
  const void** indirection_buffer;
  void* output;
  size_t slice_width;
  size_t slice_height;
  size_t indirection_y_stride;
  size_t indirection_x_stride;
  // scaled_kernel_size := kernel_size * mr * sizeof(void*).
  size_t scaled_kernel_size;
};

struct xnn_operator {
  size_t batch_size;
  uint32_t padding_top;
  uint32_t padding_right;
  uint32_t padding_bottom;
  uint32_t padding_left;
  uint32_t adjustment_height;
  uint32_t adjustment_width;
  uint32_t kernel_height;
  uint32_t kernel_width;
  uint32_t stride_height;
  uint32_t stride_width;
  uint32_t dilation_height;
  uint32_t dilation_width;
  uint32_t groups;
  size_t group_channels;
  size_t group_input_channels;
  size_t group_output_channels;
  size_t channels;

  size_t pad_before_channels;
  size_t pad_after_channels;
  uint32_t pad_value;

  size_t input_height;
  size_t input_width;
  size_t input_pixel_stride;
  const void* input;
  const void** indirection_buffer;
  void* a_sum;

  size_t input2_pixel_stride;
  const void* input2;

  size_t output_height;
  size_t output_width;
  size_t output_pixel_stride;
  void* output;

  void* packed_weights;
  // Total number of non-zero kernel elements when weights use sparse representation.
  size_t num_nonzero_values;
  // Total number of non-zero kernel blocks when weights use sparse representation.
  size_t num_nonzero_blocks;
  // Total number of output channel blocks when weights use sparse representation.
  size_t num_output_channel_blocks;
  // Input channel corresponding to the first non-zero kernel element.
  size_t first_input_channel;

  float input_scale;
  float output_scale;
  uint8_t input_zero_point;
  uint8_t kernel_zero_point;
  uint8_t output_zero_point;
  uint8_t output_min;
  uint8_t output_max;

  size_t valid_batch_size;
  size_t last_input_height;
  size_t last_input_width;
  const void* last_input;
  void* last_output;

  void* zero_buffer;
  void* lookup_table;
  void* pixelwise_buffer;
  struct subconvolution_params* subconvolution_buffer;

  union {
    union xnn_f32_avgpool_params f32_avgpool_params;
    union xnn_f32_gavgpool_params f32_gavgpool_params;
    union xnn_f32_hswish_params f32_hswish_params;
    union xnn_f32_output_params f32_output_params;
    union xnn_f32_spchw_params f32_spchw_params;
    union xnn_q8_add_params q8_add_params;
    union xnn_q8_avgpool_params q8_avgpool_params;
    union xnn_q8_gemm_params q8_gemm_params;
    union xnn_u8_output_params u8_output_params;
  };
  enum xnn_operator_type type;
  struct xnn_ukernel ukernel;

  struct compute_parameters compute;
  struct compute_parameters compute2;
  union {
    struct add_contiguous_context add_contiguous;
    struct add_strided_context add_strided;
    struct argmax_pooling_context argmax_pooling;
    struct average_pooling_context average_pooling;
    struct channel_pad_context channel_pad;
    struct channel_shuffle_context channel_shuffle;
    struct dconv2d_context dconv2d;
    struct dwconv2d_context dwconv2d;
    struct dwconv_context dwconv;
    struct gemm_context gemm;
    struct global_average_pooling_context global_average_pooling;
    struct global_average_pooling_spnchw_context global_average_pooling_spnchw;
    struct igemm_context igemm;
    struct lut_contiguous_context lut_contiguous;
    struct lut_strided_context lut_strided;
    struct max_pooling_context max_pooling;
    struct pixelwise_average_pooling_context pixelwise_average_pooling;
    struct prelu_context prelu;
    struct spmm_context spmm;
    struct subconv_context subconv;
    struct u8_softargmax_context u8_softargmax;
    struct univector_contiguous_context univector_contiguous;
    struct univector_strided_context univector_strided;
    struct unpooling_context unpooling;
    struct vmulcaddc_context vmulcaddc;
  } context;

  enum xnn_run_state state;
};

// Copyright (c) Facebook, Inc. and its affiliates.
// All rights reserved.
//
// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <stdlib.h>

#include <xnnpack.h>
#include <xnnpack/allocator.h>
#include <xnnpack/log.h>
#include <xnnpack/operator.h>
#include <xnnpack/params.h>


enum xnn_status xnn_delete_operator(xnn_operator_t op)
{
  if (!xnn_params.initialized) {
    xnn_log_error("failed to delete operator: XNNPACK is not initialized");
    return xnn_status_uninitialized;
  }

  if (op == NULL) {
    return xnn_status_invalid_parameter;
  }

  free(op->indirection_buffer);
  xnn_release_memory(op->packed_weights);
  free(op->a_sum);
  xnn_release_memory(op->zero_buffer);
  free(op->pixelwise_buffer);
  free(op->subconvolution_buffer);
  xnn_release_memory(op->lookup_table);
  xnn_release_memory(op);
  return xnn_status_success;
}

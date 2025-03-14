// Copyright (c) Facebook, Inc. and its affiliates.
// All rights reserved.
//
// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.
//
// Auto-generated file. Do not edit!
//   Specification: test/f32-gemm.yaml
//   Generator: tools/generate-gemm-test.py


#include <gtest/gtest.h>

#include <xnnpack/common.h>
#include <xnnpack/isa-checks.h>

#include <xnnpack/gemm.h>
#include <xnnpack/igemm.h>
#include <xnnpack/ppmm.h>
#include "gemm-microkernel-tester.h"


#if XNN_ARCH_ARM64
  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A57, k_eq_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(8)
      .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a57);
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A57, strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(8)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a57);
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A57, k_eq_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(8)
      .a_stride(11)
      .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a57);
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A57, k_eq_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 1; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(8)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a57);
      }
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A57, k_eq_8_subtile_m) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 1; m++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(m)
        .n(8)
        .k(8)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a57);
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A57, k_eq_8_subtile_n) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(n)
        .k(8)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a57);
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A57, k_eq_16) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(16)
      .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a57);
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A57, k_eq_16_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(16)
      .a_stride(19)
      .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a57);
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A57, k_eq_16_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 1; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(16)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a57);
      }
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A57, k_lt_16) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 16; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a57);
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A57, k_lt_16_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 16; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .a_stride(19)
        .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a57);
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A57, k_lt_16_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 16; k++) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a57);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A57, k_gt_16) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 17; k < 16; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a57);
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A57, k_gt_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 17; k < 16; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .a_stride(19)
        .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a57);
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A57, k_gt_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 17; k < 16; k++) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a57);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A57, k_div_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 24; k <= 80; k += 8) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a57);
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A57, k_div_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 24; k <= 80; k += 8) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .a_stride(83)
        .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a57);
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A57, k_div_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 24; k <= 80; k += 8) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a57);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A57, n_gt_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a57);
      }
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A57, n_gt_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a57);
      }
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A57, n_gt_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(n)
          .k(k)
          .a_stride(43)
          .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a57);
      }
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A57, n_gt_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 40; k += 9) {
        for (uint32_t m = 1; m <= 1; m++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a57);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A57, n_div_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a57);
      }
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A57, n_div_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a57);
      }
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A57, n_div_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(n)
          .k(k)
          .a_stride(43)
          .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a57);
      }
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A57, n_div_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 40; k += 9) {
        for (uint32_t m = 1; m <= 1; m++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a57);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A57, strided_cm_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k <= 40; k += 9) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a57);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A57, qmin) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(8)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a57);
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A57, qmax) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(8)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a57);
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A57, strided_cm) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(8)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a57);
  }
#endif  // XNN_ARCH_ARM64


#if XNN_ARCH_ARM64
  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A75, k_eq_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(8)
      .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a75);
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A75, strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(8)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a75);
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A75, k_eq_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(8)
      .a_stride(11)
      .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a75);
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A75, k_eq_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 1; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(8)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a75);
      }
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A75, k_eq_8_subtile_m) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 1; m++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(m)
        .n(8)
        .k(8)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a75);
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A75, k_eq_8_subtile_n) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(n)
        .k(8)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a75);
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A75, k_eq_16) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(16)
      .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a75);
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A75, k_eq_16_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(16)
      .a_stride(19)
      .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a75);
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A75, k_eq_16_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 1; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(16)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a75);
      }
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A75, k_lt_16) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 16; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a75);
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A75, k_lt_16_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 16; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .a_stride(19)
        .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a75);
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A75, k_lt_16_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 16; k++) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a75);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A75, k_gt_16) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 17; k < 16; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a75);
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A75, k_gt_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 17; k < 16; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .a_stride(19)
        .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a75);
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A75, k_gt_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 17; k < 16; k++) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a75);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A75, k_div_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 24; k <= 80; k += 8) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a75);
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A75, k_div_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 24; k <= 80; k += 8) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .a_stride(83)
        .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a75);
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A75, k_div_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 24; k <= 80; k += 8) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a75);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A75, n_gt_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a75);
      }
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A75, n_gt_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a75);
      }
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A75, n_gt_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(n)
          .k(k)
          .a_stride(43)
          .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a75);
      }
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A75, n_gt_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 40; k += 9) {
        for (uint32_t m = 1; m <= 1; m++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a75);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A75, n_div_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a75);
      }
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A75, n_div_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a75);
      }
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A75, n_div_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(n)
          .k(k)
          .a_stride(43)
          .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a75);
      }
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A75, n_div_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 40; k += 9) {
        for (uint32_t m = 1; m <= 1; m++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a75);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A75, strided_cm_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k <= 40; k += 9) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a75);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A75, qmin) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(8)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a75);
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A75, qmax) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(8)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a75);
  }

  TEST(F32_GEMM_1X8__AARCH64_NEONFMA_CORTEX_A75, strided_cm) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(8)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_1x8__aarch64_neonfma_cortex_a75);
  }
#endif  // XNN_ARCH_ARM64


#if XNN_ARCH_ARM64
  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A57, k_eq_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(8)
      .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a57);
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A57, strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(8)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a57);
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A57, k_eq_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(8)
      .a_stride(11)
      .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a57);
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A57, k_eq_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 4; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(8)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a57);
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A57, k_eq_8_subtile_m) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 4; m++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(m)
        .n(8)
        .k(8)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a57);
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A57, k_eq_8_subtile_n) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(n)
        .k(8)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a57);
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A57, k_eq_16) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(16)
      .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a57);
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A57, k_eq_16_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(16)
      .a_stride(19)
      .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a57);
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A57, k_eq_16_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 4; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(16)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a57);
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A57, k_lt_16) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 16; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a57);
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A57, k_lt_16_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 16; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(19)
        .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a57);
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A57, k_lt_16_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 16; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a57);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A57, k_gt_16) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 17; k < 16; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a57);
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A57, k_gt_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 17; k < 16; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(19)
        .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a57);
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A57, k_gt_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 17; k < 16; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a57);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A57, k_div_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 24; k <= 80; k += 8) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a57);
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A57, k_div_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 24; k <= 80; k += 8) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(83)
        .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a57);
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A57, k_div_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 24; k <= 80; k += 8) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a57);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A57, n_gt_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a57);
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A57, n_gt_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a57);
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A57, n_gt_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(43)
          .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a57);
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A57, n_gt_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 40; k += 9) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a57);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A57, n_div_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a57);
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A57, n_div_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a57);
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A57, n_div_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(43)
          .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a57);
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A57, n_div_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 40; k += 9) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a57);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A57, strided_cm_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k <= 40; k += 9) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a57);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A57, qmin) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(8)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a57);
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A57, qmax) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(8)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a57);
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A57, strided_cm) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(8)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a57);
  }
#endif  // XNN_ARCH_ARM64


#if XNN_ARCH_ARM64
  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A75, k_eq_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(8)
      .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a75);
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A75, strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(8)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a75);
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A75, k_eq_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(8)
      .a_stride(11)
      .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a75);
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A75, k_eq_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 4; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(8)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a75);
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A75, k_eq_8_subtile_m) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 4; m++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(m)
        .n(8)
        .k(8)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a75);
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A75, k_eq_8_subtile_n) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(n)
        .k(8)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a75);
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A75, k_eq_16) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(16)
      .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a75);
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A75, k_eq_16_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(16)
      .a_stride(19)
      .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a75);
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A75, k_eq_16_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 4; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(16)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a75);
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A75, k_lt_16) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 16; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a75);
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A75, k_lt_16_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 16; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(19)
        .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a75);
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A75, k_lt_16_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 16; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a75);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A75, k_gt_16) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 17; k < 16; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a75);
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A75, k_gt_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 17; k < 16; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(19)
        .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a75);
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A75, k_gt_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 17; k < 16; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a75);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A75, k_div_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 24; k <= 80; k += 8) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a75);
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A75, k_div_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 24; k <= 80; k += 8) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(83)
        .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a75);
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A75, k_div_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 24; k <= 80; k += 8) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a75);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A75, n_gt_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a75);
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A75, n_gt_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a75);
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A75, n_gt_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(43)
          .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a75);
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A75, n_gt_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 40; k += 9) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a75);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A75, n_div_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a75);
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A75, n_div_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a75);
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A75, n_div_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(43)
          .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a75);
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A75, n_div_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 40; k += 9) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a75);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A75, strided_cm_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k <= 40; k += 9) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a75);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A75, qmin) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(8)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a75);
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A75, qmax) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(8)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a75);
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_CORTEX_A75, strided_cm) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(8)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_cortex_a75);
  }
#endif  // XNN_ARCH_ARM64


#if XNN_ARCH_ARM64
  TEST(F32_GEMM_5X8__AARCH64_NEONFMA_CORTEX_A75, k_eq_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(5)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(5)
      .n(8)
      .k(8)
      .Test(xnn_f32_gemm_ukernel_5x8__aarch64_neonfma_cortex_a75);
  }

  TEST(F32_GEMM_5X8__AARCH64_NEONFMA_CORTEX_A75, strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(5)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(5)
      .n(8)
      .k(8)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_5x8__aarch64_neonfma_cortex_a75);
  }

  TEST(F32_GEMM_5X8__AARCH64_NEONFMA_CORTEX_A75, k_eq_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(5)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(5)
      .n(8)
      .k(8)
      .a_stride(11)
      .Test(xnn_f32_gemm_ukernel_5x8__aarch64_neonfma_cortex_a75);
  }

  TEST(F32_GEMM_5X8__AARCH64_NEONFMA_CORTEX_A75, k_eq_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 5; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(5)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(8)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_5x8__aarch64_neonfma_cortex_a75);
      }
    }
  }

  TEST(F32_GEMM_5X8__AARCH64_NEONFMA_CORTEX_A75, k_eq_8_subtile_m) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 5; m++) {
      GemmMicrokernelTester()
        .mr(5)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(m)
        .n(8)
        .k(8)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_5x8__aarch64_neonfma_cortex_a75);
    }
  }

  TEST(F32_GEMM_5X8__AARCH64_NEONFMA_CORTEX_A75, k_eq_8_subtile_n) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(5)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(5)
        .n(n)
        .k(8)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_5x8__aarch64_neonfma_cortex_a75);
    }
  }

  TEST(F32_GEMM_5X8__AARCH64_NEONFMA_CORTEX_A75, k_eq_16) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(5)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(5)
      .n(8)
      .k(16)
      .Test(xnn_f32_gemm_ukernel_5x8__aarch64_neonfma_cortex_a75);
  }

  TEST(F32_GEMM_5X8__AARCH64_NEONFMA_CORTEX_A75, k_eq_16_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(5)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(5)
      .n(8)
      .k(16)
      .a_stride(19)
      .Test(xnn_f32_gemm_ukernel_5x8__aarch64_neonfma_cortex_a75);
  }

  TEST(F32_GEMM_5X8__AARCH64_NEONFMA_CORTEX_A75, k_eq_16_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 5; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(5)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(16)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_5x8__aarch64_neonfma_cortex_a75);
      }
    }
  }

  TEST(F32_GEMM_5X8__AARCH64_NEONFMA_CORTEX_A75, k_lt_16) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 16; k++) {
      GemmMicrokernelTester()
        .mr(5)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(5)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_5x8__aarch64_neonfma_cortex_a75);
    }
  }

  TEST(F32_GEMM_5X8__AARCH64_NEONFMA_CORTEX_A75, k_lt_16_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 16; k++) {
      GemmMicrokernelTester()
        .mr(5)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(5)
        .n(8)
        .k(k)
        .a_stride(19)
        .Test(xnn_f32_gemm_ukernel_5x8__aarch64_neonfma_cortex_a75);
    }
  }

  TEST(F32_GEMM_5X8__AARCH64_NEONFMA_CORTEX_A75, k_lt_16_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 16; k++) {
      for (uint32_t m = 1; m <= 5; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(5)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_5x8__aarch64_neonfma_cortex_a75);
        }
      }
    }
  }

  TEST(F32_GEMM_5X8__AARCH64_NEONFMA_CORTEX_A75, k_gt_16) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 17; k < 16; k++) {
      GemmMicrokernelTester()
        .mr(5)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(5)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_5x8__aarch64_neonfma_cortex_a75);
    }
  }

  TEST(F32_GEMM_5X8__AARCH64_NEONFMA_CORTEX_A75, k_gt_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 17; k < 16; k++) {
      GemmMicrokernelTester()
        .mr(5)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(5)
        .n(8)
        .k(k)
        .a_stride(19)
        .Test(xnn_f32_gemm_ukernel_5x8__aarch64_neonfma_cortex_a75);
    }
  }

  TEST(F32_GEMM_5X8__AARCH64_NEONFMA_CORTEX_A75, k_gt_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 17; k < 16; k++) {
      for (uint32_t m = 1; m <= 5; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(5)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_5x8__aarch64_neonfma_cortex_a75);
        }
      }
    }
  }

  TEST(F32_GEMM_5X8__AARCH64_NEONFMA_CORTEX_A75, k_div_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 24; k <= 80; k += 8) {
      GemmMicrokernelTester()
        .mr(5)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(5)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_5x8__aarch64_neonfma_cortex_a75);
    }
  }

  TEST(F32_GEMM_5X8__AARCH64_NEONFMA_CORTEX_A75, k_div_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 24; k <= 80; k += 8) {
      GemmMicrokernelTester()
        .mr(5)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(5)
        .n(8)
        .k(k)
        .a_stride(83)
        .Test(xnn_f32_gemm_ukernel_5x8__aarch64_neonfma_cortex_a75);
    }
  }

  TEST(F32_GEMM_5X8__AARCH64_NEONFMA_CORTEX_A75, k_div_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 24; k <= 80; k += 8) {
      for (uint32_t m = 1; m <= 5; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(5)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_5x8__aarch64_neonfma_cortex_a75);
        }
      }
    }
  }

  TEST(F32_GEMM_5X8__AARCH64_NEONFMA_CORTEX_A75, n_gt_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(5)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(5)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_5x8__aarch64_neonfma_cortex_a75);
      }
    }
  }

  TEST(F32_GEMM_5X8__AARCH64_NEONFMA_CORTEX_A75, n_gt_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(5)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(5)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_5x8__aarch64_neonfma_cortex_a75);
      }
    }
  }

  TEST(F32_GEMM_5X8__AARCH64_NEONFMA_CORTEX_A75, n_gt_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(5)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(5)
          .n(n)
          .k(k)
          .a_stride(43)
          .Test(xnn_f32_gemm_ukernel_5x8__aarch64_neonfma_cortex_a75);
      }
    }
  }

  TEST(F32_GEMM_5X8__AARCH64_NEONFMA_CORTEX_A75, n_gt_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 40; k += 9) {
        for (uint32_t m = 1; m <= 5; m++) {
          GemmMicrokernelTester()
            .mr(5)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_5x8__aarch64_neonfma_cortex_a75);
        }
      }
    }
  }

  TEST(F32_GEMM_5X8__AARCH64_NEONFMA_CORTEX_A75, n_div_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(5)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(5)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_5x8__aarch64_neonfma_cortex_a75);
      }
    }
  }

  TEST(F32_GEMM_5X8__AARCH64_NEONFMA_CORTEX_A75, n_div_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(5)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(5)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_5x8__aarch64_neonfma_cortex_a75);
      }
    }
  }

  TEST(F32_GEMM_5X8__AARCH64_NEONFMA_CORTEX_A75, n_div_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(5)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(5)
          .n(n)
          .k(k)
          .a_stride(43)
          .Test(xnn_f32_gemm_ukernel_5x8__aarch64_neonfma_cortex_a75);
      }
    }
  }

  TEST(F32_GEMM_5X8__AARCH64_NEONFMA_CORTEX_A75, n_div_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 40; k += 9) {
        for (uint32_t m = 1; m <= 5; m++) {
          GemmMicrokernelTester()
            .mr(5)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_5x8__aarch64_neonfma_cortex_a75);
        }
      }
    }
  }

  TEST(F32_GEMM_5X8__AARCH64_NEONFMA_CORTEX_A75, strided_cm_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k <= 40; k += 9) {
      for (uint32_t m = 1; m <= 5; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(5)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_5x8__aarch64_neonfma_cortex_a75);
        }
      }
    }
  }

  TEST(F32_GEMM_5X8__AARCH64_NEONFMA_CORTEX_A75, qmin) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(5)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(5)
      .n(8)
      .k(8)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_5x8__aarch64_neonfma_cortex_a75);
  }

  TEST(F32_GEMM_5X8__AARCH64_NEONFMA_CORTEX_A75, qmax) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(5)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(5)
      .n(8)
      .k(8)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_5x8__aarch64_neonfma_cortex_a75);
  }

  TEST(F32_GEMM_5X8__AARCH64_NEONFMA_CORTEX_A75, strided_cm) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(5)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(5)
      .n(8)
      .k(8)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_5x8__aarch64_neonfma_cortex_a75);
  }
#endif  // XNN_ARCH_ARM64


#if XNN_ARCH_ARM64
  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A57, k_eq_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(8)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a57);
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A57, strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(8)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a57);
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A57, k_eq_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(8)
      .a_stride(11)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a57);
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A57, k_eq_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 6; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(8)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a57);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A57, k_eq_8_subtile_m) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 6; m++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(m)
        .n(8)
        .k(8)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a57);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A57, k_eq_8_subtile_n) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(n)
        .k(8)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a57);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A57, k_eq_16) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(16)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a57);
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A57, k_eq_16_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(16)
      .a_stride(19)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a57);
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A57, k_eq_16_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 6; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(16)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a57);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A57, k_lt_16) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 16; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a57);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A57, k_lt_16_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 16; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .a_stride(19)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a57);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A57, k_lt_16_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 16; k++) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a57);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A57, k_gt_16) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 17; k < 16; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a57);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A57, k_gt_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 17; k < 16; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .a_stride(19)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a57);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A57, k_gt_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 17; k < 16; k++) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a57);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A57, k_div_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 24; k <= 80; k += 8) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a57);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A57, k_div_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 24; k <= 80; k += 8) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .a_stride(83)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a57);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A57, k_div_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 24; k <= 80; k += 8) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a57);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A57, n_gt_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a57);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A57, n_gt_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a57);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A57, n_gt_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(n)
          .k(k)
          .a_stride(43)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a57);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A57, n_gt_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 40; k += 9) {
        for (uint32_t m = 1; m <= 6; m++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a57);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A57, n_div_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a57);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A57, n_div_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a57);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A57, n_div_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(n)
          .k(k)
          .a_stride(43)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a57);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A57, n_div_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 40; k += 9) {
        for (uint32_t m = 1; m <= 6; m++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a57);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A57, strided_cm_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k <= 40; k += 9) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a57);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A57, qmin) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(8)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a57);
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A57, qmax) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(8)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a57);
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A57, strided_cm) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(8)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a57);
  }
#endif  // XNN_ARCH_ARM64


#if XNN_ARCH_ARM64
  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A73, k_eq_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(8)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a73);
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A73, strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(8)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a73);
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A73, k_eq_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(8)
      .a_stride(11)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a73);
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A73, k_eq_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 6; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(8)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a73);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A73, k_eq_8_subtile_m) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 6; m++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(m)
        .n(8)
        .k(8)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a73);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A73, k_eq_8_subtile_n) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(n)
        .k(8)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a73);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A73, k_eq_16) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(16)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a73);
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A73, k_eq_16_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(16)
      .a_stride(19)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a73);
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A73, k_eq_16_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 6; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(16)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a73);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A73, k_lt_16) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 16; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a73);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A73, k_lt_16_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 16; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .a_stride(19)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a73);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A73, k_lt_16_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 16; k++) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a73);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A73, k_gt_16) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 17; k < 16; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a73);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A73, k_gt_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 17; k < 16; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .a_stride(19)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a73);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A73, k_gt_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 17; k < 16; k++) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a73);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A73, k_div_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 24; k <= 80; k += 8) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a73);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A73, k_div_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 24; k <= 80; k += 8) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .a_stride(83)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a73);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A73, k_div_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 24; k <= 80; k += 8) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a73);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A73, n_gt_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a73);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A73, n_gt_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a73);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A73, n_gt_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(n)
          .k(k)
          .a_stride(43)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a73);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A73, n_gt_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 40; k += 9) {
        for (uint32_t m = 1; m <= 6; m++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a73);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A73, n_div_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a73);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A73, n_div_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a73);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A73, n_div_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(n)
          .k(k)
          .a_stride(43)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a73);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A73, n_div_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 40; k += 9) {
        for (uint32_t m = 1; m <= 6; m++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a73);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A73, strided_cm_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k <= 40; k += 9) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a73);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A73, qmin) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(8)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a73);
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A73, qmax) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(8)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a73);
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A73, strided_cm) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(8)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a73);
  }
#endif  // XNN_ARCH_ARM64


#if XNN_ARCH_ARM64
  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A75, k_eq_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(8)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a75);
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A75, strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(8)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a75);
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A75, k_eq_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(8)
      .a_stride(11)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a75);
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A75, k_eq_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 6; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(8)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a75);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A75, k_eq_8_subtile_m) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 6; m++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(m)
        .n(8)
        .k(8)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a75);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A75, k_eq_8_subtile_n) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(n)
        .k(8)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a75);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A75, k_eq_16) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(16)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a75);
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A75, k_eq_16_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(16)
      .a_stride(19)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a75);
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A75, k_eq_16_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 6; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(16)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a75);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A75, k_lt_16) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 16; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a75);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A75, k_lt_16_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 16; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .a_stride(19)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a75);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A75, k_lt_16_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 16; k++) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a75);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A75, k_gt_16) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 17; k < 16; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a75);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A75, k_gt_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 17; k < 16; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .a_stride(19)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a75);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A75, k_gt_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 17; k < 16; k++) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a75);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A75, k_div_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 24; k <= 80; k += 8) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a75);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A75, k_div_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 24; k <= 80; k += 8) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .a_stride(83)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a75);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A75, k_div_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 24; k <= 80; k += 8) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a75);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A75, n_gt_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a75);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A75, n_gt_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a75);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A75, n_gt_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(n)
          .k(k)
          .a_stride(43)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a75);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A75, n_gt_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 40; k += 9) {
        for (uint32_t m = 1; m <= 6; m++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a75);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A75, n_div_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a75);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A75, n_div_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a75);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A75, n_div_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 40; k += 9) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(n)
          .k(k)
          .a_stride(43)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a75);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A75, n_div_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 40; k += 9) {
        for (uint32_t m = 1; m <= 6; m++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a75);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A75, strided_cm_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k <= 40; k += 9) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a75);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A75, qmin) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(8)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a75);
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A75, qmax) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(8)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a75);
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_CORTEX_A75, strided_cm) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(8)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_cortex_a75);
  }
#endif  // XNN_ARCH_ARM64


#if XNN_ARCH_ARM64
  TEST(F32_GEMM_1X12__AARCH64_NEONFMA_CORTEX_A53, k_eq_4) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(1)
      .nr(12)
      .kr(1)
      .sr(1)
      .m(1)
      .n(12)
      .k(4)
      .Test(xnn_f32_gemm_ukernel_1x12__aarch64_neonfma_cortex_a53);
  }

  TEST(F32_GEMM_1X12__AARCH64_NEONFMA_CORTEX_A53, strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(1)
      .nr(12)
      .kr(1)
      .sr(1)
      .m(1)
      .n(12)
      .k(4)
      .cn_stride(17)
      .Test(xnn_f32_gemm_ukernel_1x12__aarch64_neonfma_cortex_a53);
  }

  TEST(F32_GEMM_1X12__AARCH64_NEONFMA_CORTEX_A53, k_eq_4_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(1)
      .nr(12)
      .kr(1)
      .sr(1)
      .m(1)
      .n(12)
      .k(4)
      .a_stride(7)
      .Test(xnn_f32_gemm_ukernel_1x12__aarch64_neonfma_cortex_a53);
  }

  TEST(F32_GEMM_1X12__AARCH64_NEONFMA_CORTEX_A53, k_eq_4_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 1; m++) {
      for (uint32_t n = 1; n <= 12; n++) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(12)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(4)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_1x12__aarch64_neonfma_cortex_a53);
      }
    }
  }

  TEST(F32_GEMM_1X12__AARCH64_NEONFMA_CORTEX_A53, k_eq_4_subtile_m) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 1; m++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(12)
        .kr(1)
        .sr(1)
        .m(m)
        .n(12)
        .k(4)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_1x12__aarch64_neonfma_cortex_a53);
    }
  }

  TEST(F32_GEMM_1X12__AARCH64_NEONFMA_CORTEX_A53, k_eq_4_subtile_n) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 1; n <= 12; n++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(12)
        .kr(1)
        .sr(1)
        .m(1)
        .n(n)
        .k(4)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_1x12__aarch64_neonfma_cortex_a53);
    }
  }

  TEST(F32_GEMM_1X12__AARCH64_NEONFMA_CORTEX_A53, k_eq_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(1)
      .nr(12)
      .kr(1)
      .sr(1)
      .m(1)
      .n(12)
      .k(8)
      .Test(xnn_f32_gemm_ukernel_1x12__aarch64_neonfma_cortex_a53);
  }

  TEST(F32_GEMM_1X12__AARCH64_NEONFMA_CORTEX_A53, k_eq_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(1)
      .nr(12)
      .kr(1)
      .sr(1)
      .m(1)
      .n(12)
      .k(8)
      .a_stride(11)
      .Test(xnn_f32_gemm_ukernel_1x12__aarch64_neonfma_cortex_a53);
  }

  TEST(F32_GEMM_1X12__AARCH64_NEONFMA_CORTEX_A53, k_eq_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 1; m++) {
      for (uint32_t n = 1; n <= 12; n++) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(12)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(8)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_1x12__aarch64_neonfma_cortex_a53);
      }
    }
  }

  TEST(F32_GEMM_1X12__AARCH64_NEONFMA_CORTEX_A53, k_lt_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(12)
        .kr(1)
        .sr(1)
        .m(1)
        .n(12)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_1x12__aarch64_neonfma_cortex_a53);
    }
  }

  TEST(F32_GEMM_1X12__AARCH64_NEONFMA_CORTEX_A53, k_lt_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(12)
        .kr(1)
        .sr(1)
        .m(1)
        .n(12)
        .k(k)
        .a_stride(11)
        .Test(xnn_f32_gemm_ukernel_1x12__aarch64_neonfma_cortex_a53);
    }
  }

  TEST(F32_GEMM_1X12__AARCH64_NEONFMA_CORTEX_A53, k_lt_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 8; k++) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 12; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(12)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x12__aarch64_neonfma_cortex_a53);
        }
      }
    }
  }

  TEST(F32_GEMM_1X12__AARCH64_NEONFMA_CORTEX_A53, k_gt_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 9; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(12)
        .kr(1)
        .sr(1)
        .m(1)
        .n(12)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_1x12__aarch64_neonfma_cortex_a53);
    }
  }

  TEST(F32_GEMM_1X12__AARCH64_NEONFMA_CORTEX_A53, k_gt_4_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 9; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(12)
        .kr(1)
        .sr(1)
        .m(1)
        .n(12)
        .k(k)
        .a_stride(11)
        .Test(xnn_f32_gemm_ukernel_1x12__aarch64_neonfma_cortex_a53);
    }
  }

  TEST(F32_GEMM_1X12__AARCH64_NEONFMA_CORTEX_A53, k_gt_4_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 9; k < 8; k++) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 12; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(12)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x12__aarch64_neonfma_cortex_a53);
        }
      }
    }
  }

  TEST(F32_GEMM_1X12__AARCH64_NEONFMA_CORTEX_A53, k_div_4) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 12; k <= 40; k += 4) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(12)
        .kr(1)
        .sr(1)
        .m(1)
        .n(12)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_1x12__aarch64_neonfma_cortex_a53);
    }
  }

  TEST(F32_GEMM_1X12__AARCH64_NEONFMA_CORTEX_A53, k_div_4_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 12; k <= 40; k += 4) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(12)
        .kr(1)
        .sr(1)
        .m(1)
        .n(12)
        .k(k)
        .a_stride(43)
        .Test(xnn_f32_gemm_ukernel_1x12__aarch64_neonfma_cortex_a53);
    }
  }

  TEST(F32_GEMM_1X12__AARCH64_NEONFMA_CORTEX_A53, k_div_4_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 12; k <= 40; k += 4) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 12; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(12)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x12__aarch64_neonfma_cortex_a53);
        }
      }
    }
  }

  TEST(F32_GEMM_1X12__AARCH64_NEONFMA_CORTEX_A53, n_gt_12) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 13; n < 24; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(12)
          .kr(1)
          .sr(1)
          .m(1)
          .n(12)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_1x12__aarch64_neonfma_cortex_a53);
      }
    }
  }

  TEST(F32_GEMM_1X12__AARCH64_NEONFMA_CORTEX_A53, n_gt_12_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 13; n < 24; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(12)
          .kr(1)
          .sr(1)
          .m(1)
          .n(12)
          .k(k)
          .cn_stride(17)
          .Test(xnn_f32_gemm_ukernel_1x12__aarch64_neonfma_cortex_a53);
      }
    }
  }

  TEST(F32_GEMM_1X12__AARCH64_NEONFMA_CORTEX_A53, n_gt_12_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 13; n < 24; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(12)
          .kr(1)
          .sr(1)
          .m(1)
          .n(n)
          .k(k)
          .a_stride(23)
          .Test(xnn_f32_gemm_ukernel_1x12__aarch64_neonfma_cortex_a53);
      }
    }
  }

  TEST(F32_GEMM_1X12__AARCH64_NEONFMA_CORTEX_A53, n_gt_12_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 13; n < 24; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        for (uint32_t m = 1; m <= 1; m++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(12)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x12__aarch64_neonfma_cortex_a53);
        }
      }
    }
  }

  TEST(F32_GEMM_1X12__AARCH64_NEONFMA_CORTEX_A53, n_div_12) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 24; n <= 36; n += 12) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(12)
          .kr(1)
          .sr(1)
          .m(1)
          .n(12)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_1x12__aarch64_neonfma_cortex_a53);
      }
    }
  }

  TEST(F32_GEMM_1X12__AARCH64_NEONFMA_CORTEX_A53, n_div_12_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 24; n <= 36; n += 12) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(12)
          .kr(1)
          .sr(1)
          .m(1)
          .n(n)
          .k(k)
          .cn_stride(17)
          .Test(xnn_f32_gemm_ukernel_1x12__aarch64_neonfma_cortex_a53);
      }
    }
  }

  TEST(F32_GEMM_1X12__AARCH64_NEONFMA_CORTEX_A53, n_div_12_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 24; n <= 36; n += 12) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(12)
          .kr(1)
          .sr(1)
          .m(1)
          .n(n)
          .k(k)
          .a_stride(23)
          .Test(xnn_f32_gemm_ukernel_1x12__aarch64_neonfma_cortex_a53);
      }
    }
  }

  TEST(F32_GEMM_1X12__AARCH64_NEONFMA_CORTEX_A53, n_div_12_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 24; n <= 36; n += 12) {
      for (size_t k = 1; k <= 20; k += 5) {
        for (uint32_t m = 1; m <= 1; m++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(12)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x12__aarch64_neonfma_cortex_a53);
        }
      }
    }
  }

  TEST(F32_GEMM_1X12__AARCH64_NEONFMA_CORTEX_A53, strided_cm_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k <= 20; k += 5) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 12; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(12)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(17)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x12__aarch64_neonfma_cortex_a53);
        }
      }
    }
  }

  TEST(F32_GEMM_1X12__AARCH64_NEONFMA_CORTEX_A53, qmin) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(1)
      .nr(12)
      .kr(1)
      .sr(1)
      .m(1)
      .n(12)
      .k(4)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_1x12__aarch64_neonfma_cortex_a53);
  }

  TEST(F32_GEMM_1X12__AARCH64_NEONFMA_CORTEX_A53, qmax) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(1)
      .nr(12)
      .kr(1)
      .sr(1)
      .m(1)
      .n(12)
      .k(4)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_1x12__aarch64_neonfma_cortex_a53);
  }

  TEST(F32_GEMM_1X12__AARCH64_NEONFMA_CORTEX_A53, strided_cm) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(1)
      .nr(12)
      .kr(1)
      .sr(1)
      .m(1)
      .n(12)
      .k(4)
      .cm_stride(17)
      .Test(xnn_f32_gemm_ukernel_1x12__aarch64_neonfma_cortex_a53);
  }
#endif  // XNN_ARCH_ARM64


#if XNN_ARCH_ARM64
  TEST(F32_GEMM_4X12__AARCH64_NEONFMA_CORTEX_A53, k_eq_4) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(12)
      .kr(1)
      .sr(1)
      .m(4)
      .n(12)
      .k(4)
      .Test(xnn_f32_gemm_ukernel_4x12__aarch64_neonfma_cortex_a53);
  }

  TEST(F32_GEMM_4X12__AARCH64_NEONFMA_CORTEX_A53, strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(12)
      .kr(1)
      .sr(1)
      .m(4)
      .n(12)
      .k(4)
      .cn_stride(17)
      .Test(xnn_f32_gemm_ukernel_4x12__aarch64_neonfma_cortex_a53);
  }

  TEST(F32_GEMM_4X12__AARCH64_NEONFMA_CORTEX_A53, k_eq_4_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(12)
      .kr(1)
      .sr(1)
      .m(4)
      .n(12)
      .k(4)
      .a_stride(7)
      .Test(xnn_f32_gemm_ukernel_4x12__aarch64_neonfma_cortex_a53);
  }

  TEST(F32_GEMM_4X12__AARCH64_NEONFMA_CORTEX_A53, k_eq_4_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 4; m++) {
      for (uint32_t n = 1; n <= 12; n++) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(12)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(4)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_4x12__aarch64_neonfma_cortex_a53);
      }
    }
  }

  TEST(F32_GEMM_4X12__AARCH64_NEONFMA_CORTEX_A53, k_eq_4_subtile_m) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 4; m++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(12)
        .kr(1)
        .sr(1)
        .m(m)
        .n(12)
        .k(4)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x12__aarch64_neonfma_cortex_a53);
    }
  }

  TEST(F32_GEMM_4X12__AARCH64_NEONFMA_CORTEX_A53, k_eq_4_subtile_n) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 1; n <= 12; n++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(12)
        .kr(1)
        .sr(1)
        .m(4)
        .n(n)
        .k(4)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x12__aarch64_neonfma_cortex_a53);
    }
  }

  TEST(F32_GEMM_4X12__AARCH64_NEONFMA_CORTEX_A53, k_eq_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(12)
      .kr(1)
      .sr(1)
      .m(4)
      .n(12)
      .k(8)
      .Test(xnn_f32_gemm_ukernel_4x12__aarch64_neonfma_cortex_a53);
  }

  TEST(F32_GEMM_4X12__AARCH64_NEONFMA_CORTEX_A53, k_eq_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(12)
      .kr(1)
      .sr(1)
      .m(4)
      .n(12)
      .k(8)
      .a_stride(11)
      .Test(xnn_f32_gemm_ukernel_4x12__aarch64_neonfma_cortex_a53);
  }

  TEST(F32_GEMM_4X12__AARCH64_NEONFMA_CORTEX_A53, k_eq_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 4; m++) {
      for (uint32_t n = 1; n <= 12; n++) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(12)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(8)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_4x12__aarch64_neonfma_cortex_a53);
      }
    }
  }

  TEST(F32_GEMM_4X12__AARCH64_NEONFMA_CORTEX_A53, k_lt_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(12)
        .kr(1)
        .sr(1)
        .m(4)
        .n(12)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x12__aarch64_neonfma_cortex_a53);
    }
  }

  TEST(F32_GEMM_4X12__AARCH64_NEONFMA_CORTEX_A53, k_lt_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(12)
        .kr(1)
        .sr(1)
        .m(4)
        .n(12)
        .k(k)
        .a_stride(11)
        .Test(xnn_f32_gemm_ukernel_4x12__aarch64_neonfma_cortex_a53);
    }
  }

  TEST(F32_GEMM_4X12__AARCH64_NEONFMA_CORTEX_A53, k_lt_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 8; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 12; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(12)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x12__aarch64_neonfma_cortex_a53);
        }
      }
    }
  }

  TEST(F32_GEMM_4X12__AARCH64_NEONFMA_CORTEX_A53, k_gt_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 9; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(12)
        .kr(1)
        .sr(1)
        .m(4)
        .n(12)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x12__aarch64_neonfma_cortex_a53);
    }
  }

  TEST(F32_GEMM_4X12__AARCH64_NEONFMA_CORTEX_A53, k_gt_4_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 9; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(12)
        .kr(1)
        .sr(1)
        .m(4)
        .n(12)
        .k(k)
        .a_stride(11)
        .Test(xnn_f32_gemm_ukernel_4x12__aarch64_neonfma_cortex_a53);
    }
  }

  TEST(F32_GEMM_4X12__AARCH64_NEONFMA_CORTEX_A53, k_gt_4_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 9; k < 8; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 12; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(12)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x12__aarch64_neonfma_cortex_a53);
        }
      }
    }
  }

  TEST(F32_GEMM_4X12__AARCH64_NEONFMA_CORTEX_A53, k_div_4) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 12; k <= 40; k += 4) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(12)
        .kr(1)
        .sr(1)
        .m(4)
        .n(12)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x12__aarch64_neonfma_cortex_a53);
    }
  }

  TEST(F32_GEMM_4X12__AARCH64_NEONFMA_CORTEX_A53, k_div_4_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 12; k <= 40; k += 4) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(12)
        .kr(1)
        .sr(1)
        .m(4)
        .n(12)
        .k(k)
        .a_stride(43)
        .Test(xnn_f32_gemm_ukernel_4x12__aarch64_neonfma_cortex_a53);
    }
  }

  TEST(F32_GEMM_4X12__AARCH64_NEONFMA_CORTEX_A53, k_div_4_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 12; k <= 40; k += 4) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 12; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(12)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x12__aarch64_neonfma_cortex_a53);
        }
      }
    }
  }

  TEST(F32_GEMM_4X12__AARCH64_NEONFMA_CORTEX_A53, n_gt_12) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 13; n < 24; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(12)
          .kr(1)
          .sr(1)
          .m(4)
          .n(12)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x12__aarch64_neonfma_cortex_a53);
      }
    }
  }

  TEST(F32_GEMM_4X12__AARCH64_NEONFMA_CORTEX_A53, n_gt_12_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 13; n < 24; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(12)
          .kr(1)
          .sr(1)
          .m(4)
          .n(12)
          .k(k)
          .cn_stride(17)
          .Test(xnn_f32_gemm_ukernel_4x12__aarch64_neonfma_cortex_a53);
      }
    }
  }

  TEST(F32_GEMM_4X12__AARCH64_NEONFMA_CORTEX_A53, n_gt_12_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 13; n < 24; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(12)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(23)
          .Test(xnn_f32_gemm_ukernel_4x12__aarch64_neonfma_cortex_a53);
      }
    }
  }

  TEST(F32_GEMM_4X12__AARCH64_NEONFMA_CORTEX_A53, n_gt_12_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 13; n < 24; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(12)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x12__aarch64_neonfma_cortex_a53);
        }
      }
    }
  }

  TEST(F32_GEMM_4X12__AARCH64_NEONFMA_CORTEX_A53, n_div_12) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 24; n <= 36; n += 12) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(12)
          .kr(1)
          .sr(1)
          .m(4)
          .n(12)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x12__aarch64_neonfma_cortex_a53);
      }
    }
  }

  TEST(F32_GEMM_4X12__AARCH64_NEONFMA_CORTEX_A53, n_div_12_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 24; n <= 36; n += 12) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(12)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .cn_stride(17)
          .Test(xnn_f32_gemm_ukernel_4x12__aarch64_neonfma_cortex_a53);
      }
    }
  }

  TEST(F32_GEMM_4X12__AARCH64_NEONFMA_CORTEX_A53, n_div_12_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 24; n <= 36; n += 12) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(12)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(23)
          .Test(xnn_f32_gemm_ukernel_4x12__aarch64_neonfma_cortex_a53);
      }
    }
  }

  TEST(F32_GEMM_4X12__AARCH64_NEONFMA_CORTEX_A53, n_div_12_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 24; n <= 36; n += 12) {
      for (size_t k = 1; k <= 20; k += 5) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(12)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x12__aarch64_neonfma_cortex_a53);
        }
      }
    }
  }

  TEST(F32_GEMM_4X12__AARCH64_NEONFMA_CORTEX_A53, strided_cm_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k <= 20; k += 5) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 12; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(12)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(17)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x12__aarch64_neonfma_cortex_a53);
        }
      }
    }
  }

  TEST(F32_GEMM_4X12__AARCH64_NEONFMA_CORTEX_A53, qmin) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(12)
      .kr(1)
      .sr(1)
      .m(4)
      .n(12)
      .k(4)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_4x12__aarch64_neonfma_cortex_a53);
  }

  TEST(F32_GEMM_4X12__AARCH64_NEONFMA_CORTEX_A53, qmax) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(12)
      .kr(1)
      .sr(1)
      .m(4)
      .n(12)
      .k(4)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_4x12__aarch64_neonfma_cortex_a53);
  }

  TEST(F32_GEMM_4X12__AARCH64_NEONFMA_CORTEX_A53, strided_cm) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(12)
      .kr(1)
      .sr(1)
      .m(4)
      .n(12)
      .k(4)
      .cm_stride(17)
      .Test(xnn_f32_gemm_ukernel_4x12__aarch64_neonfma_cortex_a53);
  }
#endif  // XNN_ARCH_ARM64


#if XNN_ARCH_ARM64
  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD64, k_eq_2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(2)
      .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld64);
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD64, strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(2)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld64);
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD64, k_eq_2_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(2)
      .a_stride(5)
      .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld64);
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD64, k_eq_2_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 4; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(2)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD64, k_eq_2_subtile_m) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 4; m++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(m)
        .n(8)
        .k(2)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld64);
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD64, k_eq_2_subtile_n) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(n)
        .k(2)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld64);
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD64, k_lt_2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 2; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld64);
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD64, k_lt_2_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 2; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(5)
        .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld64);
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD64, k_lt_2_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 2; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD64, k_gt_2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 3; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld64);
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD64, k_gt_2_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 3; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(7)
        .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld64);
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD64, k_gt_2_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 3; k < 4; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD64, k_div_2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 4; k <= 20; k += 2) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld64);
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD64, k_div_2_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 4; k <= 20; k += 2) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(23)
        .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld64);
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD64, k_div_2_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 4; k <= 20; k += 2) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD64, n_gt_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD64, n_gt_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD64, n_gt_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(13)
          .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD64, n_gt_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD64, n_div_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD64, n_div_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD64, n_div_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(13)
          .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD64, n_div_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD64, strided_cm_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k <= 10; k += 3) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD64, qmin) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(2)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld64);
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD64, qmax) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(2)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld64);
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD64, strided_cm) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(2)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld64);
  }
#endif  // XNN_ARCH_ARM64


#if XNN_ARCH_ARM64
  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD128, k_eq_4) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(4)
      .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld128);
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD128, strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(4)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld128);
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD128, k_eq_4_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(4)
      .a_stride(7)
      .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld128);
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD128, k_eq_4_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 4; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(4)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld128);
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD128, k_eq_4_subtile_m) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 4; m++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(m)
        .n(8)
        .k(4)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld128);
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD128, k_eq_4_subtile_n) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(n)
        .k(4)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld128);
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD128, k_lt_4) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld128);
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD128, k_lt_4_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(7)
        .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld128);
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD128, k_lt_4_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 4; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld128);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD128, k_gt_4) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 5; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld128);
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD128, k_gt_4_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 5; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(11)
        .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld128);
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD128, k_gt_4_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 5; k < 8; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld128);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD128, k_div_4) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 8; k <= 40; k += 4) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld128);
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD128, k_div_4_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 8; k <= 40; k += 4) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(43)
        .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld128);
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD128, k_div_4_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 8; k <= 40; k += 4) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld128);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD128, n_gt_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld128);
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD128, n_gt_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld128);
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD128, n_gt_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(23)
          .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld128);
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD128, n_gt_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld128);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD128, n_div_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld128);
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD128, n_div_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld128);
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD128, n_div_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(23)
          .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld128);
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD128, n_div_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld128);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD128, strided_cm_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k <= 20; k += 5) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld128);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD128, qmin) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(4)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld128);
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD128, qmax) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(4)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld128);
  }

  TEST(F32_GEMM_4X8__AARCH64_NEONFMA_LD128, strided_cm) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(4)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_4x8__aarch64_neonfma_ld128);
  }
#endif  // XNN_ARCH_ARM64


#if XNN_ARCH_ARM64
  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD64, k_eq_2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(2)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld64);
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD64, strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(2)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld64);
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD64, k_eq_2_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(2)
      .a_stride(5)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld64);
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD64, k_eq_2_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 6; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(2)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD64, k_eq_2_subtile_m) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 6; m++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(m)
        .n(8)
        .k(2)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld64);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD64, k_eq_2_subtile_n) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(n)
        .k(2)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld64);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD64, k_lt_2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 2; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld64);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD64, k_lt_2_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 2; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .a_stride(5)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld64);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD64, k_lt_2_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 2; k++) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD64, k_gt_2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 3; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld64);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD64, k_gt_2_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 3; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .a_stride(7)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld64);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD64, k_gt_2_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 3; k < 4; k++) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD64, k_div_2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 4; k <= 20; k += 2) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld64);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD64, k_div_2_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 4; k <= 20; k += 2) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .a_stride(23)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld64);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD64, k_div_2_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 4; k <= 20; k += 2) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD64, n_gt_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD64, n_gt_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD64, n_gt_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(n)
          .k(k)
          .a_stride(13)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD64, n_gt_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        for (uint32_t m = 1; m <= 6; m++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD64, n_div_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD64, n_div_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD64, n_div_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(n)
          .k(k)
          .a_stride(13)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD64, n_div_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        for (uint32_t m = 1; m <= 6; m++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD64, strided_cm_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k <= 10; k += 3) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD64, qmin) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(2)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld64);
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD64, qmax) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(2)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld64);
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD64, strided_cm) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(2)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld64);
  }
#endif  // XNN_ARCH_ARM64


#if XNN_ARCH_ARM64
  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD128, k_eq_4) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(4)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld128);
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD128, strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(4)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld128);
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD128, k_eq_4_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(4)
      .a_stride(7)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld128);
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD128, k_eq_4_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 6; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(4)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld128);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD128, k_eq_4_subtile_m) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 6; m++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(m)
        .n(8)
        .k(4)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld128);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD128, k_eq_4_subtile_n) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(n)
        .k(4)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld128);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD128, k_lt_4) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld128);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD128, k_lt_4_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .a_stride(7)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld128);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD128, k_lt_4_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 4; k++) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld128);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD128, k_gt_4) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 5; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld128);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD128, k_gt_4_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 5; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .a_stride(11)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld128);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD128, k_gt_4_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 5; k < 8; k++) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld128);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD128, k_div_4) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 8; k <= 40; k += 4) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld128);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD128, k_div_4_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 8; k <= 40; k += 4) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .a_stride(43)
        .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld128);
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD128, k_div_4_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 8; k <= 40; k += 4) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld128);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD128, n_gt_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld128);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD128, n_gt_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld128);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD128, n_gt_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(n)
          .k(k)
          .a_stride(23)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld128);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD128, n_gt_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        for (uint32_t m = 1; m <= 6; m++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld128);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD128, n_div_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld128);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD128, n_div_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld128);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD128, n_div_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(n)
          .k(k)
          .a_stride(23)
          .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld128);
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD128, n_div_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        for (uint32_t m = 1; m <= 6; m++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld128);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD128, strided_cm_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k <= 20; k += 5) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld128);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD128, qmin) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(4)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld128);
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD128, qmax) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(4)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld128);
  }

  TEST(F32_GEMM_6X8__AARCH64_NEONFMA_LD128, strided_cm) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(4)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_6x8__aarch64_neonfma_ld128);
  }
#endif  // XNN_ARCH_ARM64


#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(F32_GEMM_4X12__NEON_LD64, k_eq_2) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(4)
      .nr(12)
      .kr(1)
      .sr(1)
      .m(4)
      .n(12)
      .k(2)
      .Test(xnn_f32_gemm_ukernel_4x12__neon_ld64);
  }

  TEST(F32_GEMM_4X12__NEON_LD64, strided_cn) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(4)
      .nr(12)
      .kr(1)
      .sr(1)
      .m(4)
      .n(12)
      .k(2)
      .cn_stride(17)
      .Test(xnn_f32_gemm_ukernel_4x12__neon_ld64);
  }

  TEST(F32_GEMM_4X12__NEON_LD64, k_eq_2_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(4)
      .nr(12)
      .kr(1)
      .sr(1)
      .m(4)
      .n(12)
      .k(2)
      .a_stride(5)
      .Test(xnn_f32_gemm_ukernel_4x12__neon_ld64);
  }

  TEST(F32_GEMM_4X12__NEON_LD64, k_eq_2_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t m = 1; m <= 4; m++) {
      for (uint32_t n = 1; n <= 12; n++) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(12)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(2)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_4x12__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X12__NEON_LD64, k_eq_2_subtile_m) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t m = 1; m <= 4; m++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(12)
        .kr(1)
        .sr(1)
        .m(m)
        .n(12)
        .k(2)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x12__neon_ld64);
    }
  }

  TEST(F32_GEMM_4X12__NEON_LD64, k_eq_2_subtile_n) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 1; n <= 12; n++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(12)
        .kr(1)
        .sr(1)
        .m(4)
        .n(n)
        .k(2)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x12__neon_ld64);
    }
  }

  TEST(F32_GEMM_4X12__NEON_LD64, k_lt_2) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 1; k < 2; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(12)
        .kr(1)
        .sr(1)
        .m(4)
        .n(12)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x12__neon_ld64);
    }
  }

  TEST(F32_GEMM_4X12__NEON_LD64, k_lt_2_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 1; k < 2; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(12)
        .kr(1)
        .sr(1)
        .m(4)
        .n(12)
        .k(k)
        .a_stride(5)
        .Test(xnn_f32_gemm_ukernel_4x12__neon_ld64);
    }
  }

  TEST(F32_GEMM_4X12__NEON_LD64, k_lt_2_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 1; k < 2; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 12; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(12)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x12__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X12__NEON_LD64, k_gt_2) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 3; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(12)
        .kr(1)
        .sr(1)
        .m(4)
        .n(12)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x12__neon_ld64);
    }
  }

  TEST(F32_GEMM_4X12__NEON_LD64, k_gt_2_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 3; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(12)
        .kr(1)
        .sr(1)
        .m(4)
        .n(12)
        .k(k)
        .a_stride(7)
        .Test(xnn_f32_gemm_ukernel_4x12__neon_ld64);
    }
  }

  TEST(F32_GEMM_4X12__NEON_LD64, k_gt_2_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 3; k < 4; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 12; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(12)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x12__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X12__NEON_LD64, k_div_2) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 4; k <= 20; k += 2) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(12)
        .kr(1)
        .sr(1)
        .m(4)
        .n(12)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x12__neon_ld64);
    }
  }

  TEST(F32_GEMM_4X12__NEON_LD64, k_div_2_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 4; k <= 20; k += 2) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(12)
        .kr(1)
        .sr(1)
        .m(4)
        .n(12)
        .k(k)
        .a_stride(23)
        .Test(xnn_f32_gemm_ukernel_4x12__neon_ld64);
    }
  }

  TEST(F32_GEMM_4X12__NEON_LD64, k_div_2_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 4; k <= 20; k += 2) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 12; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(12)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x12__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X12__NEON_LD64, n_gt_12) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 13; n < 24; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(12)
          .kr(1)
          .sr(1)
          .m(4)
          .n(12)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x12__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X12__NEON_LD64, n_gt_12_strided_cn) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 13; n < 24; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(12)
          .kr(1)
          .sr(1)
          .m(4)
          .n(12)
          .k(k)
          .cn_stride(17)
          .Test(xnn_f32_gemm_ukernel_4x12__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X12__NEON_LD64, n_gt_12_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 13; n < 24; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(12)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(13)
          .Test(xnn_f32_gemm_ukernel_4x12__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X12__NEON_LD64, n_gt_12_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 13; n < 24; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(12)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x12__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X12__NEON_LD64, n_div_12) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 24; n <= 36; n += 12) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(12)
          .kr(1)
          .sr(1)
          .m(4)
          .n(12)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x12__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X12__NEON_LD64, n_div_12_strided_cn) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 24; n <= 36; n += 12) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(12)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .cn_stride(17)
          .Test(xnn_f32_gemm_ukernel_4x12__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X12__NEON_LD64, n_div_12_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 24; n <= 36; n += 12) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(12)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(13)
          .Test(xnn_f32_gemm_ukernel_4x12__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X12__NEON_LD64, n_div_12_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 24; n <= 36; n += 12) {
      for (size_t k = 1; k <= 10; k += 3) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(12)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x12__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X12__NEON_LD64, strided_cm_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 1; k <= 10; k += 3) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 12; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(12)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(17)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x12__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X12__NEON_LD64, qmin) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(4)
      .nr(12)
      .kr(1)
      .sr(1)
      .m(4)
      .n(12)
      .k(2)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_4x12__neon_ld64);
  }

  TEST(F32_GEMM_4X12__NEON_LD64, qmax) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(4)
      .nr(12)
      .kr(1)
      .sr(1)
      .m(4)
      .n(12)
      .k(2)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_4x12__neon_ld64);
  }

  TEST(F32_GEMM_4X12__NEON_LD64, strided_cm) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(4)
      .nr(12)
      .kr(1)
      .sr(1)
      .m(4)
      .n(12)
      .k(2)
      .cm_stride(17)
      .Test(xnn_f32_gemm_ukernel_4x12__neon_ld64);
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64


#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(F32_GEMM_1X8__NEON_LD64, k_eq_2) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(2)
      .Test(xnn_f32_gemm_ukernel_1x8__neon_ld64);
  }

  TEST(F32_GEMM_1X8__NEON_LD64, strided_cn) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(2)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_1x8__neon_ld64);
  }

  TEST(F32_GEMM_1X8__NEON_LD64, k_eq_2_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(2)
      .a_stride(5)
      .Test(xnn_f32_gemm_ukernel_1x8__neon_ld64);
  }

  TEST(F32_GEMM_1X8__NEON_LD64, k_eq_2_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t m = 1; m <= 1; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(2)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_1x8__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_1X8__NEON_LD64, k_eq_2_subtile_m) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t m = 1; m <= 1; m++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(m)
        .n(8)
        .k(2)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_1x8__neon_ld64);
    }
  }

  TEST(F32_GEMM_1X8__NEON_LD64, k_eq_2_subtile_n) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(n)
        .k(2)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_1x8__neon_ld64);
    }
  }

  TEST(F32_GEMM_1X8__NEON_LD64, k_lt_2) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 1; k < 2; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_1x8__neon_ld64);
    }
  }

  TEST(F32_GEMM_1X8__NEON_LD64, k_lt_2_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 1; k < 2; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .a_stride(5)
        .Test(xnn_f32_gemm_ukernel_1x8__neon_ld64);
    }
  }

  TEST(F32_GEMM_1X8__NEON_LD64, k_lt_2_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 1; k < 2; k++) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__NEON_LD64, k_gt_2) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 3; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_1x8__neon_ld64);
    }
  }

  TEST(F32_GEMM_1X8__NEON_LD64, k_gt_2_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 3; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .a_stride(7)
        .Test(xnn_f32_gemm_ukernel_1x8__neon_ld64);
    }
  }

  TEST(F32_GEMM_1X8__NEON_LD64, k_gt_2_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 3; k < 4; k++) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__NEON_LD64, k_div_2) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 4; k <= 20; k += 2) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_1x8__neon_ld64);
    }
  }

  TEST(F32_GEMM_1X8__NEON_LD64, k_div_2_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 4; k <= 20; k += 2) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .a_stride(23)
        .Test(xnn_f32_gemm_ukernel_1x8__neon_ld64);
    }
  }

  TEST(F32_GEMM_1X8__NEON_LD64, k_div_2_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 4; k <= 20; k += 2) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__NEON_LD64, n_gt_8) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_1x8__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_1X8__NEON_LD64, n_gt_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_1x8__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_1X8__NEON_LD64, n_gt_8_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(n)
          .k(k)
          .a_stride(13)
          .Test(xnn_f32_gemm_ukernel_1x8__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_1X8__NEON_LD64, n_gt_8_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        for (uint32_t m = 1; m <= 1; m++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__NEON_LD64, n_div_8) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_1x8__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_1X8__NEON_LD64, n_div_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_1x8__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_1X8__NEON_LD64, n_div_8_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(n)
          .k(k)
          .a_stride(13)
          .Test(xnn_f32_gemm_ukernel_1x8__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_1X8__NEON_LD64, n_div_8_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        for (uint32_t m = 1; m <= 1; m++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__NEON_LD64, strided_cm_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 1; k <= 10; k += 3) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__NEON_LD64, qmin) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(2)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_1x8__neon_ld64);
  }

  TEST(F32_GEMM_1X8__NEON_LD64, qmax) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(2)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_1x8__neon_ld64);
  }

  TEST(F32_GEMM_1X8__NEON_LD64, strided_cm) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(2)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_1x8__neon_ld64);
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64


#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(F32_GEMM_4X2__NEON_LD64, k_eq_2) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(4)
      .nr(2)
      .kr(1)
      .sr(1)
      .m(4)
      .n(2)
      .k(2)
      .Test(xnn_f32_gemm_ukernel_4x2__neon_ld64);
  }

  TEST(F32_GEMM_4X2__NEON_LD64, strided_cn) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(4)
      .nr(2)
      .kr(1)
      .sr(1)
      .m(4)
      .n(2)
      .k(2)
      .cn_stride(5)
      .Test(xnn_f32_gemm_ukernel_4x2__neon_ld64);
  }

  TEST(F32_GEMM_4X2__NEON_LD64, k_eq_2_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(4)
      .nr(2)
      .kr(1)
      .sr(1)
      .m(4)
      .n(2)
      .k(2)
      .a_stride(5)
      .Test(xnn_f32_gemm_ukernel_4x2__neon_ld64);
  }

  TEST(F32_GEMM_4X2__NEON_LD64, k_eq_2_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t m = 1; m <= 4; m++) {
      for (uint32_t n = 1; n <= 2; n++) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(2)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(2)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_4x2__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X2__NEON_LD64, k_eq_2_subtile_m) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t m = 1; m <= 4; m++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(2)
        .kr(1)
        .sr(1)
        .m(m)
        .n(2)
        .k(2)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x2__neon_ld64);
    }
  }

  TEST(F32_GEMM_4X2__NEON_LD64, k_eq_2_subtile_n) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 1; n <= 2; n++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(2)
        .kr(1)
        .sr(1)
        .m(4)
        .n(n)
        .k(2)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x2__neon_ld64);
    }
  }

  TEST(F32_GEMM_4X2__NEON_LD64, k_lt_2) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 1; k < 2; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(2)
        .kr(1)
        .sr(1)
        .m(4)
        .n(2)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x2__neon_ld64);
    }
  }

  TEST(F32_GEMM_4X2__NEON_LD64, k_lt_2_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 1; k < 2; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(2)
        .kr(1)
        .sr(1)
        .m(4)
        .n(2)
        .k(k)
        .a_stride(5)
        .Test(xnn_f32_gemm_ukernel_4x2__neon_ld64);
    }
  }

  TEST(F32_GEMM_4X2__NEON_LD64, k_lt_2_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 1; k < 2; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 2; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(2)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x2__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X2__NEON_LD64, k_gt_2) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 3; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(2)
        .kr(1)
        .sr(1)
        .m(4)
        .n(2)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x2__neon_ld64);
    }
  }

  TEST(F32_GEMM_4X2__NEON_LD64, k_gt_2_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 3; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(2)
        .kr(1)
        .sr(1)
        .m(4)
        .n(2)
        .k(k)
        .a_stride(7)
        .Test(xnn_f32_gemm_ukernel_4x2__neon_ld64);
    }
  }

  TEST(F32_GEMM_4X2__NEON_LD64, k_gt_2_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 3; k < 4; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 2; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(2)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x2__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X2__NEON_LD64, k_div_2) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 4; k <= 20; k += 2) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(2)
        .kr(1)
        .sr(1)
        .m(4)
        .n(2)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x2__neon_ld64);
    }
  }

  TEST(F32_GEMM_4X2__NEON_LD64, k_div_2_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 4; k <= 20; k += 2) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(2)
        .kr(1)
        .sr(1)
        .m(4)
        .n(2)
        .k(k)
        .a_stride(23)
        .Test(xnn_f32_gemm_ukernel_4x2__neon_ld64);
    }
  }

  TEST(F32_GEMM_4X2__NEON_LD64, k_div_2_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 4; k <= 20; k += 2) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 2; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(2)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x2__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X2__NEON_LD64, n_gt_2) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 3; n < 4; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(2)
          .kr(1)
          .sr(1)
          .m(4)
          .n(2)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x2__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X2__NEON_LD64, n_gt_2_strided_cn) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 3; n < 4; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(2)
          .kr(1)
          .sr(1)
          .m(4)
          .n(2)
          .k(k)
          .cn_stride(5)
          .Test(xnn_f32_gemm_ukernel_4x2__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X2__NEON_LD64, n_gt_2_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 3; n < 4; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(2)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(13)
          .Test(xnn_f32_gemm_ukernel_4x2__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X2__NEON_LD64, n_gt_2_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 3; n < 4; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(2)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x2__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X2__NEON_LD64, n_div_2) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 4; n <= 6; n += 2) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(2)
          .kr(1)
          .sr(1)
          .m(4)
          .n(2)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x2__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X2__NEON_LD64, n_div_2_strided_cn) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 4; n <= 6; n += 2) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(2)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .cn_stride(5)
          .Test(xnn_f32_gemm_ukernel_4x2__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X2__NEON_LD64, n_div_2_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 4; n <= 6; n += 2) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(2)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(13)
          .Test(xnn_f32_gemm_ukernel_4x2__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X2__NEON_LD64, n_div_2_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 4; n <= 6; n += 2) {
      for (size_t k = 1; k <= 10; k += 3) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(2)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x2__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X2__NEON_LD64, strided_cm_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 1; k <= 10; k += 3) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 2; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(2)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(5)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x2__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X2__NEON_LD64, qmin) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(4)
      .nr(2)
      .kr(1)
      .sr(1)
      .m(4)
      .n(2)
      .k(2)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_4x2__neon_ld64);
  }

  TEST(F32_GEMM_4X2__NEON_LD64, qmax) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(4)
      .nr(2)
      .kr(1)
      .sr(1)
      .m(4)
      .n(2)
      .k(2)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_4x2__neon_ld64);
  }

  TEST(F32_GEMM_4X2__NEON_LD64, strided_cm) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(4)
      .nr(2)
      .kr(1)
      .sr(1)
      .m(4)
      .n(2)
      .k(2)
      .cm_stride(5)
      .Test(xnn_f32_gemm_ukernel_4x2__neon_ld64);
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64


#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(F32_GEMM_4X8__NEON_LD64, k_eq_2) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(2)
      .Test(xnn_f32_gemm_ukernel_4x8__neon_ld64);
  }

  TEST(F32_GEMM_4X8__NEON_LD64, strided_cn) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(2)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_4x8__neon_ld64);
  }

  TEST(F32_GEMM_4X8__NEON_LD64, k_eq_2_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(2)
      .a_stride(5)
      .Test(xnn_f32_gemm_ukernel_4x8__neon_ld64);
  }

  TEST(F32_GEMM_4X8__NEON_LD64, k_eq_2_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t m = 1; m <= 4; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(2)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_4x8__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD64, k_eq_2_subtile_m) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t m = 1; m <= 4; m++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(m)
        .n(8)
        .k(2)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x8__neon_ld64);
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD64, k_eq_2_subtile_n) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(n)
        .k(2)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x8__neon_ld64);
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD64, k_lt_2) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 1; k < 2; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8__neon_ld64);
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD64, k_lt_2_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 1; k < 2; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(5)
        .Test(xnn_f32_gemm_ukernel_4x8__neon_ld64);
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD64, k_lt_2_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 1; k < 2; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD64, k_gt_2) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 3; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8__neon_ld64);
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD64, k_gt_2_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 3; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(7)
        .Test(xnn_f32_gemm_ukernel_4x8__neon_ld64);
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD64, k_gt_2_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 3; k < 4; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD64, k_div_2) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 4; k <= 20; k += 2) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8__neon_ld64);
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD64, k_div_2_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 4; k <= 20; k += 2) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(23)
        .Test(xnn_f32_gemm_ukernel_4x8__neon_ld64);
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD64, k_div_2_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 4; k <= 20; k += 2) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD64, n_gt_8) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x8__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD64, n_gt_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_4x8__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD64, n_gt_8_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(13)
          .Test(xnn_f32_gemm_ukernel_4x8__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD64, n_gt_8_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD64, n_div_8) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x8__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD64, n_div_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_4x8__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD64, n_div_8_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(13)
          .Test(xnn_f32_gemm_ukernel_4x8__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD64, n_div_8_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD64, strided_cm_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 1; k <= 10; k += 3) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD64, qmin) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(2)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_4x8__neon_ld64);
  }

  TEST(F32_GEMM_4X8__NEON_LD64, qmax) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(2)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_4x8__neon_ld64);
  }

  TEST(F32_GEMM_4X8__NEON_LD64, strided_cm) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(2)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_4x8__neon_ld64);
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64


#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(F32_GEMM_4X8__NEON_LD128, k_eq_4) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(4)
      .Test(xnn_f32_gemm_ukernel_4x8__neon_ld128);
  }

  TEST(F32_GEMM_4X8__NEON_LD128, strided_cn) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(4)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_4x8__neon_ld128);
  }

  TEST(F32_GEMM_4X8__NEON_LD128, k_eq_4_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(4)
      .a_stride(7)
      .Test(xnn_f32_gemm_ukernel_4x8__neon_ld128);
  }

  TEST(F32_GEMM_4X8__NEON_LD128, k_eq_4_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t m = 1; m <= 4; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(4)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_4x8__neon_ld128);
      }
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD128, k_eq_4_subtile_m) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t m = 1; m <= 4; m++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(m)
        .n(8)
        .k(4)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x8__neon_ld128);
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD128, k_eq_4_subtile_n) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(n)
        .k(4)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x8__neon_ld128);
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD128, k_lt_4) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 1; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8__neon_ld128);
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD128, k_lt_4_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 1; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(7)
        .Test(xnn_f32_gemm_ukernel_4x8__neon_ld128);
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD128, k_lt_4_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 1; k < 4; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__neon_ld128);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD128, k_gt_4) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 5; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8__neon_ld128);
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD128, k_gt_4_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 5; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(11)
        .Test(xnn_f32_gemm_ukernel_4x8__neon_ld128);
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD128, k_gt_4_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 5; k < 8; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__neon_ld128);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD128, k_div_4) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 8; k <= 40; k += 4) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8__neon_ld128);
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD128, k_div_4_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 8; k <= 40; k += 4) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(43)
        .Test(xnn_f32_gemm_ukernel_4x8__neon_ld128);
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD128, k_div_4_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 8; k <= 40; k += 4) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__neon_ld128);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD128, n_gt_8) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x8__neon_ld128);
      }
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD128, n_gt_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_4x8__neon_ld128);
      }
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD128, n_gt_8_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(23)
          .Test(xnn_f32_gemm_ukernel_4x8__neon_ld128);
      }
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD128, n_gt_8_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__neon_ld128);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD128, n_div_8) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x8__neon_ld128);
      }
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD128, n_div_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_4x8__neon_ld128);
      }
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD128, n_div_8_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(23)
          .Test(xnn_f32_gemm_ukernel_4x8__neon_ld128);
      }
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD128, n_div_8_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__neon_ld128);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD128, strided_cm_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 1; k <= 20; k += 5) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__neon_ld128);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__NEON_LD128, qmin) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(4)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_4x8__neon_ld128);
  }

  TEST(F32_GEMM_4X8__NEON_LD128, qmax) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(4)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_4x8__neon_ld128);
  }

  TEST(F32_GEMM_4X8__NEON_LD128, strided_cm) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(4)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_4x8__neon_ld128);
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64


#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(F32_GEMM_5X8__NEON_LD64, k_eq_2) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(5)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(5)
      .n(8)
      .k(2)
      .Test(xnn_f32_gemm_ukernel_5x8__neon_ld64);
  }

  TEST(F32_GEMM_5X8__NEON_LD64, strided_cn) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(5)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(5)
      .n(8)
      .k(2)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_5x8__neon_ld64);
  }

  TEST(F32_GEMM_5X8__NEON_LD64, k_eq_2_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(5)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(5)
      .n(8)
      .k(2)
      .a_stride(5)
      .Test(xnn_f32_gemm_ukernel_5x8__neon_ld64);
  }

  TEST(F32_GEMM_5X8__NEON_LD64, k_eq_2_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t m = 1; m <= 5; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(5)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(2)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_5x8__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_5X8__NEON_LD64, k_eq_2_subtile_m) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t m = 1; m <= 5; m++) {
      GemmMicrokernelTester()
        .mr(5)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(m)
        .n(8)
        .k(2)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_5x8__neon_ld64);
    }
  }

  TEST(F32_GEMM_5X8__NEON_LD64, k_eq_2_subtile_n) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(5)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(5)
        .n(n)
        .k(2)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_5x8__neon_ld64);
    }
  }

  TEST(F32_GEMM_5X8__NEON_LD64, k_lt_2) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 1; k < 2; k++) {
      GemmMicrokernelTester()
        .mr(5)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(5)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_5x8__neon_ld64);
    }
  }

  TEST(F32_GEMM_5X8__NEON_LD64, k_lt_2_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 1; k < 2; k++) {
      GemmMicrokernelTester()
        .mr(5)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(5)
        .n(8)
        .k(k)
        .a_stride(5)
        .Test(xnn_f32_gemm_ukernel_5x8__neon_ld64);
    }
  }

  TEST(F32_GEMM_5X8__NEON_LD64, k_lt_2_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 1; k < 2; k++) {
      for (uint32_t m = 1; m <= 5; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(5)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_5x8__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_5X8__NEON_LD64, k_gt_2) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 3; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(5)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(5)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_5x8__neon_ld64);
    }
  }

  TEST(F32_GEMM_5X8__NEON_LD64, k_gt_2_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 3; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(5)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(5)
        .n(8)
        .k(k)
        .a_stride(7)
        .Test(xnn_f32_gemm_ukernel_5x8__neon_ld64);
    }
  }

  TEST(F32_GEMM_5X8__NEON_LD64, k_gt_2_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 3; k < 4; k++) {
      for (uint32_t m = 1; m <= 5; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(5)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_5x8__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_5X8__NEON_LD64, k_div_2) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 4; k <= 20; k += 2) {
      GemmMicrokernelTester()
        .mr(5)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(5)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_5x8__neon_ld64);
    }
  }

  TEST(F32_GEMM_5X8__NEON_LD64, k_div_2_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 4; k <= 20; k += 2) {
      GemmMicrokernelTester()
        .mr(5)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(5)
        .n(8)
        .k(k)
        .a_stride(23)
        .Test(xnn_f32_gemm_ukernel_5x8__neon_ld64);
    }
  }

  TEST(F32_GEMM_5X8__NEON_LD64, k_div_2_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 4; k <= 20; k += 2) {
      for (uint32_t m = 1; m <= 5; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(5)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_5x8__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_5X8__NEON_LD64, n_gt_8) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(5)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(5)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_5x8__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_5X8__NEON_LD64, n_gt_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(5)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(5)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_5x8__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_5X8__NEON_LD64, n_gt_8_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(5)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(5)
          .n(n)
          .k(k)
          .a_stride(13)
          .Test(xnn_f32_gemm_ukernel_5x8__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_5X8__NEON_LD64, n_gt_8_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        for (uint32_t m = 1; m <= 5; m++) {
          GemmMicrokernelTester()
            .mr(5)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_5x8__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_5X8__NEON_LD64, n_div_8) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(5)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(5)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_5x8__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_5X8__NEON_LD64, n_div_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(5)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(5)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_5x8__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_5X8__NEON_LD64, n_div_8_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(5)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(5)
          .n(n)
          .k(k)
          .a_stride(13)
          .Test(xnn_f32_gemm_ukernel_5x8__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_5X8__NEON_LD64, n_div_8_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        for (uint32_t m = 1; m <= 5; m++) {
          GemmMicrokernelTester()
            .mr(5)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_5x8__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_5X8__NEON_LD64, strided_cm_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 1; k <= 10; k += 3) {
      for (uint32_t m = 1; m <= 5; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(5)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_5x8__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_5X8__NEON_LD64, qmin) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(5)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(5)
      .n(8)
      .k(2)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_5x8__neon_ld64);
  }

  TEST(F32_GEMM_5X8__NEON_LD64, qmax) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(5)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(5)
      .n(8)
      .k(2)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_5x8__neon_ld64);
  }

  TEST(F32_GEMM_5X8__NEON_LD64, strided_cm) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(5)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(5)
      .n(8)
      .k(2)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_5x8__neon_ld64);
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64


#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(F32_GEMM_6X8__NEON_LD64, k_eq_2) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(2)
      .Test(xnn_f32_gemm_ukernel_6x8__neon_ld64);
  }

  TEST(F32_GEMM_6X8__NEON_LD64, strided_cn) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(2)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_6x8__neon_ld64);
  }

  TEST(F32_GEMM_6X8__NEON_LD64, k_eq_2_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(2)
      .a_stride(5)
      .Test(xnn_f32_gemm_ukernel_6x8__neon_ld64);
  }

  TEST(F32_GEMM_6X8__NEON_LD64, k_eq_2_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t m = 1; m <= 6; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(2)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_6x8__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_6X8__NEON_LD64, k_eq_2_subtile_m) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t m = 1; m <= 6; m++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(m)
        .n(8)
        .k(2)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_6x8__neon_ld64);
    }
  }

  TEST(F32_GEMM_6X8__NEON_LD64, k_eq_2_subtile_n) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(n)
        .k(2)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_6x8__neon_ld64);
    }
  }

  TEST(F32_GEMM_6X8__NEON_LD64, k_lt_2) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 1; k < 2; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_6x8__neon_ld64);
    }
  }

  TEST(F32_GEMM_6X8__NEON_LD64, k_lt_2_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 1; k < 2; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .a_stride(5)
        .Test(xnn_f32_gemm_ukernel_6x8__neon_ld64);
    }
  }

  TEST(F32_GEMM_6X8__NEON_LD64, k_lt_2_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 1; k < 2; k++) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__NEON_LD64, k_gt_2) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 3; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_6x8__neon_ld64);
    }
  }

  TEST(F32_GEMM_6X8__NEON_LD64, k_gt_2_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 3; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .a_stride(7)
        .Test(xnn_f32_gemm_ukernel_6x8__neon_ld64);
    }
  }

  TEST(F32_GEMM_6X8__NEON_LD64, k_gt_2_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 3; k < 4; k++) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__NEON_LD64, k_div_2) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 4; k <= 20; k += 2) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_6x8__neon_ld64);
    }
  }

  TEST(F32_GEMM_6X8__NEON_LD64, k_div_2_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 4; k <= 20; k += 2) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .a_stride(23)
        .Test(xnn_f32_gemm_ukernel_6x8__neon_ld64);
    }
  }

  TEST(F32_GEMM_6X8__NEON_LD64, k_div_2_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 4; k <= 20; k += 2) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__NEON_LD64, n_gt_8) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_6x8__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_6X8__NEON_LD64, n_gt_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_6x8__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_6X8__NEON_LD64, n_gt_8_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(n)
          .k(k)
          .a_stride(13)
          .Test(xnn_f32_gemm_ukernel_6x8__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_6X8__NEON_LD64, n_gt_8_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        for (uint32_t m = 1; m <= 6; m++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__NEON_LD64, n_div_8) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_6x8__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_6X8__NEON_LD64, n_div_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_6x8__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_6X8__NEON_LD64, n_div_8_strided_a) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(n)
          .k(k)
          .a_stride(13)
          .Test(xnn_f32_gemm_ukernel_6x8__neon_ld64);
      }
    }
  }

  TEST(F32_GEMM_6X8__NEON_LD64, n_div_8_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        for (uint32_t m = 1; m <= 6; m++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__NEON_LD64, strided_cm_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t k = 1; k <= 10; k += 3) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__neon_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__NEON_LD64, qmin) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(2)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_6x8__neon_ld64);
  }

  TEST(F32_GEMM_6X8__NEON_LD64, qmax) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(2)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_6x8__neon_ld64);
  }

  TEST(F32_GEMM_6X8__NEON_LD64, strided_cm) {
    TEST_REQUIRES_ARM_NEON;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(2)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_6x8__neon_ld64);
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64


#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(F32_GEMM_1X8__NEONFMA_LD64, k_eq_2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(2)
      .Test(xnn_f32_gemm_ukernel_1x8__neonfma_ld64);
  }

  TEST(F32_GEMM_1X8__NEONFMA_LD64, strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(2)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_1x8__neonfma_ld64);
  }

  TEST(F32_GEMM_1X8__NEONFMA_LD64, k_eq_2_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(2)
      .a_stride(5)
      .Test(xnn_f32_gemm_ukernel_1x8__neonfma_ld64);
  }

  TEST(F32_GEMM_1X8__NEONFMA_LD64, k_eq_2_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 1; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(2)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_1x8__neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_1X8__NEONFMA_LD64, k_eq_2_subtile_m) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 1; m++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(m)
        .n(8)
        .k(2)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_1x8__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_1X8__NEONFMA_LD64, k_eq_2_subtile_n) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(n)
        .k(2)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_1x8__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_1X8__NEONFMA_LD64, k_lt_2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 2; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_1x8__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_1X8__NEONFMA_LD64, k_lt_2_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 2; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .a_stride(5)
        .Test(xnn_f32_gemm_ukernel_1x8__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_1X8__NEONFMA_LD64, k_lt_2_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 2; k++) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__NEONFMA_LD64, k_gt_2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 3; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_1x8__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_1X8__NEONFMA_LD64, k_gt_2_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 3; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .a_stride(7)
        .Test(xnn_f32_gemm_ukernel_1x8__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_1X8__NEONFMA_LD64, k_gt_2_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 3; k < 4; k++) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__NEONFMA_LD64, k_div_2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 4; k <= 20; k += 2) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_1x8__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_1X8__NEONFMA_LD64, k_div_2_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 4; k <= 20; k += 2) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .a_stride(23)
        .Test(xnn_f32_gemm_ukernel_1x8__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_1X8__NEONFMA_LD64, k_div_2_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 4; k <= 20; k += 2) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__NEONFMA_LD64, n_gt_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_1x8__neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_1X8__NEONFMA_LD64, n_gt_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_1x8__neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_1X8__NEONFMA_LD64, n_gt_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(n)
          .k(k)
          .a_stride(13)
          .Test(xnn_f32_gemm_ukernel_1x8__neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_1X8__NEONFMA_LD64, n_gt_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        for (uint32_t m = 1; m <= 1; m++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__NEONFMA_LD64, n_div_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_1x8__neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_1X8__NEONFMA_LD64, n_div_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_1x8__neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_1X8__NEONFMA_LD64, n_div_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(n)
          .k(k)
          .a_stride(13)
          .Test(xnn_f32_gemm_ukernel_1x8__neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_1X8__NEONFMA_LD64, n_div_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        for (uint32_t m = 1; m <= 1; m++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__NEONFMA_LD64, strided_cm_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k <= 10; k += 3) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__NEONFMA_LD64, qmin) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(2)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_1x8__neonfma_ld64);
  }

  TEST(F32_GEMM_1X8__NEONFMA_LD64, qmax) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(2)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_1x8__neonfma_ld64);
  }

  TEST(F32_GEMM_1X8__NEONFMA_LD64, strided_cm) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(2)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_1x8__neonfma_ld64);
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64


#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(F32_GEMM_4X12__NEONFMA_LD64, k_eq_2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(12)
      .kr(1)
      .sr(1)
      .m(4)
      .n(12)
      .k(2)
      .Test(xnn_f32_gemm_ukernel_4x12__neonfma_ld64);
  }

  TEST(F32_GEMM_4X12__NEONFMA_LD64, strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(12)
      .kr(1)
      .sr(1)
      .m(4)
      .n(12)
      .k(2)
      .cn_stride(17)
      .Test(xnn_f32_gemm_ukernel_4x12__neonfma_ld64);
  }

  TEST(F32_GEMM_4X12__NEONFMA_LD64, k_eq_2_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(12)
      .kr(1)
      .sr(1)
      .m(4)
      .n(12)
      .k(2)
      .a_stride(5)
      .Test(xnn_f32_gemm_ukernel_4x12__neonfma_ld64);
  }

  TEST(F32_GEMM_4X12__NEONFMA_LD64, k_eq_2_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 4; m++) {
      for (uint32_t n = 1; n <= 12; n++) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(12)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(2)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_4x12__neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X12__NEONFMA_LD64, k_eq_2_subtile_m) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 4; m++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(12)
        .kr(1)
        .sr(1)
        .m(m)
        .n(12)
        .k(2)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x12__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_4X12__NEONFMA_LD64, k_eq_2_subtile_n) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 1; n <= 12; n++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(12)
        .kr(1)
        .sr(1)
        .m(4)
        .n(n)
        .k(2)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x12__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_4X12__NEONFMA_LD64, k_lt_2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 2; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(12)
        .kr(1)
        .sr(1)
        .m(4)
        .n(12)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x12__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_4X12__NEONFMA_LD64, k_lt_2_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 2; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(12)
        .kr(1)
        .sr(1)
        .m(4)
        .n(12)
        .k(k)
        .a_stride(5)
        .Test(xnn_f32_gemm_ukernel_4x12__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_4X12__NEONFMA_LD64, k_lt_2_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 2; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 12; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(12)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x12__neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X12__NEONFMA_LD64, k_gt_2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 3; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(12)
        .kr(1)
        .sr(1)
        .m(4)
        .n(12)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x12__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_4X12__NEONFMA_LD64, k_gt_2_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 3; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(12)
        .kr(1)
        .sr(1)
        .m(4)
        .n(12)
        .k(k)
        .a_stride(7)
        .Test(xnn_f32_gemm_ukernel_4x12__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_4X12__NEONFMA_LD64, k_gt_2_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 3; k < 4; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 12; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(12)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x12__neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X12__NEONFMA_LD64, k_div_2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 4; k <= 20; k += 2) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(12)
        .kr(1)
        .sr(1)
        .m(4)
        .n(12)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x12__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_4X12__NEONFMA_LD64, k_div_2_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 4; k <= 20; k += 2) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(12)
        .kr(1)
        .sr(1)
        .m(4)
        .n(12)
        .k(k)
        .a_stride(23)
        .Test(xnn_f32_gemm_ukernel_4x12__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_4X12__NEONFMA_LD64, k_div_2_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 4; k <= 20; k += 2) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 12; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(12)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x12__neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X12__NEONFMA_LD64, n_gt_12) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 13; n < 24; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(12)
          .kr(1)
          .sr(1)
          .m(4)
          .n(12)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x12__neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X12__NEONFMA_LD64, n_gt_12_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 13; n < 24; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(12)
          .kr(1)
          .sr(1)
          .m(4)
          .n(12)
          .k(k)
          .cn_stride(17)
          .Test(xnn_f32_gemm_ukernel_4x12__neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X12__NEONFMA_LD64, n_gt_12_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 13; n < 24; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(12)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(13)
          .Test(xnn_f32_gemm_ukernel_4x12__neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X12__NEONFMA_LD64, n_gt_12_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 13; n < 24; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(12)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x12__neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X12__NEONFMA_LD64, n_div_12) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 24; n <= 36; n += 12) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(12)
          .kr(1)
          .sr(1)
          .m(4)
          .n(12)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x12__neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X12__NEONFMA_LD64, n_div_12_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 24; n <= 36; n += 12) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(12)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .cn_stride(17)
          .Test(xnn_f32_gemm_ukernel_4x12__neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X12__NEONFMA_LD64, n_div_12_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 24; n <= 36; n += 12) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(12)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(13)
          .Test(xnn_f32_gemm_ukernel_4x12__neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X12__NEONFMA_LD64, n_div_12_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 24; n <= 36; n += 12) {
      for (size_t k = 1; k <= 10; k += 3) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(12)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x12__neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X12__NEONFMA_LD64, strided_cm_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k <= 10; k += 3) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 12; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(12)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(17)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x12__neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X12__NEONFMA_LD64, qmin) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(12)
      .kr(1)
      .sr(1)
      .m(4)
      .n(12)
      .k(2)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_4x12__neonfma_ld64);
  }

  TEST(F32_GEMM_4X12__NEONFMA_LD64, qmax) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(12)
      .kr(1)
      .sr(1)
      .m(4)
      .n(12)
      .k(2)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_4x12__neonfma_ld64);
  }

  TEST(F32_GEMM_4X12__NEONFMA_LD64, strided_cm) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(12)
      .kr(1)
      .sr(1)
      .m(4)
      .n(12)
      .k(2)
      .cm_stride(17)
      .Test(xnn_f32_gemm_ukernel_4x12__neonfma_ld64);
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64


#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(F32_GEMM_4X8__NEONFMA_LD64, k_eq_2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(2)
      .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld64);
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD64, strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(2)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld64);
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD64, k_eq_2_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(2)
      .a_stride(5)
      .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld64);
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD64, k_eq_2_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 4; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(2)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD64, k_eq_2_subtile_m) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 4; m++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(m)
        .n(8)
        .k(2)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD64, k_eq_2_subtile_n) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(n)
        .k(2)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD64, k_lt_2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 2; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD64, k_lt_2_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 2; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(5)
        .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD64, k_lt_2_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 2; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD64, k_gt_2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 3; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD64, k_gt_2_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 3; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(7)
        .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD64, k_gt_2_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 3; k < 4; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD64, k_div_2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 4; k <= 20; k += 2) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD64, k_div_2_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 4; k <= 20; k += 2) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(23)
        .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD64, k_div_2_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 4; k <= 20; k += 2) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD64, n_gt_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD64, n_gt_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD64, n_gt_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(13)
          .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD64, n_gt_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD64, n_div_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD64, n_div_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD64, n_div_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(13)
          .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD64, n_div_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD64, strided_cm_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k <= 10; k += 3) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD64, qmin) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(2)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld64);
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD64, qmax) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(2)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld64);
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD64, strided_cm) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(2)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld64);
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64


#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(F32_GEMM_4X8__NEONFMA_LD128, k_eq_4) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(4)
      .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld128);
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD128, strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(4)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld128);
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD128, k_eq_4_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(4)
      .a_stride(7)
      .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld128);
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD128, k_eq_4_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 4; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(4)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld128);
      }
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD128, k_eq_4_subtile_m) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 4; m++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(m)
        .n(8)
        .k(4)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld128);
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD128, k_eq_4_subtile_n) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(n)
        .k(4)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld128);
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD128, k_lt_4) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld128);
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD128, k_lt_4_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(7)
        .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld128);
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD128, k_lt_4_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 4; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld128);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD128, k_gt_4) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 5; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld128);
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD128, k_gt_4_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 5; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(11)
        .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld128);
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD128, k_gt_4_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 5; k < 8; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld128);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD128, k_div_4) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 8; k <= 40; k += 4) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld128);
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD128, k_div_4_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 8; k <= 40; k += 4) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(43)
        .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld128);
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD128, k_div_4_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 8; k <= 40; k += 4) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld128);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD128, n_gt_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld128);
      }
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD128, n_gt_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld128);
      }
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD128, n_gt_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(23)
          .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld128);
      }
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD128, n_gt_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld128);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD128, n_div_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld128);
      }
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD128, n_div_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld128);
      }
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD128, n_div_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(23)
          .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld128);
      }
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD128, n_div_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld128);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD128, strided_cm_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k <= 20; k += 5) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld128);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD128, qmin) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(4)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld128);
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD128, qmax) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(4)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld128);
  }

  TEST(F32_GEMM_4X8__NEONFMA_LD128, strided_cm) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(4)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_4x8__neonfma_ld128);
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64


#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(F32_GEMM_5X8__NEONFMA_LD64, k_eq_2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(5)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(5)
      .n(8)
      .k(2)
      .Test(xnn_f32_gemm_ukernel_5x8__neonfma_ld64);
  }

  TEST(F32_GEMM_5X8__NEONFMA_LD64, strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(5)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(5)
      .n(8)
      .k(2)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_5x8__neonfma_ld64);
  }

  TEST(F32_GEMM_5X8__NEONFMA_LD64, k_eq_2_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(5)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(5)
      .n(8)
      .k(2)
      .a_stride(5)
      .Test(xnn_f32_gemm_ukernel_5x8__neonfma_ld64);
  }

  TEST(F32_GEMM_5X8__NEONFMA_LD64, k_eq_2_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 5; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(5)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(2)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_5x8__neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_5X8__NEONFMA_LD64, k_eq_2_subtile_m) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 5; m++) {
      GemmMicrokernelTester()
        .mr(5)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(m)
        .n(8)
        .k(2)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_5x8__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_5X8__NEONFMA_LD64, k_eq_2_subtile_n) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(5)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(5)
        .n(n)
        .k(2)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_5x8__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_5X8__NEONFMA_LD64, k_lt_2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 2; k++) {
      GemmMicrokernelTester()
        .mr(5)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(5)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_5x8__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_5X8__NEONFMA_LD64, k_lt_2_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 2; k++) {
      GemmMicrokernelTester()
        .mr(5)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(5)
        .n(8)
        .k(k)
        .a_stride(5)
        .Test(xnn_f32_gemm_ukernel_5x8__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_5X8__NEONFMA_LD64, k_lt_2_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 2; k++) {
      for (uint32_t m = 1; m <= 5; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(5)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_5x8__neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_5X8__NEONFMA_LD64, k_gt_2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 3; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(5)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(5)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_5x8__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_5X8__NEONFMA_LD64, k_gt_2_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 3; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(5)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(5)
        .n(8)
        .k(k)
        .a_stride(7)
        .Test(xnn_f32_gemm_ukernel_5x8__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_5X8__NEONFMA_LD64, k_gt_2_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 3; k < 4; k++) {
      for (uint32_t m = 1; m <= 5; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(5)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_5x8__neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_5X8__NEONFMA_LD64, k_div_2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 4; k <= 20; k += 2) {
      GemmMicrokernelTester()
        .mr(5)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(5)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_5x8__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_5X8__NEONFMA_LD64, k_div_2_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 4; k <= 20; k += 2) {
      GemmMicrokernelTester()
        .mr(5)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(5)
        .n(8)
        .k(k)
        .a_stride(23)
        .Test(xnn_f32_gemm_ukernel_5x8__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_5X8__NEONFMA_LD64, k_div_2_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 4; k <= 20; k += 2) {
      for (uint32_t m = 1; m <= 5; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(5)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_5x8__neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_5X8__NEONFMA_LD64, n_gt_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(5)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(5)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_5x8__neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_5X8__NEONFMA_LD64, n_gt_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(5)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(5)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_5x8__neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_5X8__NEONFMA_LD64, n_gt_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(5)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(5)
          .n(n)
          .k(k)
          .a_stride(13)
          .Test(xnn_f32_gemm_ukernel_5x8__neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_5X8__NEONFMA_LD64, n_gt_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        for (uint32_t m = 1; m <= 5; m++) {
          GemmMicrokernelTester()
            .mr(5)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_5x8__neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_5X8__NEONFMA_LD64, n_div_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(5)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(5)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_5x8__neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_5X8__NEONFMA_LD64, n_div_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(5)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(5)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_5x8__neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_5X8__NEONFMA_LD64, n_div_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(5)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(5)
          .n(n)
          .k(k)
          .a_stride(13)
          .Test(xnn_f32_gemm_ukernel_5x8__neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_5X8__NEONFMA_LD64, n_div_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        for (uint32_t m = 1; m <= 5; m++) {
          GemmMicrokernelTester()
            .mr(5)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_5x8__neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_5X8__NEONFMA_LD64, strided_cm_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k <= 10; k += 3) {
      for (uint32_t m = 1; m <= 5; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(5)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_5x8__neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_5X8__NEONFMA_LD64, qmin) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(5)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(5)
      .n(8)
      .k(2)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_5x8__neonfma_ld64);
  }

  TEST(F32_GEMM_5X8__NEONFMA_LD64, qmax) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(5)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(5)
      .n(8)
      .k(2)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_5x8__neonfma_ld64);
  }

  TEST(F32_GEMM_5X8__NEONFMA_LD64, strided_cm) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(5)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(5)
      .n(8)
      .k(2)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_5x8__neonfma_ld64);
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64


#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(F32_GEMM_6X8__NEONFMA_LD64, k_eq_2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(2)
      .Test(xnn_f32_gemm_ukernel_6x8__neonfma_ld64);
  }

  TEST(F32_GEMM_6X8__NEONFMA_LD64, strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(2)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_6x8__neonfma_ld64);
  }

  TEST(F32_GEMM_6X8__NEONFMA_LD64, k_eq_2_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(2)
      .a_stride(5)
      .Test(xnn_f32_gemm_ukernel_6x8__neonfma_ld64);
  }

  TEST(F32_GEMM_6X8__NEONFMA_LD64, k_eq_2_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 6; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(2)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_6x8__neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_6X8__NEONFMA_LD64, k_eq_2_subtile_m) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t m = 1; m <= 6; m++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(m)
        .n(8)
        .k(2)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_6x8__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_6X8__NEONFMA_LD64, k_eq_2_subtile_n) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(n)
        .k(2)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_6x8__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_6X8__NEONFMA_LD64, k_lt_2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 2; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_6x8__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_6X8__NEONFMA_LD64, k_lt_2_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 2; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .a_stride(5)
        .Test(xnn_f32_gemm_ukernel_6x8__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_6X8__NEONFMA_LD64, k_lt_2_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k < 2; k++) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__NEONFMA_LD64, k_gt_2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 3; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_6x8__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_6X8__NEONFMA_LD64, k_gt_2_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 3; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .a_stride(7)
        .Test(xnn_f32_gemm_ukernel_6x8__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_6X8__NEONFMA_LD64, k_gt_2_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 3; k < 4; k++) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__NEONFMA_LD64, k_div_2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 4; k <= 20; k += 2) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_6x8__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_6X8__NEONFMA_LD64, k_div_2_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 4; k <= 20; k += 2) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .a_stride(23)
        .Test(xnn_f32_gemm_ukernel_6x8__neonfma_ld64);
    }
  }

  TEST(F32_GEMM_6X8__NEONFMA_LD64, k_div_2_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 4; k <= 20; k += 2) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__NEONFMA_LD64, n_gt_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_6x8__neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_6X8__NEONFMA_LD64, n_gt_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_6x8__neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_6X8__NEONFMA_LD64, n_gt_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(n)
          .k(k)
          .a_stride(13)
          .Test(xnn_f32_gemm_ukernel_6x8__neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_6X8__NEONFMA_LD64, n_gt_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 10; k += 3) {
        for (uint32_t m = 1; m <= 6; m++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__NEONFMA_LD64, n_div_8) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_6x8__neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_6X8__NEONFMA_LD64, n_div_8_strided_cn) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_6x8__neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_6X8__NEONFMA_LD64, n_div_8_strided_a) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(n)
          .k(k)
          .a_stride(13)
          .Test(xnn_f32_gemm_ukernel_6x8__neonfma_ld64);
      }
    }
  }

  TEST(F32_GEMM_6X8__NEONFMA_LD64, n_div_8_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 10; k += 3) {
        for (uint32_t m = 1; m <= 6; m++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__NEONFMA_LD64, strided_cm_subtile) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t k = 1; k <= 10; k += 3) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__neonfma_ld64);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__NEONFMA_LD64, qmin) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(2)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_6x8__neonfma_ld64);
  }

  TEST(F32_GEMM_6X8__NEONFMA_LD64, qmax) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(2)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_6x8__neonfma_ld64);
  }

  TEST(F32_GEMM_6X8__NEONFMA_LD64, strided_cm) {
    TEST_REQUIRES_ARM_NEON_FMA;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(2)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_6x8__neonfma_ld64);
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64


#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  TEST(F32_GEMM_1X8__SSE_LOAD1, k_eq_1) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(1)
      .Test(xnn_f32_gemm_ukernel_1x8__sse_load1);
  }

  TEST(F32_GEMM_1X8__SSE_LOAD1, strided_cn) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(1)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_1x8__sse_load1);
  }

  TEST(F32_GEMM_1X8__SSE_LOAD1, k_eq_1_strided_a) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(1)
      .a_stride(3)
      .Test(xnn_f32_gemm_ukernel_1x8__sse_load1);
  }

  TEST(F32_GEMM_1X8__SSE_LOAD1, k_eq_1_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t m = 1; m <= 1; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(1)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_1x8__sse_load1);
      }
    }
  }

  TEST(F32_GEMM_1X8__SSE_LOAD1, k_eq_1_subtile_m) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t m = 1; m <= 1; m++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(m)
        .n(8)
        .k(1)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_1x8__sse_load1);
    }
  }

  TEST(F32_GEMM_1X8__SSE_LOAD1, k_eq_1_subtile_n) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(n)
        .k(1)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_1x8__sse_load1);
    }
  }

  TEST(F32_GEMM_1X8__SSE_LOAD1, k_gt_1) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 2; k < 10; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_1x8__sse_load1);
    }
  }

  TEST(F32_GEMM_1X8__SSE_LOAD1, k_gt_1_strided_a) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 2; k < 10; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .a_stride(11)
        .Test(xnn_f32_gemm_ukernel_1x8__sse_load1);
    }
  }

  TEST(F32_GEMM_1X8__SSE_LOAD1, k_gt_1_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 2; k < 10; k++) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__sse_load1);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__SSE_LOAD1, n_gt_8) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 5; k += 2) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_1x8__sse_load1);
      }
    }
  }

  TEST(F32_GEMM_1X8__SSE_LOAD1, n_gt_8_strided_cn) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 5; k += 2) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_1x8__sse_load1);
      }
    }
  }

  TEST(F32_GEMM_1X8__SSE_LOAD1, n_gt_8_strided_a) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 5; k += 2) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(n)
          .k(k)
          .a_stride(7)
          .Test(xnn_f32_gemm_ukernel_1x8__sse_load1);
      }
    }
  }

  TEST(F32_GEMM_1X8__SSE_LOAD1, n_gt_8_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 5; k += 2) {
        for (uint32_t m = 1; m <= 1; m++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__sse_load1);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__SSE_LOAD1, n_div_8) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 5; k += 2) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_1x8__sse_load1);
      }
    }
  }

  TEST(F32_GEMM_1X8__SSE_LOAD1, n_div_8_strided_cn) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 5; k += 2) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_1x8__sse_load1);
      }
    }
  }

  TEST(F32_GEMM_1X8__SSE_LOAD1, n_div_8_strided_a) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 5; k += 2) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(n)
          .k(k)
          .a_stride(7)
          .Test(xnn_f32_gemm_ukernel_1x8__sse_load1);
      }
    }
  }

  TEST(F32_GEMM_1X8__SSE_LOAD1, n_div_8_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 5; k += 2) {
        for (uint32_t m = 1; m <= 1; m++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__sse_load1);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__SSE_LOAD1, strided_cm_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 1; k <= 5; k += 2) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__sse_load1);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__SSE_LOAD1, qmin) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(1)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_1x8__sse_load1);
  }

  TEST(F32_GEMM_1X8__SSE_LOAD1, qmax) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(1)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_1x8__sse_load1);
  }

  TEST(F32_GEMM_1X8__SSE_LOAD1, strided_cm) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(1)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_1x8__sse_load1);
  }
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64


#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  TEST(F32_GEMM_4X8__SSE_LOAD1, k_eq_1) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(1)
      .Test(xnn_f32_gemm_ukernel_4x8__sse_load1);
  }

  TEST(F32_GEMM_4X8__SSE_LOAD1, strided_cn) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(1)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_4x8__sse_load1);
  }

  TEST(F32_GEMM_4X8__SSE_LOAD1, k_eq_1_strided_a) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(1)
      .a_stride(3)
      .Test(xnn_f32_gemm_ukernel_4x8__sse_load1);
  }

  TEST(F32_GEMM_4X8__SSE_LOAD1, k_eq_1_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t m = 1; m <= 4; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(1)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_4x8__sse_load1);
      }
    }
  }

  TEST(F32_GEMM_4X8__SSE_LOAD1, k_eq_1_subtile_m) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t m = 1; m <= 4; m++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(m)
        .n(8)
        .k(1)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x8__sse_load1);
    }
  }

  TEST(F32_GEMM_4X8__SSE_LOAD1, k_eq_1_subtile_n) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(n)
        .k(1)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x8__sse_load1);
    }
  }

  TEST(F32_GEMM_4X8__SSE_LOAD1, k_gt_1) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 2; k < 10; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8__sse_load1);
    }
  }

  TEST(F32_GEMM_4X8__SSE_LOAD1, k_gt_1_strided_a) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 2; k < 10; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(11)
        .Test(xnn_f32_gemm_ukernel_4x8__sse_load1);
    }
  }

  TEST(F32_GEMM_4X8__SSE_LOAD1, k_gt_1_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 2; k < 10; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__sse_load1);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__SSE_LOAD1, n_gt_8) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 5; k += 2) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x8__sse_load1);
      }
    }
  }

  TEST(F32_GEMM_4X8__SSE_LOAD1, n_gt_8_strided_cn) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 5; k += 2) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_4x8__sse_load1);
      }
    }
  }

  TEST(F32_GEMM_4X8__SSE_LOAD1, n_gt_8_strided_a) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 5; k += 2) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(7)
          .Test(xnn_f32_gemm_ukernel_4x8__sse_load1);
      }
    }
  }

  TEST(F32_GEMM_4X8__SSE_LOAD1, n_gt_8_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 5; k += 2) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__sse_load1);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__SSE_LOAD1, n_div_8) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 5; k += 2) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x8__sse_load1);
      }
    }
  }

  TEST(F32_GEMM_4X8__SSE_LOAD1, n_div_8_strided_cn) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 5; k += 2) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_4x8__sse_load1);
      }
    }
  }

  TEST(F32_GEMM_4X8__SSE_LOAD1, n_div_8_strided_a) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 5; k += 2) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(7)
          .Test(xnn_f32_gemm_ukernel_4x8__sse_load1);
      }
    }
  }

  TEST(F32_GEMM_4X8__SSE_LOAD1, n_div_8_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 5; k += 2) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__sse_load1);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__SSE_LOAD1, strided_cm_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 1; k <= 5; k += 2) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__sse_load1);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__SSE_LOAD1, qmin) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(1)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_4x8__sse_load1);
  }

  TEST(F32_GEMM_4X8__SSE_LOAD1, qmax) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(1)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_4x8__sse_load1);
  }

  TEST(F32_GEMM_4X8__SSE_LOAD1, strided_cm) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(1)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_4x8__sse_load1);
  }
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64


#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  TEST(F32_GEMM_1X8__SSE_DUP, k_eq_4) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(4)
      .Test(xnn_f32_gemm_ukernel_1x8__sse_dup);
  }

  TEST(F32_GEMM_1X8__SSE_DUP, strided_cn) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(4)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_1x8__sse_dup);
  }

  TEST(F32_GEMM_1X8__SSE_DUP, k_eq_4_strided_a) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(4)
      .a_stride(7)
      .Test(xnn_f32_gemm_ukernel_1x8__sse_dup);
  }

  TEST(F32_GEMM_1X8__SSE_DUP, k_eq_4_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t m = 1; m <= 1; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(4)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_1x8__sse_dup);
      }
    }
  }

  TEST(F32_GEMM_1X8__SSE_DUP, k_eq_4_subtile_m) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t m = 1; m <= 1; m++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(m)
        .n(8)
        .k(4)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_1x8__sse_dup);
    }
  }

  TEST(F32_GEMM_1X8__SSE_DUP, k_eq_4_subtile_n) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(n)
        .k(4)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_1x8__sse_dup);
    }
  }

  TEST(F32_GEMM_1X8__SSE_DUP, k_lt_4) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 1; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_1x8__sse_dup);
    }
  }

  TEST(F32_GEMM_1X8__SSE_DUP, k_lt_4_strided_a) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 1; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .a_stride(7)
        .Test(xnn_f32_gemm_ukernel_1x8__sse_dup);
    }
  }

  TEST(F32_GEMM_1X8__SSE_DUP, k_lt_4_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 1; k < 4; k++) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__sse_dup);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__SSE_DUP, k_gt_4) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 5; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_1x8__sse_dup);
    }
  }

  TEST(F32_GEMM_1X8__SSE_DUP, k_gt_4_strided_a) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 5; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .a_stride(11)
        .Test(xnn_f32_gemm_ukernel_1x8__sse_dup);
    }
  }

  TEST(F32_GEMM_1X8__SSE_DUP, k_gt_4_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 5; k < 8; k++) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__sse_dup);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__SSE_DUP, k_div_4) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 8; k <= 40; k += 4) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_1x8__sse_dup);
    }
  }

  TEST(F32_GEMM_1X8__SSE_DUP, k_div_4_strided_a) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 8; k <= 40; k += 4) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .a_stride(43)
        .Test(xnn_f32_gemm_ukernel_1x8__sse_dup);
    }
  }

  TEST(F32_GEMM_1X8__SSE_DUP, k_div_4_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 8; k <= 40; k += 4) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__sse_dup);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__SSE_DUP, n_gt_8) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_1x8__sse_dup);
      }
    }
  }

  TEST(F32_GEMM_1X8__SSE_DUP, n_gt_8_strided_cn) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_1x8__sse_dup);
      }
    }
  }

  TEST(F32_GEMM_1X8__SSE_DUP, n_gt_8_strided_a) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(n)
          .k(k)
          .a_stride(23)
          .Test(xnn_f32_gemm_ukernel_1x8__sse_dup);
      }
    }
  }

  TEST(F32_GEMM_1X8__SSE_DUP, n_gt_8_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        for (uint32_t m = 1; m <= 1; m++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__sse_dup);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__SSE_DUP, n_div_8) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_1x8__sse_dup);
      }
    }
  }

  TEST(F32_GEMM_1X8__SSE_DUP, n_div_8_strided_cn) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_1x8__sse_dup);
      }
    }
  }

  TEST(F32_GEMM_1X8__SSE_DUP, n_div_8_strided_a) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(n)
          .k(k)
          .a_stride(23)
          .Test(xnn_f32_gemm_ukernel_1x8__sse_dup);
      }
    }
  }

  TEST(F32_GEMM_1X8__SSE_DUP, n_div_8_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        for (uint32_t m = 1; m <= 1; m++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__sse_dup);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__SSE_DUP, strided_cm_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 1; k <= 20; k += 5) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__sse_dup);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__SSE_DUP, qmin) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(4)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_1x8__sse_dup);
  }

  TEST(F32_GEMM_1X8__SSE_DUP, qmax) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(4)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_1x8__sse_dup);
  }

  TEST(F32_GEMM_1X8__SSE_DUP, strided_cm) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(4)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_1x8__sse_dup);
  }
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64


#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  TEST(F32_GEMM_4X8__SSE_DUP, k_eq_4) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(4)
      .Test(xnn_f32_gemm_ukernel_4x8__sse_dup);
  }

  TEST(F32_GEMM_4X8__SSE_DUP, strided_cn) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(4)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_4x8__sse_dup);
  }

  TEST(F32_GEMM_4X8__SSE_DUP, k_eq_4_strided_a) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(4)
      .a_stride(7)
      .Test(xnn_f32_gemm_ukernel_4x8__sse_dup);
  }

  TEST(F32_GEMM_4X8__SSE_DUP, k_eq_4_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t m = 1; m <= 4; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(4)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_4x8__sse_dup);
      }
    }
  }

  TEST(F32_GEMM_4X8__SSE_DUP, k_eq_4_subtile_m) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t m = 1; m <= 4; m++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(m)
        .n(8)
        .k(4)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x8__sse_dup);
    }
  }

  TEST(F32_GEMM_4X8__SSE_DUP, k_eq_4_subtile_n) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(n)
        .k(4)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x8__sse_dup);
    }
  }

  TEST(F32_GEMM_4X8__SSE_DUP, k_lt_4) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 1; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8__sse_dup);
    }
  }

  TEST(F32_GEMM_4X8__SSE_DUP, k_lt_4_strided_a) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 1; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(7)
        .Test(xnn_f32_gemm_ukernel_4x8__sse_dup);
    }
  }

  TEST(F32_GEMM_4X8__SSE_DUP, k_lt_4_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 1; k < 4; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__sse_dup);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__SSE_DUP, k_gt_4) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 5; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8__sse_dup);
    }
  }

  TEST(F32_GEMM_4X8__SSE_DUP, k_gt_4_strided_a) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 5; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(11)
        .Test(xnn_f32_gemm_ukernel_4x8__sse_dup);
    }
  }

  TEST(F32_GEMM_4X8__SSE_DUP, k_gt_4_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 5; k < 8; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__sse_dup);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__SSE_DUP, k_div_4) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 8; k <= 40; k += 4) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8__sse_dup);
    }
  }

  TEST(F32_GEMM_4X8__SSE_DUP, k_div_4_strided_a) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 8; k <= 40; k += 4) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(43)
        .Test(xnn_f32_gemm_ukernel_4x8__sse_dup);
    }
  }

  TEST(F32_GEMM_4X8__SSE_DUP, k_div_4_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 8; k <= 40; k += 4) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__sse_dup);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__SSE_DUP, n_gt_8) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x8__sse_dup);
      }
    }
  }

  TEST(F32_GEMM_4X8__SSE_DUP, n_gt_8_strided_cn) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_4x8__sse_dup);
      }
    }
  }

  TEST(F32_GEMM_4X8__SSE_DUP, n_gt_8_strided_a) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(23)
          .Test(xnn_f32_gemm_ukernel_4x8__sse_dup);
      }
    }
  }

  TEST(F32_GEMM_4X8__SSE_DUP, n_gt_8_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__sse_dup);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__SSE_DUP, n_div_8) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x8__sse_dup);
      }
    }
  }

  TEST(F32_GEMM_4X8__SSE_DUP, n_div_8_strided_cn) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_4x8__sse_dup);
      }
    }
  }

  TEST(F32_GEMM_4X8__SSE_DUP, n_div_8_strided_a) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(23)
          .Test(xnn_f32_gemm_ukernel_4x8__sse_dup);
      }
    }
  }

  TEST(F32_GEMM_4X8__SSE_DUP, n_div_8_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__sse_dup);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__SSE_DUP, strided_cm_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 1; k <= 20; k += 5) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__sse_dup);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__SSE_DUP, qmin) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(4)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_4x8__sse_dup);
  }

  TEST(F32_GEMM_4X8__SSE_DUP, qmax) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(4)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_4x8__sse_dup);
  }

  TEST(F32_GEMM_4X8__SSE_DUP, strided_cm) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(4)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_4x8__sse_dup);
  }
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64


#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  TEST(F32_GEMM_1X8S4__SSE, k_eq_4) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(4)
      .m(1)
      .n(8)
      .k(4)
      .Test(xnn_f32_gemm_ukernel_1x8s4__sse);
  }

  TEST(F32_GEMM_1X8S4__SSE, strided_cn) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(4)
      .m(1)
      .n(8)
      .k(4)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_1x8s4__sse);
  }

  TEST(F32_GEMM_1X8S4__SSE, k_eq_4_strided_a) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(4)
      .m(1)
      .n(8)
      .k(4)
      .a_stride(7)
      .Test(xnn_f32_gemm_ukernel_1x8s4__sse);
  }

  TEST(F32_GEMM_1X8S4__SSE, k_eq_4_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t m = 1; m <= 1; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(4)
          .m(m)
          .n(n)
          .k(4)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_1x8s4__sse);
      }
    }
  }

  TEST(F32_GEMM_1X8S4__SSE, k_eq_4_subtile_m) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t m = 1; m <= 1; m++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(m)
        .n(8)
        .k(4)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_1x8s4__sse);
    }
  }

  TEST(F32_GEMM_1X8S4__SSE, k_eq_4_subtile_n) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(1)
        .n(n)
        .k(4)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_1x8s4__sse);
    }
  }

  TEST(F32_GEMM_1X8S4__SSE, k_lt_4) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 1; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(1)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_1x8s4__sse);
    }
  }

  TEST(F32_GEMM_1X8S4__SSE, k_lt_4_strided_a) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 1; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(1)
        .n(8)
        .k(k)
        .a_stride(7)
        .Test(xnn_f32_gemm_ukernel_1x8s4__sse);
    }
  }

  TEST(F32_GEMM_1X8S4__SSE, k_lt_4_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 1; k < 4; k++) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(4)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8s4__sse);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8S4__SSE, k_gt_4) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 5; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(1)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_1x8s4__sse);
    }
  }

  TEST(F32_GEMM_1X8S4__SSE, k_gt_4_strided_a) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 5; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(1)
        .n(8)
        .k(k)
        .a_stride(11)
        .Test(xnn_f32_gemm_ukernel_1x8s4__sse);
    }
  }

  TEST(F32_GEMM_1X8S4__SSE, k_gt_4_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 5; k < 8; k++) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(4)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8s4__sse);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8S4__SSE, k_div_4) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 8; k <= 40; k += 4) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(1)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_1x8s4__sse);
    }
  }

  TEST(F32_GEMM_1X8S4__SSE, k_div_4_strided_a) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 8; k <= 40; k += 4) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(1)
        .n(8)
        .k(k)
        .a_stride(43)
        .Test(xnn_f32_gemm_ukernel_1x8s4__sse);
    }
  }

  TEST(F32_GEMM_1X8S4__SSE, k_div_4_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 8; k <= 40; k += 4) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(4)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8s4__sse);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8S4__SSE, n_gt_8) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(4)
          .m(1)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_1x8s4__sse);
      }
    }
  }

  TEST(F32_GEMM_1X8S4__SSE, n_gt_8_strided_cn) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(4)
          .m(1)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_1x8s4__sse);
      }
    }
  }

  TEST(F32_GEMM_1X8S4__SSE, n_gt_8_strided_a) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(4)
          .m(1)
          .n(n)
          .k(k)
          .a_stride(23)
          .Test(xnn_f32_gemm_ukernel_1x8s4__sse);
      }
    }
  }

  TEST(F32_GEMM_1X8S4__SSE, n_gt_8_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        for (uint32_t m = 1; m <= 1; m++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(4)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8s4__sse);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8S4__SSE, n_div_8) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(4)
          .m(1)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_1x8s4__sse);
      }
    }
  }

  TEST(F32_GEMM_1X8S4__SSE, n_div_8_strided_cn) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(4)
          .m(1)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_1x8s4__sse);
      }
    }
  }

  TEST(F32_GEMM_1X8S4__SSE, n_div_8_strided_a) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(4)
          .m(1)
          .n(n)
          .k(k)
          .a_stride(23)
          .Test(xnn_f32_gemm_ukernel_1x8s4__sse);
      }
    }
  }

  TEST(F32_GEMM_1X8S4__SSE, n_div_8_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        for (uint32_t m = 1; m <= 1; m++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(4)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8s4__sse);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8S4__SSE, strided_cm_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 1; k <= 20; k += 5) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(4)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8s4__sse);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8S4__SSE, qmin) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(4)
      .m(1)
      .n(8)
      .k(4)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_1x8s4__sse);
  }

  TEST(F32_GEMM_1X8S4__SSE, qmax) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(4)
      .m(1)
      .n(8)
      .k(4)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_1x8s4__sse);
  }

  TEST(F32_GEMM_1X8S4__SSE, strided_cm) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(4)
      .m(1)
      .n(8)
      .k(4)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_1x8s4__sse);
  }
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64


#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  TEST(F32_GEMM_4X8S4__SSE, k_eq_4) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(4)
      .m(4)
      .n(8)
      .k(4)
      .Test(xnn_f32_gemm_ukernel_4x8s4__sse);
  }

  TEST(F32_GEMM_4X8S4__SSE, strided_cn) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(4)
      .m(4)
      .n(8)
      .k(4)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_4x8s4__sse);
  }

  TEST(F32_GEMM_4X8S4__SSE, k_eq_4_strided_a) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(4)
      .m(4)
      .n(8)
      .k(4)
      .a_stride(7)
      .Test(xnn_f32_gemm_ukernel_4x8s4__sse);
  }

  TEST(F32_GEMM_4X8S4__SSE, k_eq_4_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t m = 1; m <= 4; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(4)
          .m(m)
          .n(n)
          .k(4)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_4x8s4__sse);
      }
    }
  }

  TEST(F32_GEMM_4X8S4__SSE, k_eq_4_subtile_m) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t m = 1; m <= 4; m++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(m)
        .n(8)
        .k(4)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x8s4__sse);
    }
  }

  TEST(F32_GEMM_4X8S4__SSE, k_eq_4_subtile_n) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(4)
        .n(n)
        .k(4)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x8s4__sse);
    }
  }

  TEST(F32_GEMM_4X8S4__SSE, k_lt_4) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 1; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8s4__sse);
    }
  }

  TEST(F32_GEMM_4X8S4__SSE, k_lt_4_strided_a) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 1; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(7)
        .Test(xnn_f32_gemm_ukernel_4x8s4__sse);
    }
  }

  TEST(F32_GEMM_4X8S4__SSE, k_lt_4_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 1; k < 4; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(4)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8s4__sse);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8S4__SSE, k_gt_4) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 5; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8s4__sse);
    }
  }

  TEST(F32_GEMM_4X8S4__SSE, k_gt_4_strided_a) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 5; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(11)
        .Test(xnn_f32_gemm_ukernel_4x8s4__sse);
    }
  }

  TEST(F32_GEMM_4X8S4__SSE, k_gt_4_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 5; k < 8; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(4)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8s4__sse);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8S4__SSE, k_div_4) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 8; k <= 40; k += 4) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8s4__sse);
    }
  }

  TEST(F32_GEMM_4X8S4__SSE, k_div_4_strided_a) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 8; k <= 40; k += 4) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(43)
        .Test(xnn_f32_gemm_ukernel_4x8s4__sse);
    }
  }

  TEST(F32_GEMM_4X8S4__SSE, k_div_4_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 8; k <= 40; k += 4) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(4)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8s4__sse);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8S4__SSE, n_gt_8) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(4)
          .m(4)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x8s4__sse);
      }
    }
  }

  TEST(F32_GEMM_4X8S4__SSE, n_gt_8_strided_cn) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(4)
          .m(4)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_4x8s4__sse);
      }
    }
  }

  TEST(F32_GEMM_4X8S4__SSE, n_gt_8_strided_a) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(4)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(23)
          .Test(xnn_f32_gemm_ukernel_4x8s4__sse);
      }
    }
  }

  TEST(F32_GEMM_4X8S4__SSE, n_gt_8_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(4)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8s4__sse);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8S4__SSE, n_div_8) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(4)
          .m(4)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x8s4__sse);
      }
    }
  }

  TEST(F32_GEMM_4X8S4__SSE, n_div_8_strided_cn) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(4)
          .m(4)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_4x8s4__sse);
      }
    }
  }

  TEST(F32_GEMM_4X8S4__SSE, n_div_8_strided_a) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(4)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(23)
          .Test(xnn_f32_gemm_ukernel_4x8s4__sse);
      }
    }
  }

  TEST(F32_GEMM_4X8S4__SSE, n_div_8_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(4)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8s4__sse);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8S4__SSE, strided_cm_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t k = 1; k <= 20; k += 5) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(4)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8s4__sse);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8S4__SSE, qmin) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(4)
      .m(4)
      .n(8)
      .k(4)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_4x8s4__sse);
  }

  TEST(F32_GEMM_4X8S4__SSE, qmax) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(4)
      .m(4)
      .n(8)
      .k(4)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_4x8s4__sse);
  }

  TEST(F32_GEMM_4X8S4__SSE, strided_cm) {
    TEST_REQUIRES_X86_SSE;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(4)
      .m(4)
      .n(8)
      .k(4)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_4x8s4__sse);
  }
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64


#if !XNN_ARCH_ASMJS && !XNN_ARCH_WASM
  TEST(F32_GEMM_1X8__PSIMD_LOADSPLAT, k_eq_1) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(1)
      .Test(xnn_f32_gemm_ukernel_1x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_1X8__PSIMD_LOADSPLAT, strided_cn) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(1)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_1x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_1X8__PSIMD_LOADSPLAT, k_eq_1_strided_a) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(1)
      .a_stride(3)
      .Test(xnn_f32_gemm_ukernel_1x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_1X8__PSIMD_LOADSPLAT, k_eq_1_subtile) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t m = 1; m <= 1; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(1)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_1x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_LOADSPLAT, k_eq_1_subtile_m) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t m = 1; m <= 1; m++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(m)
        .n(8)
        .k(1)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_1x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_LOADSPLAT, k_eq_1_subtile_n) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(n)
        .k(1)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_1x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_LOADSPLAT, k_gt_1) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 2; k < 10; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_1x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_LOADSPLAT, k_gt_1_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 2; k < 10; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .a_stride(11)
        .Test(xnn_f32_gemm_ukernel_1x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_LOADSPLAT, k_gt_1_subtile) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 2; k < 10; k++) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_LOADSPLAT, n_gt_8) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 5; k += 2) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_1x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_LOADSPLAT, n_gt_8_strided_cn) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 5; k += 2) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_1x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_LOADSPLAT, n_gt_8_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 5; k += 2) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(n)
          .k(k)
          .a_stride(7)
          .Test(xnn_f32_gemm_ukernel_1x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_LOADSPLAT, n_gt_8_subtile) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 5; k += 2) {
        for (uint32_t m = 1; m <= 1; m++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_LOADSPLAT, n_div_8) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 5; k += 2) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_1x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_LOADSPLAT, n_div_8_strided_cn) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 5; k += 2) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_1x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_LOADSPLAT, n_div_8_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 5; k += 2) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(n)
          .k(k)
          .a_stride(7)
          .Test(xnn_f32_gemm_ukernel_1x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_LOADSPLAT, n_div_8_subtile) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 5; k += 2) {
        for (uint32_t m = 1; m <= 1; m++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_LOADSPLAT, strided_cm_subtile) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 1; k <= 5; k += 2) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_LOADSPLAT, qmin) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(1)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_1x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_1X8__PSIMD_LOADSPLAT, qmax) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(1)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_1x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_1X8__PSIMD_LOADSPLAT, strided_cm) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(1)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_1x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
  }
#endif  // !XNN_ARCH_ASMJS && !XNN_ARCH_WASM


#if !XNN_ARCH_ASMJS && !XNN_ARCH_WASM
  TEST(F32_GEMM_4X8__PSIMD_LOADSPLAT, k_eq_1) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(1)
      .Test(xnn_f32_gemm_ukernel_4x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_4X8__PSIMD_LOADSPLAT, strided_cn) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(1)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_4x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_4X8__PSIMD_LOADSPLAT, k_eq_1_strided_a) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(1)
      .a_stride(3)
      .Test(xnn_f32_gemm_ukernel_4x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_4X8__PSIMD_LOADSPLAT, k_eq_1_subtile) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t m = 1; m <= 4; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(1)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_4x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_LOADSPLAT, k_eq_1_subtile_m) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t m = 1; m <= 4; m++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(m)
        .n(8)
        .k(1)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_LOADSPLAT, k_eq_1_subtile_n) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(n)
        .k(1)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_LOADSPLAT, k_gt_1) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 2; k < 10; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_LOADSPLAT, k_gt_1_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 2; k < 10; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(11)
        .Test(xnn_f32_gemm_ukernel_4x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_LOADSPLAT, k_gt_1_subtile) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 2; k < 10; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_LOADSPLAT, n_gt_8) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 5; k += 2) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_LOADSPLAT, n_gt_8_strided_cn) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 5; k += 2) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_4x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_LOADSPLAT, n_gt_8_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 5; k += 2) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(7)
          .Test(xnn_f32_gemm_ukernel_4x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_LOADSPLAT, n_gt_8_subtile) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 5; k += 2) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_LOADSPLAT, n_div_8) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 5; k += 2) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_LOADSPLAT, n_div_8_strided_cn) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 5; k += 2) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_4x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_LOADSPLAT, n_div_8_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 5; k += 2) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(7)
          .Test(xnn_f32_gemm_ukernel_4x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_LOADSPLAT, n_div_8_subtile) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 5; k += 2) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_LOADSPLAT, strided_cm_subtile) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 1; k <= 5; k += 2) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_LOADSPLAT, qmin) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(1)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_4x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_4X8__PSIMD_LOADSPLAT, qmax) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(1)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_4x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_4X8__PSIMD_LOADSPLAT, strided_cm) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(1)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_4x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
  }
#endif  // !XNN_ARCH_ASMJS && !XNN_ARCH_WASM


#if !XNN_ARCH_ASMJS && !XNN_ARCH_WASM
  TEST(F32_GEMM_6X8__PSIMD_LOADSPLAT, k_eq_1) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(1)
      .Test(xnn_f32_gemm_ukernel_6x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_6X8__PSIMD_LOADSPLAT, strided_cn) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(1)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_6x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_6X8__PSIMD_LOADSPLAT, k_eq_1_strided_a) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(1)
      .a_stride(3)
      .Test(xnn_f32_gemm_ukernel_6x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_6X8__PSIMD_LOADSPLAT, k_eq_1_subtile) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t m = 1; m <= 6; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(1)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_6x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_LOADSPLAT, k_eq_1_subtile_m) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t m = 1; m <= 6; m++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(m)
        .n(8)
        .k(1)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_6x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_LOADSPLAT, k_eq_1_subtile_n) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(n)
        .k(1)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_6x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_LOADSPLAT, k_gt_1) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 2; k < 10; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_6x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_LOADSPLAT, k_gt_1_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 2; k < 10; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .a_stride(11)
        .Test(xnn_f32_gemm_ukernel_6x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_LOADSPLAT, k_gt_1_subtile) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 2; k < 10; k++) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_LOADSPLAT, n_gt_8) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 5; k += 2) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_6x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_LOADSPLAT, n_gt_8_strided_cn) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 5; k += 2) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_6x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_LOADSPLAT, n_gt_8_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 5; k += 2) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(n)
          .k(k)
          .a_stride(7)
          .Test(xnn_f32_gemm_ukernel_6x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_LOADSPLAT, n_gt_8_subtile) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 5; k += 2) {
        for (uint32_t m = 1; m <= 6; m++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_LOADSPLAT, n_div_8) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 5; k += 2) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_6x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_LOADSPLAT, n_div_8_strided_cn) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 5; k += 2) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_6x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_LOADSPLAT, n_div_8_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 5; k += 2) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(n)
          .k(k)
          .a_stride(7)
          .Test(xnn_f32_gemm_ukernel_6x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_LOADSPLAT, n_div_8_subtile) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 5; k += 2) {
        for (uint32_t m = 1; m <= 6; m++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_LOADSPLAT, strided_cm_subtile) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 1; k <= 5; k += 2) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_LOADSPLAT, qmin) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(1)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_6x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_6X8__PSIMD_LOADSPLAT, qmax) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(1)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_6x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_6X8__PSIMD_LOADSPLAT, strided_cm) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(1)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_6x8__psimd_loadsplat, GemmMicrokernelTester::Variant::Scalar);
  }
#endif  // !XNN_ARCH_ASMJS && !XNN_ARCH_WASM


#if !XNN_ARCH_ASMJS && !XNN_ARCH_WASM
  TEST(F32_GEMM_1X8__PSIMD_SPLAT, k_eq_4) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(4)
      .Test(xnn_f32_gemm_ukernel_1x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_1X8__PSIMD_SPLAT, strided_cn) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(4)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_1x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_1X8__PSIMD_SPLAT, k_eq_4_strided_a) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(4)
      .a_stride(7)
      .Test(xnn_f32_gemm_ukernel_1x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_1X8__PSIMD_SPLAT, k_eq_4_subtile) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t m = 1; m <= 1; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(4)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_1x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_SPLAT, k_eq_4_subtile_m) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t m = 1; m <= 1; m++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(m)
        .n(8)
        .k(4)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_1x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_SPLAT, k_eq_4_subtile_n) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(n)
        .k(4)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_1x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_SPLAT, k_lt_4) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 1; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_1x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_SPLAT, k_lt_4_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 1; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .a_stride(7)
        .Test(xnn_f32_gemm_ukernel_1x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_SPLAT, k_lt_4_subtile) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 1; k < 4; k++) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_SPLAT, k_gt_4) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 5; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_1x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_SPLAT, k_gt_4_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 5; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .a_stride(11)
        .Test(xnn_f32_gemm_ukernel_1x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_SPLAT, k_gt_4_subtile) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 5; k < 8; k++) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_SPLAT, k_div_4) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 8; k <= 40; k += 4) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_1x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_SPLAT, k_div_4_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 8; k <= 40; k += 4) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(1)
        .n(8)
        .k(k)
        .a_stride(43)
        .Test(xnn_f32_gemm_ukernel_1x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_SPLAT, k_div_4_subtile) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 8; k <= 40; k += 4) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_SPLAT, n_gt_8) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_1x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_SPLAT, n_gt_8_strided_cn) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_1x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_SPLAT, n_gt_8_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(n)
          .k(k)
          .a_stride(23)
          .Test(xnn_f32_gemm_ukernel_1x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_SPLAT, n_gt_8_subtile) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        for (uint32_t m = 1; m <= 1; m++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_SPLAT, n_div_8) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_1x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_SPLAT, n_div_8_strided_cn) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_1x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_SPLAT, n_div_8_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(1)
          .n(n)
          .k(k)
          .a_stride(23)
          .Test(xnn_f32_gemm_ukernel_1x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_SPLAT, n_div_8_subtile) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        for (uint32_t m = 1; m <= 1; m++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_SPLAT, strided_cm_subtile) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 1; k <= 20; k += 5) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8__PSIMD_SPLAT, qmin) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(4)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_1x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_1X8__PSIMD_SPLAT, qmax) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(4)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_1x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_1X8__PSIMD_SPLAT, strided_cm) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(1)
      .n(8)
      .k(4)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_1x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
  }
#endif  // !XNN_ARCH_ASMJS && !XNN_ARCH_WASM


#if !XNN_ARCH_ASMJS && !XNN_ARCH_WASM
  TEST(F32_GEMM_4X8__PSIMD_SPLAT, k_eq_4) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(4)
      .Test(xnn_f32_gemm_ukernel_4x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_4X8__PSIMD_SPLAT, strided_cn) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(4)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_4x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_4X8__PSIMD_SPLAT, k_eq_4_strided_a) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(4)
      .a_stride(7)
      .Test(xnn_f32_gemm_ukernel_4x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_4X8__PSIMD_SPLAT, k_eq_4_subtile) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t m = 1; m <= 4; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(4)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_4x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_SPLAT, k_eq_4_subtile_m) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t m = 1; m <= 4; m++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(m)
        .n(8)
        .k(4)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_SPLAT, k_eq_4_subtile_n) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(n)
        .k(4)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_SPLAT, k_lt_4) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 1; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_SPLAT, k_lt_4_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 1; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(7)
        .Test(xnn_f32_gemm_ukernel_4x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_SPLAT, k_lt_4_subtile) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 1; k < 4; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_SPLAT, k_gt_4) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 5; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_SPLAT, k_gt_4_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 5; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(11)
        .Test(xnn_f32_gemm_ukernel_4x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_SPLAT, k_gt_4_subtile) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 5; k < 8; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_SPLAT, k_div_4) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 8; k <= 40; k += 4) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_SPLAT, k_div_4_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 8; k <= 40; k += 4) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(43)
        .Test(xnn_f32_gemm_ukernel_4x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_SPLAT, k_div_4_subtile) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 8; k <= 40; k += 4) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_SPLAT, n_gt_8) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_SPLAT, n_gt_8_strided_cn) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_4x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_SPLAT, n_gt_8_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(23)
          .Test(xnn_f32_gemm_ukernel_4x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_SPLAT, n_gt_8_subtile) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_SPLAT, n_div_8) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_SPLAT, n_div_8_strided_cn) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_4x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_SPLAT, n_div_8_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(23)
          .Test(xnn_f32_gemm_ukernel_4x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_SPLAT, n_div_8_subtile) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_SPLAT, strided_cm_subtile) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 1; k <= 20; k += 5) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8__PSIMD_SPLAT, qmin) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(4)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_4x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_4X8__PSIMD_SPLAT, qmax) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(4)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_4x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_4X8__PSIMD_SPLAT, strided_cm) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(4)
      .n(8)
      .k(4)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_4x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
  }
#endif  // !XNN_ARCH_ASMJS && !XNN_ARCH_WASM


#if !XNN_ARCH_ASMJS && !XNN_ARCH_WASM
  TEST(F32_GEMM_6X8__PSIMD_SPLAT, k_eq_4) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(4)
      .Test(xnn_f32_gemm_ukernel_6x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_6X8__PSIMD_SPLAT, strided_cn) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(4)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_6x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_6X8__PSIMD_SPLAT, k_eq_4_strided_a) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(4)
      .a_stride(7)
      .Test(xnn_f32_gemm_ukernel_6x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_6X8__PSIMD_SPLAT, k_eq_4_subtile) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t m = 1; m <= 6; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(4)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_6x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_SPLAT, k_eq_4_subtile_m) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t m = 1; m <= 6; m++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(m)
        .n(8)
        .k(4)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_6x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_SPLAT, k_eq_4_subtile_n) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(n)
        .k(4)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_6x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_SPLAT, k_lt_4) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 1; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_6x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_SPLAT, k_lt_4_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 1; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .a_stride(7)
        .Test(xnn_f32_gemm_ukernel_6x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_SPLAT, k_lt_4_subtile) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 1; k < 4; k++) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_SPLAT, k_gt_4) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 5; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_6x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_SPLAT, k_gt_4_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 5; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .a_stride(11)
        .Test(xnn_f32_gemm_ukernel_6x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_SPLAT, k_gt_4_subtile) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 5; k < 8; k++) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_SPLAT, k_div_4) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 8; k <= 40; k += 4) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_6x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_SPLAT, k_div_4_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 8; k <= 40; k += 4) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(1)
        .m(6)
        .n(8)
        .k(k)
        .a_stride(43)
        .Test(xnn_f32_gemm_ukernel_6x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_SPLAT, k_div_4_subtile) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 8; k <= 40; k += 4) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_SPLAT, n_gt_8) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_6x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_SPLAT, n_gt_8_strided_cn) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_6x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_SPLAT, n_gt_8_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(n)
          .k(k)
          .a_stride(23)
          .Test(xnn_f32_gemm_ukernel_6x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_SPLAT, n_gt_8_subtile) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        for (uint32_t m = 1; m <= 6; m++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_SPLAT, n_div_8) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_6x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_SPLAT, n_div_8_strided_cn) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_6x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_SPLAT, n_div_8_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(1)
          .m(6)
          .n(n)
          .k(k)
          .a_stride(23)
          .Test(xnn_f32_gemm_ukernel_6x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_SPLAT, n_div_8_subtile) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        for (uint32_t m = 1; m <= 6; m++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_SPLAT, strided_cm_subtile) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 1; k <= 20; k += 5) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(1)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8__PSIMD_SPLAT, qmin) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(4)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_6x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_6X8__PSIMD_SPLAT, qmax) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(4)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_6x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_6X8__PSIMD_SPLAT, strided_cm) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(1)
      .m(6)
      .n(8)
      .k(4)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_6x8__psimd_splat, GemmMicrokernelTester::Variant::Scalar);
  }
#endif  // !XNN_ARCH_ASMJS && !XNN_ARCH_WASM


#if !XNN_ARCH_ASMJS && !XNN_ARCH_WASM
  TEST(F32_GEMM_1X8S4__PSIMD, k_eq_4) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(4)
      .m(1)
      .n(8)
      .k(4)
      .Test(xnn_f32_gemm_ukernel_1x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_1X8S4__PSIMD, strided_cn) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(4)
      .m(1)
      .n(8)
      .k(4)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_1x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_1X8S4__PSIMD, k_eq_4_strided_a) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(4)
      .m(1)
      .n(8)
      .k(4)
      .a_stride(7)
      .Test(xnn_f32_gemm_ukernel_1x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_1X8S4__PSIMD, k_eq_4_subtile) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t m = 1; m <= 1; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(4)
          .m(m)
          .n(n)
          .k(4)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_1x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_1X8S4__PSIMD, k_eq_4_subtile_m) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t m = 1; m <= 1; m++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(m)
        .n(8)
        .k(4)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_1x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_1X8S4__PSIMD, k_eq_4_subtile_n) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(1)
        .n(n)
        .k(4)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_1x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_1X8S4__PSIMD, k_lt_4) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 1; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(1)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_1x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_1X8S4__PSIMD, k_lt_4_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 1; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(1)
        .n(8)
        .k(k)
        .a_stride(7)
        .Test(xnn_f32_gemm_ukernel_1x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_1X8S4__PSIMD, k_lt_4_subtile) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 1; k < 4; k++) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(4)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8S4__PSIMD, k_gt_4) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 5; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(1)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_1x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_1X8S4__PSIMD, k_gt_4_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 5; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(1)
        .n(8)
        .k(k)
        .a_stride(11)
        .Test(xnn_f32_gemm_ukernel_1x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_1X8S4__PSIMD, k_gt_4_subtile) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 5; k < 8; k++) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(4)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8S4__PSIMD, k_div_4) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 8; k <= 40; k += 4) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(1)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_1x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_1X8S4__PSIMD, k_div_4_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 8; k <= 40; k += 4) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(1)
        .n(8)
        .k(k)
        .a_stride(43)
        .Test(xnn_f32_gemm_ukernel_1x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_1X8S4__PSIMD, k_div_4_subtile) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 8; k <= 40; k += 4) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(4)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8S4__PSIMD, n_gt_8) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(4)
          .m(1)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_1x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_1X8S4__PSIMD, n_gt_8_strided_cn) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(4)
          .m(1)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_1x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_1X8S4__PSIMD, n_gt_8_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(4)
          .m(1)
          .n(n)
          .k(k)
          .a_stride(23)
          .Test(xnn_f32_gemm_ukernel_1x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_1X8S4__PSIMD, n_gt_8_subtile) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        for (uint32_t m = 1; m <= 1; m++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(4)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8S4__PSIMD, n_div_8) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(4)
          .m(1)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_1x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_1X8S4__PSIMD, n_div_8_strided_cn) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(4)
          .m(1)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_1x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_1X8S4__PSIMD, n_div_8_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(8)
          .kr(1)
          .sr(4)
          .m(1)
          .n(n)
          .k(k)
          .a_stride(23)
          .Test(xnn_f32_gemm_ukernel_1x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_1X8S4__PSIMD, n_div_8_subtile) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        for (uint32_t m = 1; m <= 1; m++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(4)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8S4__PSIMD, strided_cm_subtile) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 1; k <= 20; k += 5) {
      for (uint32_t m = 1; m <= 1; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(1)
            .nr(8)
            .kr(1)
            .sr(4)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_1x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_1X8S4__PSIMD, qmin) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(4)
      .m(1)
      .n(8)
      .k(4)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_1x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_1X8S4__PSIMD, qmax) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(4)
      .m(1)
      .n(8)
      .k(4)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_1x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_1X8S4__PSIMD, strided_cm) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(1)
      .nr(8)
      .kr(1)
      .sr(4)
      .m(1)
      .n(8)
      .k(4)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_1x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
  }
#endif  // !XNN_ARCH_ASMJS && !XNN_ARCH_WASM


#if !XNN_ARCH_ASMJS && !XNN_ARCH_WASM
  TEST(F32_GEMM_4X8S4__PSIMD, k_eq_4) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(4)
      .m(4)
      .n(8)
      .k(4)
      .Test(xnn_f32_gemm_ukernel_4x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_4X8S4__PSIMD, strided_cn) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(4)
      .m(4)
      .n(8)
      .k(4)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_4x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_4X8S4__PSIMD, k_eq_4_strided_a) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(4)
      .m(4)
      .n(8)
      .k(4)
      .a_stride(7)
      .Test(xnn_f32_gemm_ukernel_4x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_4X8S4__PSIMD, k_eq_4_subtile) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t m = 1; m <= 4; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(4)
          .m(m)
          .n(n)
          .k(4)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_4x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_4X8S4__PSIMD, k_eq_4_subtile_m) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t m = 1; m <= 4; m++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(m)
        .n(8)
        .k(4)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_4X8S4__PSIMD, k_eq_4_subtile_n) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(4)
        .n(n)
        .k(4)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_4X8S4__PSIMD, k_lt_4) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 1; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_4X8S4__PSIMD, k_lt_4_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 1; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(7)
        .Test(xnn_f32_gemm_ukernel_4x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_4X8S4__PSIMD, k_lt_4_subtile) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 1; k < 4; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(4)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8S4__PSIMD, k_gt_4) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 5; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_4X8S4__PSIMD, k_gt_4_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 5; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(11)
        .Test(xnn_f32_gemm_ukernel_4x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_4X8S4__PSIMD, k_gt_4_subtile) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 5; k < 8; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(4)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8S4__PSIMD, k_div_4) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 8; k <= 40; k += 4) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(4)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_4X8S4__PSIMD, k_div_4_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 8; k <= 40; k += 4) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(4)
        .n(8)
        .k(k)
        .a_stride(43)
        .Test(xnn_f32_gemm_ukernel_4x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_4X8S4__PSIMD, k_div_4_subtile) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 8; k <= 40; k += 4) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(4)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8S4__PSIMD, n_gt_8) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(4)
          .m(4)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_4X8S4__PSIMD, n_gt_8_strided_cn) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(4)
          .m(4)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_4x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_4X8S4__PSIMD, n_gt_8_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(4)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(23)
          .Test(xnn_f32_gemm_ukernel_4x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_4X8S4__PSIMD, n_gt_8_subtile) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(4)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8S4__PSIMD, n_div_8) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(4)
          .m(4)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_4x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_4X8S4__PSIMD, n_div_8_strided_cn) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(4)
          .m(4)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_4x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_4X8S4__PSIMD, n_div_8_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(8)
          .kr(1)
          .sr(4)
          .m(4)
          .n(n)
          .k(k)
          .a_stride(23)
          .Test(xnn_f32_gemm_ukernel_4x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_4X8S4__PSIMD, n_div_8_subtile) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        for (uint32_t m = 1; m <= 4; m++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(4)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8S4__PSIMD, strided_cm_subtile) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 1; k <= 20; k += 5) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(4)
            .nr(8)
            .kr(1)
            .sr(4)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_4x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_4X8S4__PSIMD, qmin) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(4)
      .m(4)
      .n(8)
      .k(4)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_4x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_4X8S4__PSIMD, qmax) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(4)
      .m(4)
      .n(8)
      .k(4)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_4x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_4X8S4__PSIMD, strided_cm) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(4)
      .nr(8)
      .kr(1)
      .sr(4)
      .m(4)
      .n(8)
      .k(4)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_4x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
  }
#endif  // !XNN_ARCH_ASMJS && !XNN_ARCH_WASM


#if !XNN_ARCH_ASMJS && !XNN_ARCH_WASM
  TEST(F32_GEMM_6X8S4__PSIMD, k_eq_4) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(4)
      .m(6)
      .n(8)
      .k(4)
      .Test(xnn_f32_gemm_ukernel_6x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_6X8S4__PSIMD, strided_cn) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(4)
      .m(6)
      .n(8)
      .k(4)
      .cn_stride(11)
      .Test(xnn_f32_gemm_ukernel_6x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_6X8S4__PSIMD, k_eq_4_strided_a) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(4)
      .m(6)
      .n(8)
      .k(4)
      .a_stride(7)
      .Test(xnn_f32_gemm_ukernel_6x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_6X8S4__PSIMD, k_eq_4_subtile) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t m = 1; m <= 6; m++) {
      for (uint32_t n = 1; n <= 8; n++) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(4)
          .m(m)
          .n(n)
          .k(4)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_6x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_6X8S4__PSIMD, k_eq_4_subtile_m) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t m = 1; m <= 6; m++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(m)
        .n(8)
        .k(4)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_6x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_6X8S4__PSIMD, k_eq_4_subtile_n) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 1; n <= 8; n++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(6)
        .n(n)
        .k(4)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_6x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_6X8S4__PSIMD, k_lt_4) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 1; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(6)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_6x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_6X8S4__PSIMD, k_lt_4_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 1; k < 4; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(6)
        .n(8)
        .k(k)
        .a_stride(7)
        .Test(xnn_f32_gemm_ukernel_6x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_6X8S4__PSIMD, k_lt_4_subtile) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 1; k < 4; k++) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(4)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8S4__PSIMD, k_gt_4) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 5; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(6)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_6x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_6X8S4__PSIMD, k_gt_4_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 5; k < 8; k++) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(6)
        .n(8)
        .k(k)
        .a_stride(11)
        .Test(xnn_f32_gemm_ukernel_6x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_6X8S4__PSIMD, k_gt_4_subtile) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 5; k < 8; k++) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(4)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8S4__PSIMD, k_div_4) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 8; k <= 40; k += 4) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(6)
        .n(8)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_6x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_6X8S4__PSIMD, k_div_4_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 8; k <= 40; k += 4) {
      GemmMicrokernelTester()
        .mr(6)
        .nr(8)
        .kr(1)
        .sr(4)
        .m(6)
        .n(8)
        .k(k)
        .a_stride(43)
        .Test(xnn_f32_gemm_ukernel_6x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_GEMM_6X8S4__PSIMD, k_div_4_subtile) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 8; k <= 40; k += 4) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(4)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8S4__PSIMD, n_gt_8) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(4)
          .m(6)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_6x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_6X8S4__PSIMD, n_gt_8_strided_cn) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(4)
          .m(6)
          .n(8)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_6x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_6X8S4__PSIMD, n_gt_8_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(4)
          .m(6)
          .n(n)
          .k(k)
          .a_stride(23)
          .Test(xnn_f32_gemm_ukernel_6x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_6X8S4__PSIMD, n_gt_8_subtile) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 9; n < 16; n++) {
      for (size_t k = 1; k <= 20; k += 5) {
        for (uint32_t m = 1; m <= 6; m++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(4)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8S4__PSIMD, n_div_8) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(4)
          .m(6)
          .n(8)
          .k(k)
          .Test(xnn_f32_gemm_ukernel_6x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_6X8S4__PSIMD, n_div_8_strided_cn) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(4)
          .m(6)
          .n(n)
          .k(k)
          .cn_stride(11)
          .Test(xnn_f32_gemm_ukernel_6x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_6X8S4__PSIMD, n_div_8_strided_a) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        GemmMicrokernelTester()
          .mr(6)
          .nr(8)
          .kr(1)
          .sr(4)
          .m(6)
          .n(n)
          .k(k)
          .a_stride(23)
          .Test(xnn_f32_gemm_ukernel_6x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_GEMM_6X8S4__PSIMD, n_div_8_subtile) {
    TEST_REQUIRES_PSIMD;
    for (uint32_t n = 16; n <= 24; n += 8) {
      for (size_t k = 1; k <= 20; k += 5) {
        for (uint32_t m = 1; m <= 6; m++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(4)
            .m(m)
            .n(n)
            .k(k)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8S4__PSIMD, strided_cm_subtile) {
    TEST_REQUIRES_PSIMD;
    for (size_t k = 1; k <= 20; k += 5) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmMicrokernelTester()
            .mr(6)
            .nr(8)
            .kr(1)
            .sr(4)
            .m(m)
            .n(n)
            .k(k)
            .cm_stride(11)
            .iterations(1)
            .Test(xnn_f32_gemm_ukernel_6x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
        }
      }
    }
  }

  TEST(F32_GEMM_6X8S4__PSIMD, qmin) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(4)
      .m(6)
      .n(8)
      .k(4)
      .qmin(128)
      .Test(xnn_f32_gemm_ukernel_6x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_6X8S4__PSIMD, qmax) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(4)
      .m(6)
      .n(8)
      .k(4)
      .qmax(128)
      .Test(xnn_f32_gemm_ukernel_6x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_GEMM_6X8S4__PSIMD, strided_cm) {
    TEST_REQUIRES_PSIMD;
    GemmMicrokernelTester()
      .mr(6)
      .nr(8)
      .kr(1)
      .sr(4)
      .m(6)
      .n(8)
      .k(4)
      .cm_stride(11)
      .Test(xnn_f32_gemm_ukernel_6x8s4__psimd, GemmMicrokernelTester::Variant::Scalar);
  }
#endif  // !XNN_ARCH_ASMJS && !XNN_ARCH_WASM


TEST(F32_GEMM_1X4__SCALAR, k_eq_1) {
  GemmMicrokernelTester()
    .mr(1)
    .nr(4)
    .kr(1)
    .sr(1)
    .m(1)
    .n(4)
    .k(1)
    .Test(xnn_f32_gemm_ukernel_1x4__scalar, GemmMicrokernelTester::Variant::Scalar);
}

TEST(F32_GEMM_1X4__SCALAR, strided_cn) {
  GemmMicrokernelTester()
    .mr(1)
    .nr(4)
    .kr(1)
    .sr(1)
    .m(1)
    .n(4)
    .k(1)
    .cn_stride(7)
    .Test(xnn_f32_gemm_ukernel_1x4__scalar, GemmMicrokernelTester::Variant::Scalar);
}

TEST(F32_GEMM_1X4__SCALAR, k_eq_1_strided_a) {
  GemmMicrokernelTester()
    .mr(1)
    .nr(4)
    .kr(1)
    .sr(1)
    .m(1)
    .n(4)
    .k(1)
    .a_stride(3)
    .Test(xnn_f32_gemm_ukernel_1x4__scalar, GemmMicrokernelTester::Variant::Scalar);
}

TEST(F32_GEMM_1X4__SCALAR, k_eq_1_subtile) {
  for (uint32_t m = 1; m <= 1; m++) {
    for (uint32_t n = 1; n <= 4; n++) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(4)
        .kr(1)
        .sr(1)
        .m(m)
        .n(n)
        .k(1)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_1x4__scalar, GemmMicrokernelTester::Variant::Scalar);
    }
  }
}

TEST(F32_GEMM_1X4__SCALAR, k_eq_1_subtile_m) {
  for (uint32_t m = 1; m <= 1; m++) {
    GemmMicrokernelTester()
      .mr(1)
      .nr(4)
      .kr(1)
      .sr(1)
      .m(m)
      .n(4)
      .k(1)
      .iterations(1)
      .Test(xnn_f32_gemm_ukernel_1x4__scalar, GemmMicrokernelTester::Variant::Scalar);
  }
}

TEST(F32_GEMM_1X4__SCALAR, k_eq_1_subtile_n) {
  for (uint32_t n = 1; n <= 4; n++) {
    GemmMicrokernelTester()
      .mr(1)
      .nr(4)
      .kr(1)
      .sr(1)
      .m(1)
      .n(n)
      .k(1)
      .iterations(1)
      .Test(xnn_f32_gemm_ukernel_1x4__scalar, GemmMicrokernelTester::Variant::Scalar);
  }
}

TEST(F32_GEMM_1X4__SCALAR, k_gt_1) {
  for (size_t k = 2; k < 10; k++) {
    GemmMicrokernelTester()
      .mr(1)
      .nr(4)
      .kr(1)
      .sr(1)
      .m(1)
      .n(4)
      .k(k)
      .Test(xnn_f32_gemm_ukernel_1x4__scalar, GemmMicrokernelTester::Variant::Scalar);
  }
}

TEST(F32_GEMM_1X4__SCALAR, k_gt_1_strided_a) {
  for (size_t k = 2; k < 10; k++) {
    GemmMicrokernelTester()
      .mr(1)
      .nr(4)
      .kr(1)
      .sr(1)
      .m(1)
      .n(4)
      .k(k)
      .a_stride(11)
      .Test(xnn_f32_gemm_ukernel_1x4__scalar, GemmMicrokernelTester::Variant::Scalar);
  }
}

TEST(F32_GEMM_1X4__SCALAR, k_gt_1_subtile) {
  for (size_t k = 2; k < 10; k++) {
    for (uint32_t m = 1; m <= 1; m++) {
      for (uint32_t n = 1; n <= 4; n++) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(4)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(k)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_1x4__scalar, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }
}

TEST(F32_GEMM_1X4__SCALAR, n_gt_4) {
  for (uint32_t n = 5; n < 8; n++) {
    for (size_t k = 1; k <= 5; k += 2) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(4)
        .kr(1)
        .sr(1)
        .m(1)
        .n(4)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_1x4__scalar, GemmMicrokernelTester::Variant::Scalar);
    }
  }
}

TEST(F32_GEMM_1X4__SCALAR, n_gt_4_strided_cn) {
  for (uint32_t n = 5; n < 8; n++) {
    for (size_t k = 1; k <= 5; k += 2) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(4)
        .kr(1)
        .sr(1)
        .m(1)
        .n(4)
        .k(k)
        .cn_stride(7)
        .Test(xnn_f32_gemm_ukernel_1x4__scalar, GemmMicrokernelTester::Variant::Scalar);
    }
  }
}

TEST(F32_GEMM_1X4__SCALAR, n_gt_4_strided_a) {
  for (uint32_t n = 5; n < 8; n++) {
    for (size_t k = 1; k <= 5; k += 2) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(4)
        .kr(1)
        .sr(1)
        .m(1)
        .n(n)
        .k(k)
        .a_stride(7)
        .Test(xnn_f32_gemm_ukernel_1x4__scalar, GemmMicrokernelTester::Variant::Scalar);
    }
  }
}

TEST(F32_GEMM_1X4__SCALAR, n_gt_4_subtile) {
  for (uint32_t n = 5; n < 8; n++) {
    for (size_t k = 1; k <= 5; k += 2) {
      for (uint32_t m = 1; m <= 1; m++) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(4)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(k)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_1x4__scalar, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }
}

TEST(F32_GEMM_1X4__SCALAR, n_div_4) {
  for (uint32_t n = 8; n <= 12; n += 4) {
    for (size_t k = 1; k <= 5; k += 2) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(4)
        .kr(1)
        .sr(1)
        .m(1)
        .n(4)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_1x4__scalar, GemmMicrokernelTester::Variant::Scalar);
    }
  }
}

TEST(F32_GEMM_1X4__SCALAR, n_div_4_strided_cn) {
  for (uint32_t n = 8; n <= 12; n += 4) {
    for (size_t k = 1; k <= 5; k += 2) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(4)
        .kr(1)
        .sr(1)
        .m(1)
        .n(n)
        .k(k)
        .cn_stride(7)
        .Test(xnn_f32_gemm_ukernel_1x4__scalar, GemmMicrokernelTester::Variant::Scalar);
    }
  }
}

TEST(F32_GEMM_1X4__SCALAR, n_div_4_strided_a) {
  for (uint32_t n = 8; n <= 12; n += 4) {
    for (size_t k = 1; k <= 5; k += 2) {
      GemmMicrokernelTester()
        .mr(1)
        .nr(4)
        .kr(1)
        .sr(1)
        .m(1)
        .n(n)
        .k(k)
        .a_stride(7)
        .Test(xnn_f32_gemm_ukernel_1x4__scalar, GemmMicrokernelTester::Variant::Scalar);
    }
  }
}

TEST(F32_GEMM_1X4__SCALAR, n_div_4_subtile) {
  for (uint32_t n = 8; n <= 12; n += 4) {
    for (size_t k = 1; k <= 5; k += 2) {
      for (uint32_t m = 1; m <= 1; m++) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(4)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(k)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_1x4__scalar, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }
}

TEST(F32_GEMM_1X4__SCALAR, strided_cm_subtile) {
  for (size_t k = 1; k <= 5; k += 2) {
    for (uint32_t m = 1; m <= 1; m++) {
      for (uint32_t n = 1; n <= 4; n++) {
        GemmMicrokernelTester()
          .mr(1)
          .nr(4)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(k)
          .cm_stride(7)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_1x4__scalar, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }
}

TEST(F32_GEMM_1X4__SCALAR, qmin) {
  GemmMicrokernelTester()
    .mr(1)
    .nr(4)
    .kr(1)
    .sr(1)
    .m(1)
    .n(4)
    .k(1)
    .qmin(128)
    .Test(xnn_f32_gemm_ukernel_1x4__scalar, GemmMicrokernelTester::Variant::Scalar);
}

TEST(F32_GEMM_1X4__SCALAR, qmax) {
  GemmMicrokernelTester()
    .mr(1)
    .nr(4)
    .kr(1)
    .sr(1)
    .m(1)
    .n(4)
    .k(1)
    .qmax(128)
    .Test(xnn_f32_gemm_ukernel_1x4__scalar, GemmMicrokernelTester::Variant::Scalar);
}

TEST(F32_GEMM_1X4__SCALAR, strided_cm) {
  GemmMicrokernelTester()
    .mr(1)
    .nr(4)
    .kr(1)
    .sr(1)
    .m(1)
    .n(4)
    .k(1)
    .cm_stride(7)
    .Test(xnn_f32_gemm_ukernel_1x4__scalar, GemmMicrokernelTester::Variant::Scalar);
}


TEST(F32_GEMM_2X4__SCALAR, k_eq_1) {
  GemmMicrokernelTester()
    .mr(2)
    .nr(4)
    .kr(1)
    .sr(1)
    .m(2)
    .n(4)
    .k(1)
    .Test(xnn_f32_gemm_ukernel_2x4__scalar, GemmMicrokernelTester::Variant::Scalar);
}

TEST(F32_GEMM_2X4__SCALAR, strided_cn) {
  GemmMicrokernelTester()
    .mr(2)
    .nr(4)
    .kr(1)
    .sr(1)
    .m(2)
    .n(4)
    .k(1)
    .cn_stride(7)
    .Test(xnn_f32_gemm_ukernel_2x4__scalar, GemmMicrokernelTester::Variant::Scalar);
}

TEST(F32_GEMM_2X4__SCALAR, k_eq_1_strided_a) {
  GemmMicrokernelTester()
    .mr(2)
    .nr(4)
    .kr(1)
    .sr(1)
    .m(2)
    .n(4)
    .k(1)
    .a_stride(3)
    .Test(xnn_f32_gemm_ukernel_2x4__scalar, GemmMicrokernelTester::Variant::Scalar);
}

TEST(F32_GEMM_2X4__SCALAR, k_eq_1_subtile) {
  for (uint32_t m = 1; m <= 2; m++) {
    for (uint32_t n = 1; n <= 4; n++) {
      GemmMicrokernelTester()
        .mr(2)
        .nr(4)
        .kr(1)
        .sr(1)
        .m(m)
        .n(n)
        .k(1)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_2x4__scalar, GemmMicrokernelTester::Variant::Scalar);
    }
  }
}

TEST(F32_GEMM_2X4__SCALAR, k_eq_1_subtile_m) {
  for (uint32_t m = 1; m <= 2; m++) {
    GemmMicrokernelTester()
      .mr(2)
      .nr(4)
      .kr(1)
      .sr(1)
      .m(m)
      .n(4)
      .k(1)
      .iterations(1)
      .Test(xnn_f32_gemm_ukernel_2x4__scalar, GemmMicrokernelTester::Variant::Scalar);
  }
}

TEST(F32_GEMM_2X4__SCALAR, k_eq_1_subtile_n) {
  for (uint32_t n = 1; n <= 4; n++) {
    GemmMicrokernelTester()
      .mr(2)
      .nr(4)
      .kr(1)
      .sr(1)
      .m(2)
      .n(n)
      .k(1)
      .iterations(1)
      .Test(xnn_f32_gemm_ukernel_2x4__scalar, GemmMicrokernelTester::Variant::Scalar);
  }
}

TEST(F32_GEMM_2X4__SCALAR, k_gt_1) {
  for (size_t k = 2; k < 10; k++) {
    GemmMicrokernelTester()
      .mr(2)
      .nr(4)
      .kr(1)
      .sr(1)
      .m(2)
      .n(4)
      .k(k)
      .Test(xnn_f32_gemm_ukernel_2x4__scalar, GemmMicrokernelTester::Variant::Scalar);
  }
}

TEST(F32_GEMM_2X4__SCALAR, k_gt_1_strided_a) {
  for (size_t k = 2; k < 10; k++) {
    GemmMicrokernelTester()
      .mr(2)
      .nr(4)
      .kr(1)
      .sr(1)
      .m(2)
      .n(4)
      .k(k)
      .a_stride(11)
      .Test(xnn_f32_gemm_ukernel_2x4__scalar, GemmMicrokernelTester::Variant::Scalar);
  }
}

TEST(F32_GEMM_2X4__SCALAR, k_gt_1_subtile) {
  for (size_t k = 2; k < 10; k++) {
    for (uint32_t m = 1; m <= 2; m++) {
      for (uint32_t n = 1; n <= 4; n++) {
        GemmMicrokernelTester()
          .mr(2)
          .nr(4)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(k)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_2x4__scalar, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }
}

TEST(F32_GEMM_2X4__SCALAR, n_gt_4) {
  for (uint32_t n = 5; n < 8; n++) {
    for (size_t k = 1; k <= 5; k += 2) {
      GemmMicrokernelTester()
        .mr(2)
        .nr(4)
        .kr(1)
        .sr(1)
        .m(2)
        .n(4)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_2x4__scalar, GemmMicrokernelTester::Variant::Scalar);
    }
  }
}

TEST(F32_GEMM_2X4__SCALAR, n_gt_4_strided_cn) {
  for (uint32_t n = 5; n < 8; n++) {
    for (size_t k = 1; k <= 5; k += 2) {
      GemmMicrokernelTester()
        .mr(2)
        .nr(4)
        .kr(1)
        .sr(1)
        .m(2)
        .n(4)
        .k(k)
        .cn_stride(7)
        .Test(xnn_f32_gemm_ukernel_2x4__scalar, GemmMicrokernelTester::Variant::Scalar);
    }
  }
}

TEST(F32_GEMM_2X4__SCALAR, n_gt_4_strided_a) {
  for (uint32_t n = 5; n < 8; n++) {
    for (size_t k = 1; k <= 5; k += 2) {
      GemmMicrokernelTester()
        .mr(2)
        .nr(4)
        .kr(1)
        .sr(1)
        .m(2)
        .n(n)
        .k(k)
        .a_stride(7)
        .Test(xnn_f32_gemm_ukernel_2x4__scalar, GemmMicrokernelTester::Variant::Scalar);
    }
  }
}

TEST(F32_GEMM_2X4__SCALAR, n_gt_4_subtile) {
  for (uint32_t n = 5; n < 8; n++) {
    for (size_t k = 1; k <= 5; k += 2) {
      for (uint32_t m = 1; m <= 2; m++) {
        GemmMicrokernelTester()
          .mr(2)
          .nr(4)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(k)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_2x4__scalar, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }
}

TEST(F32_GEMM_2X4__SCALAR, n_div_4) {
  for (uint32_t n = 8; n <= 12; n += 4) {
    for (size_t k = 1; k <= 5; k += 2) {
      GemmMicrokernelTester()
        .mr(2)
        .nr(4)
        .kr(1)
        .sr(1)
        .m(2)
        .n(4)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_2x4__scalar, GemmMicrokernelTester::Variant::Scalar);
    }
  }
}

TEST(F32_GEMM_2X4__SCALAR, n_div_4_strided_cn) {
  for (uint32_t n = 8; n <= 12; n += 4) {
    for (size_t k = 1; k <= 5; k += 2) {
      GemmMicrokernelTester()
        .mr(2)
        .nr(4)
        .kr(1)
        .sr(1)
        .m(2)
        .n(n)
        .k(k)
        .cn_stride(7)
        .Test(xnn_f32_gemm_ukernel_2x4__scalar, GemmMicrokernelTester::Variant::Scalar);
    }
  }
}

TEST(F32_GEMM_2X4__SCALAR, n_div_4_strided_a) {
  for (uint32_t n = 8; n <= 12; n += 4) {
    for (size_t k = 1; k <= 5; k += 2) {
      GemmMicrokernelTester()
        .mr(2)
        .nr(4)
        .kr(1)
        .sr(1)
        .m(2)
        .n(n)
        .k(k)
        .a_stride(7)
        .Test(xnn_f32_gemm_ukernel_2x4__scalar, GemmMicrokernelTester::Variant::Scalar);
    }
  }
}

TEST(F32_GEMM_2X4__SCALAR, n_div_4_subtile) {
  for (uint32_t n = 8; n <= 12; n += 4) {
    for (size_t k = 1; k <= 5; k += 2) {
      for (uint32_t m = 1; m <= 2; m++) {
        GemmMicrokernelTester()
          .mr(2)
          .nr(4)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(k)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_2x4__scalar, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }
}

TEST(F32_GEMM_2X4__SCALAR, strided_cm_subtile) {
  for (size_t k = 1; k <= 5; k += 2) {
    for (uint32_t m = 1; m <= 2; m++) {
      for (uint32_t n = 1; n <= 4; n++) {
        GemmMicrokernelTester()
          .mr(2)
          .nr(4)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(k)
          .cm_stride(7)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_2x4__scalar, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }
}

TEST(F32_GEMM_2X4__SCALAR, qmin) {
  GemmMicrokernelTester()
    .mr(2)
    .nr(4)
    .kr(1)
    .sr(1)
    .m(2)
    .n(4)
    .k(1)
    .qmin(128)
    .Test(xnn_f32_gemm_ukernel_2x4__scalar, GemmMicrokernelTester::Variant::Scalar);
}

TEST(F32_GEMM_2X4__SCALAR, qmax) {
  GemmMicrokernelTester()
    .mr(2)
    .nr(4)
    .kr(1)
    .sr(1)
    .m(2)
    .n(4)
    .k(1)
    .qmax(128)
    .Test(xnn_f32_gemm_ukernel_2x4__scalar, GemmMicrokernelTester::Variant::Scalar);
}

TEST(F32_GEMM_2X4__SCALAR, strided_cm) {
  GemmMicrokernelTester()
    .mr(2)
    .nr(4)
    .kr(1)
    .sr(1)
    .m(2)
    .n(4)
    .k(1)
    .cm_stride(7)
    .Test(xnn_f32_gemm_ukernel_2x4__scalar, GemmMicrokernelTester::Variant::Scalar);
}


TEST(F32_GEMM_4X4__SCALAR, k_eq_1) {
  GemmMicrokernelTester()
    .mr(4)
    .nr(4)
    .kr(1)
    .sr(1)
    .m(4)
    .n(4)
    .k(1)
    .Test(xnn_f32_gemm_ukernel_4x4__scalar, GemmMicrokernelTester::Variant::Scalar);
}

TEST(F32_GEMM_4X4__SCALAR, strided_cn) {
  GemmMicrokernelTester()
    .mr(4)
    .nr(4)
    .kr(1)
    .sr(1)
    .m(4)
    .n(4)
    .k(1)
    .cn_stride(7)
    .Test(xnn_f32_gemm_ukernel_4x4__scalar, GemmMicrokernelTester::Variant::Scalar);
}

TEST(F32_GEMM_4X4__SCALAR, k_eq_1_strided_a) {
  GemmMicrokernelTester()
    .mr(4)
    .nr(4)
    .kr(1)
    .sr(1)
    .m(4)
    .n(4)
    .k(1)
    .a_stride(3)
    .Test(xnn_f32_gemm_ukernel_4x4__scalar, GemmMicrokernelTester::Variant::Scalar);
}

TEST(F32_GEMM_4X4__SCALAR, k_eq_1_subtile) {
  for (uint32_t m = 1; m <= 4; m++) {
    for (uint32_t n = 1; n <= 4; n++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(4)
        .kr(1)
        .sr(1)
        .m(m)
        .n(n)
        .k(1)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x4__scalar, GemmMicrokernelTester::Variant::Scalar);
    }
  }
}

TEST(F32_GEMM_4X4__SCALAR, k_eq_1_subtile_m) {
  for (uint32_t m = 1; m <= 4; m++) {
    GemmMicrokernelTester()
      .mr(4)
      .nr(4)
      .kr(1)
      .sr(1)
      .m(m)
      .n(4)
      .k(1)
      .iterations(1)
      .Test(xnn_f32_gemm_ukernel_4x4__scalar, GemmMicrokernelTester::Variant::Scalar);
  }
}

TEST(F32_GEMM_4X4__SCALAR, k_eq_1_subtile_n) {
  for (uint32_t n = 1; n <= 4; n++) {
    GemmMicrokernelTester()
      .mr(4)
      .nr(4)
      .kr(1)
      .sr(1)
      .m(4)
      .n(n)
      .k(1)
      .iterations(1)
      .Test(xnn_f32_gemm_ukernel_4x4__scalar, GemmMicrokernelTester::Variant::Scalar);
  }
}

TEST(F32_GEMM_4X4__SCALAR, k_gt_1) {
  for (size_t k = 2; k < 10; k++) {
    GemmMicrokernelTester()
      .mr(4)
      .nr(4)
      .kr(1)
      .sr(1)
      .m(4)
      .n(4)
      .k(k)
      .Test(xnn_f32_gemm_ukernel_4x4__scalar, GemmMicrokernelTester::Variant::Scalar);
  }
}

TEST(F32_GEMM_4X4__SCALAR, k_gt_1_strided_a) {
  for (size_t k = 2; k < 10; k++) {
    GemmMicrokernelTester()
      .mr(4)
      .nr(4)
      .kr(1)
      .sr(1)
      .m(4)
      .n(4)
      .k(k)
      .a_stride(11)
      .Test(xnn_f32_gemm_ukernel_4x4__scalar, GemmMicrokernelTester::Variant::Scalar);
  }
}

TEST(F32_GEMM_4X4__SCALAR, k_gt_1_subtile) {
  for (size_t k = 2; k < 10; k++) {
    for (uint32_t m = 1; m <= 4; m++) {
      for (uint32_t n = 1; n <= 4; n++) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(4)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(k)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_4x4__scalar, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }
}

TEST(F32_GEMM_4X4__SCALAR, n_gt_4) {
  for (uint32_t n = 5; n < 8; n++) {
    for (size_t k = 1; k <= 5; k += 2) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(4)
        .kr(1)
        .sr(1)
        .m(4)
        .n(4)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x4__scalar, GemmMicrokernelTester::Variant::Scalar);
    }
  }
}

TEST(F32_GEMM_4X4__SCALAR, n_gt_4_strided_cn) {
  for (uint32_t n = 5; n < 8; n++) {
    for (size_t k = 1; k <= 5; k += 2) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(4)
        .kr(1)
        .sr(1)
        .m(4)
        .n(4)
        .k(k)
        .cn_stride(7)
        .Test(xnn_f32_gemm_ukernel_4x4__scalar, GemmMicrokernelTester::Variant::Scalar);
    }
  }
}

TEST(F32_GEMM_4X4__SCALAR, n_gt_4_strided_a) {
  for (uint32_t n = 5; n < 8; n++) {
    for (size_t k = 1; k <= 5; k += 2) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(4)
        .kr(1)
        .sr(1)
        .m(4)
        .n(n)
        .k(k)
        .a_stride(7)
        .Test(xnn_f32_gemm_ukernel_4x4__scalar, GemmMicrokernelTester::Variant::Scalar);
    }
  }
}

TEST(F32_GEMM_4X4__SCALAR, n_gt_4_subtile) {
  for (uint32_t n = 5; n < 8; n++) {
    for (size_t k = 1; k <= 5; k += 2) {
      for (uint32_t m = 1; m <= 4; m++) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(4)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(k)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_4x4__scalar, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }
}

TEST(F32_GEMM_4X4__SCALAR, n_div_4) {
  for (uint32_t n = 8; n <= 12; n += 4) {
    for (size_t k = 1; k <= 5; k += 2) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(4)
        .kr(1)
        .sr(1)
        .m(4)
        .n(4)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x4__scalar, GemmMicrokernelTester::Variant::Scalar);
    }
  }
}

TEST(F32_GEMM_4X4__SCALAR, n_div_4_strided_cn) {
  for (uint32_t n = 8; n <= 12; n += 4) {
    for (size_t k = 1; k <= 5; k += 2) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(4)
        .kr(1)
        .sr(1)
        .m(4)
        .n(n)
        .k(k)
        .cn_stride(7)
        .Test(xnn_f32_gemm_ukernel_4x4__scalar, GemmMicrokernelTester::Variant::Scalar);
    }
  }
}

TEST(F32_GEMM_4X4__SCALAR, n_div_4_strided_a) {
  for (uint32_t n = 8; n <= 12; n += 4) {
    for (size_t k = 1; k <= 5; k += 2) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(4)
        .kr(1)
        .sr(1)
        .m(4)
        .n(n)
        .k(k)
        .a_stride(7)
        .Test(xnn_f32_gemm_ukernel_4x4__scalar, GemmMicrokernelTester::Variant::Scalar);
    }
  }
}

TEST(F32_GEMM_4X4__SCALAR, n_div_4_subtile) {
  for (uint32_t n = 8; n <= 12; n += 4) {
    for (size_t k = 1; k <= 5; k += 2) {
      for (uint32_t m = 1; m <= 4; m++) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(4)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(k)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_4x4__scalar, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }
}

TEST(F32_GEMM_4X4__SCALAR, strided_cm_subtile) {
  for (size_t k = 1; k <= 5; k += 2) {
    for (uint32_t m = 1; m <= 4; m++) {
      for (uint32_t n = 1; n <= 4; n++) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(4)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(k)
          .cm_stride(7)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_4x4__scalar, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }
}

TEST(F32_GEMM_4X4__SCALAR, qmin) {
  GemmMicrokernelTester()
    .mr(4)
    .nr(4)
    .kr(1)
    .sr(1)
    .m(4)
    .n(4)
    .k(1)
    .qmin(128)
    .Test(xnn_f32_gemm_ukernel_4x4__scalar, GemmMicrokernelTester::Variant::Scalar);
}

TEST(F32_GEMM_4X4__SCALAR, qmax) {
  GemmMicrokernelTester()
    .mr(4)
    .nr(4)
    .kr(1)
    .sr(1)
    .m(4)
    .n(4)
    .k(1)
    .qmax(128)
    .Test(xnn_f32_gemm_ukernel_4x4__scalar, GemmMicrokernelTester::Variant::Scalar);
}

TEST(F32_GEMM_4X4__SCALAR, strided_cm) {
  GemmMicrokernelTester()
    .mr(4)
    .nr(4)
    .kr(1)
    .sr(1)
    .m(4)
    .n(4)
    .k(1)
    .cm_stride(7)
    .Test(xnn_f32_gemm_ukernel_4x4__scalar, GemmMicrokernelTester::Variant::Scalar);
}


TEST(F32_GEMM_4X2__SCALAR, k_eq_1) {
  GemmMicrokernelTester()
    .mr(4)
    .nr(2)
    .kr(1)
    .sr(1)
    .m(4)
    .n(2)
    .k(1)
    .Test(xnn_f32_gemm_ukernel_4x2__scalar, GemmMicrokernelTester::Variant::Scalar);
}

TEST(F32_GEMM_4X2__SCALAR, strided_cn) {
  GemmMicrokernelTester()
    .mr(4)
    .nr(2)
    .kr(1)
    .sr(1)
    .m(4)
    .n(2)
    .k(1)
    .cn_stride(5)
    .Test(xnn_f32_gemm_ukernel_4x2__scalar, GemmMicrokernelTester::Variant::Scalar);
}

TEST(F32_GEMM_4X2__SCALAR, k_eq_1_strided_a) {
  GemmMicrokernelTester()
    .mr(4)
    .nr(2)
    .kr(1)
    .sr(1)
    .m(4)
    .n(2)
    .k(1)
    .a_stride(3)
    .Test(xnn_f32_gemm_ukernel_4x2__scalar, GemmMicrokernelTester::Variant::Scalar);
}

TEST(F32_GEMM_4X2__SCALAR, k_eq_1_subtile) {
  for (uint32_t m = 1; m <= 4; m++) {
    for (uint32_t n = 1; n <= 2; n++) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(2)
        .kr(1)
        .sr(1)
        .m(m)
        .n(n)
        .k(1)
        .iterations(1)
        .Test(xnn_f32_gemm_ukernel_4x2__scalar, GemmMicrokernelTester::Variant::Scalar);
    }
  }
}

TEST(F32_GEMM_4X2__SCALAR, k_eq_1_subtile_m) {
  for (uint32_t m = 1; m <= 4; m++) {
    GemmMicrokernelTester()
      .mr(4)
      .nr(2)
      .kr(1)
      .sr(1)
      .m(m)
      .n(2)
      .k(1)
      .iterations(1)
      .Test(xnn_f32_gemm_ukernel_4x2__scalar, GemmMicrokernelTester::Variant::Scalar);
  }
}

TEST(F32_GEMM_4X2__SCALAR, k_eq_1_subtile_n) {
  for (uint32_t n = 1; n <= 2; n++) {
    GemmMicrokernelTester()
      .mr(4)
      .nr(2)
      .kr(1)
      .sr(1)
      .m(4)
      .n(n)
      .k(1)
      .iterations(1)
      .Test(xnn_f32_gemm_ukernel_4x2__scalar, GemmMicrokernelTester::Variant::Scalar);
  }
}

TEST(F32_GEMM_4X2__SCALAR, k_gt_1) {
  for (size_t k = 2; k < 10; k++) {
    GemmMicrokernelTester()
      .mr(4)
      .nr(2)
      .kr(1)
      .sr(1)
      .m(4)
      .n(2)
      .k(k)
      .Test(xnn_f32_gemm_ukernel_4x2__scalar, GemmMicrokernelTester::Variant::Scalar);
  }
}

TEST(F32_GEMM_4X2__SCALAR, k_gt_1_strided_a) {
  for (size_t k = 2; k < 10; k++) {
    GemmMicrokernelTester()
      .mr(4)
      .nr(2)
      .kr(1)
      .sr(1)
      .m(4)
      .n(2)
      .k(k)
      .a_stride(11)
      .Test(xnn_f32_gemm_ukernel_4x2__scalar, GemmMicrokernelTester::Variant::Scalar);
  }
}

TEST(F32_GEMM_4X2__SCALAR, k_gt_1_subtile) {
  for (size_t k = 2; k < 10; k++) {
    for (uint32_t m = 1; m <= 4; m++) {
      for (uint32_t n = 1; n <= 2; n++) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(2)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(k)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_4x2__scalar, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }
}

TEST(F32_GEMM_4X2__SCALAR, n_gt_2) {
  for (uint32_t n = 3; n < 4; n++) {
    for (size_t k = 1; k <= 5; k += 2) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(2)
        .kr(1)
        .sr(1)
        .m(4)
        .n(2)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x2__scalar, GemmMicrokernelTester::Variant::Scalar);
    }
  }
}

TEST(F32_GEMM_4X2__SCALAR, n_gt_2_strided_cn) {
  for (uint32_t n = 3; n < 4; n++) {
    for (size_t k = 1; k <= 5; k += 2) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(2)
        .kr(1)
        .sr(1)
        .m(4)
        .n(2)
        .k(k)
        .cn_stride(5)
        .Test(xnn_f32_gemm_ukernel_4x2__scalar, GemmMicrokernelTester::Variant::Scalar);
    }
  }
}

TEST(F32_GEMM_4X2__SCALAR, n_gt_2_strided_a) {
  for (uint32_t n = 3; n < 4; n++) {
    for (size_t k = 1; k <= 5; k += 2) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(2)
        .kr(1)
        .sr(1)
        .m(4)
        .n(n)
        .k(k)
        .a_stride(7)
        .Test(xnn_f32_gemm_ukernel_4x2__scalar, GemmMicrokernelTester::Variant::Scalar);
    }
  }
}

TEST(F32_GEMM_4X2__SCALAR, n_gt_2_subtile) {
  for (uint32_t n = 3; n < 4; n++) {
    for (size_t k = 1; k <= 5; k += 2) {
      for (uint32_t m = 1; m <= 4; m++) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(2)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(k)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_4x2__scalar, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }
}

TEST(F32_GEMM_4X2__SCALAR, n_div_2) {
  for (uint32_t n = 4; n <= 6; n += 2) {
    for (size_t k = 1; k <= 5; k += 2) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(2)
        .kr(1)
        .sr(1)
        .m(4)
        .n(2)
        .k(k)
        .Test(xnn_f32_gemm_ukernel_4x2__scalar, GemmMicrokernelTester::Variant::Scalar);
    }
  }
}

TEST(F32_GEMM_4X2__SCALAR, n_div_2_strided_cn) {
  for (uint32_t n = 4; n <= 6; n += 2) {
    for (size_t k = 1; k <= 5; k += 2) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(2)
        .kr(1)
        .sr(1)
        .m(4)
        .n(n)
        .k(k)
        .cn_stride(5)
        .Test(xnn_f32_gemm_ukernel_4x2__scalar, GemmMicrokernelTester::Variant::Scalar);
    }
  }
}

TEST(F32_GEMM_4X2__SCALAR, n_div_2_strided_a) {
  for (uint32_t n = 4; n <= 6; n += 2) {
    for (size_t k = 1; k <= 5; k += 2) {
      GemmMicrokernelTester()
        .mr(4)
        .nr(2)
        .kr(1)
        .sr(1)
        .m(4)
        .n(n)
        .k(k)
        .a_stride(7)
        .Test(xnn_f32_gemm_ukernel_4x2__scalar, GemmMicrokernelTester::Variant::Scalar);
    }
  }
}

TEST(F32_GEMM_4X2__SCALAR, n_div_2_subtile) {
  for (uint32_t n = 4; n <= 6; n += 2) {
    for (size_t k = 1; k <= 5; k += 2) {
      for (uint32_t m = 1; m <= 4; m++) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(2)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(k)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_4x2__scalar, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }
}

TEST(F32_GEMM_4X2__SCALAR, strided_cm_subtile) {
  for (size_t k = 1; k <= 5; k += 2) {
    for (uint32_t m = 1; m <= 4; m++) {
      for (uint32_t n = 1; n <= 2; n++) {
        GemmMicrokernelTester()
          .mr(4)
          .nr(2)
          .kr(1)
          .sr(1)
          .m(m)
          .n(n)
          .k(k)
          .cm_stride(5)
          .iterations(1)
          .Test(xnn_f32_gemm_ukernel_4x2__scalar, GemmMicrokernelTester::Variant::Scalar);
      }
    }
  }
}

TEST(F32_GEMM_4X2__SCALAR, qmin) {
  GemmMicrokernelTester()
    .mr(4)
    .nr(2)
    .kr(1)
    .sr(1)
    .m(4)
    .n(2)
    .k(1)
    .qmin(128)
    .Test(xnn_f32_gemm_ukernel_4x2__scalar, GemmMicrokernelTester::Variant::Scalar);
}

TEST(F32_GEMM_4X2__SCALAR, qmax) {
  GemmMicrokernelTester()
    .mr(4)
    .nr(2)
    .kr(1)
    .sr(1)
    .m(4)
    .n(2)
    .k(1)
    .qmax(128)
    .Test(xnn_f32_gemm_ukernel_4x2__scalar, GemmMicrokernelTester::Variant::Scalar);
}

TEST(F32_GEMM_4X2__SCALAR, strided_cm) {
  GemmMicrokernelTester()
    .mr(4)
    .nr(2)
    .kr(1)
    .sr(1)
    .m(4)
    .n(2)
    .k(1)
    .cm_stride(5)
    .Test(xnn_f32_gemm_ukernel_4x2__scalar, GemmMicrokernelTester::Variant::Scalar);
}

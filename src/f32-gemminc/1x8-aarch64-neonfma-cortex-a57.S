// Auto-generated file. Do not edit!
//   Template: src/f32-gemm/1x8-aarch64-neonfma-cortex-a57.S.in
//   Generator: tools/xngen
//
# Copyright 2019 Google LLC
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree.

#include <xnnpack/assembly.h>

# void xnn_f32_gemminc_ukernel_1x8__aarch64_neonfma_cortex_a57(
#     size_t mr,                (x0) - unused.  mr = 1
#     size_t nc,                x1
#     size_t kc,                x2 / x0
#     const uint8_t*restrict a, x3
#     size_t a_stride,          (x4) - unused
#     const void*restrict w,    x5
#     uint8_t*restrict c,       x6
#     size_t cm_stride,         (x7) - unused
#     size_t cn_stride,         [sp] -> x14
#     const float*restrict acc,  [sp + 8] -> x15
#     const union xnn_f32_output_params params[restrict static 1])  [sp + 16] -> x8

# d8-d15 need to be preserved if used.
# x19-30 need to be preserved if used.

# A pointer
# x3  a0

# C pointer
# x6  c0

# Clamp v4 v5

# A57 based on A75 but with PRFM removed from main loop

BEGIN_FUNCTION xnn_f32_gemminc_ukernel_1x8__aarch64_neonfma_cortex_a57

        # Load cn_stride, acc
        LDP x14, x15, [sp]
        # Load params pointer
        LDR x8, [sp, 16]

        # Load clamping_params values
        LD2R {v4.4s, v5.4s}, [x8]
0:
        # Load initial accumulators
        LDP q16, q17, [x15], 32

        MOVI v18.4s, 0  // second set of C for pipelining FMLA
        PRFM PLDL1KEEP, [x5]
        MOVI v19.4s, 0
        PRFM PLDL1KEEP, [x5, 64]
        PRFM PLDL1KEEP, [x5, 128]
        PRFM PLDL1KEEP, [x5, 192]

        # Is there at least 8 floats (32 bytes) for prologue + epilogue?
        SUBS x0, x2, 32  // k = kc - 32

        B.LO 3f

        # 16 prologue
        # Read first block of 1 A and B.
        LDP q20, q21, [x5], 32
        LDP q22, q23, [x5], 32
        LDP q24, q25, [x5], 32
        LDP q26, q27, [x5], 32
        LDR q0, [x3], 16

        # Is there at least 32.  yes do main loop
        SUBS x0, x0, 32
        B.LO 2f

        # Main loop - 8 floats of A (32 bytes)
1:
        # First block of 4.  FMA for first 4, loads for 2nd block of 4.
        FMLA v16.4s, v20.4s, v0.s[0]
        LDR q1, [x3], 16
        FMLA v17.4s, v21.4s, v0.s[0]
        LDP q20, q21, [x5], 32
        FMLA v18.4s, v22.4s, v0.s[1]
        FMLA v19.4s, v23.4s, v0.s[1]
        LDP q22, q23, [x5], 32
        FMLA v16.4s, v24.4s, v0.s[2]
        FMLA v17.4s, v25.4s, v0.s[2]
        LDP q24, q25, [x5], 32
        FMLA v18.4s, v26.4s, v0.s[3]
        FMLA v19.4s, v27.4s, v0.s[3]
        LDP q26, q27, [x5], 32

        # Second block of 4.  FMA for second 4, loads for 1st block of 4.
        FMLA v16.4s, v20.4s, v1.s[0]
        LDR q0, [x3], 16
        FMLA v17.4s, v21.4s, v1.s[0]
        LDP q20, q21, [x5], 32
        FMLA v18.4s, v22.4s, v1.s[1]
        FMLA v19.4s, v23.4s, v1.s[1]
        LDP q22, q23, [x5], 32
        FMLA v16.4s, v24.4s, v1.s[2]
        FMLA v17.4s, v25.4s, v1.s[2]
        LDP q24, q25, [x5], 32
        FMLA v18.4s, v26.4s, v1.s[3]
        FMLA v19.4s, v27.4s, v1.s[3]
        SUBS x0, x0, 32
        LDP q26, q27, [x5], 32
        B.HS 1b

2:
        # Epilogue

        # First block of 4.  FMA for first 4, loads for 2nd block of 4.
        FMLA v16.4s, v20.4s, v0.s[0]
        LDR q1, [x3], 16
        FMLA v17.4s, v21.4s, v0.s[0]
        LDP q20, q21, [x5], 32
        FMLA v18.4s, v22.4s, v0.s[1]
        FMLA v19.4s, v23.4s, v0.s[1]
        LDP q22, q23, [x5], 32
        FMLA v16.4s, v24.4s, v0.s[2]
        FMLA v17.4s, v25.4s, v0.s[2]
        LDP q24, q25, [x5], 32
        FMLA v18.4s, v26.4s, v0.s[3]
        FMLA v19.4s, v27.4s, v0.s[3]
        LDP q26, q27, [x5], 32

        # Second block of 4.  no loads
        FMLA v16.4s, v20.4s, v1.s[0]
        FMLA v17.4s, v21.4s, v1.s[0]
        FMLA v18.4s, v22.4s, v1.s[1]
        FMLA v19.4s, v23.4s, v1.s[1]
        FMLA v16.4s, v24.4s, v1.s[2]
        FMLA v17.4s, v25.4s, v1.s[2]
        FMLA v18.4s, v26.4s, v1.s[3]
        FMLA v19.4s, v27.4s, v1.s[3]

3:
        # Is there a remainder?- 4 floats of A (16 bytes)
        TBNZ x0, 4, 5f
        # Is there a remainder?- 2 floats of A (8 bytes)
        TBNZ x0, 3, 6f
        # Is there a remainder?- 1 floats of A (4 bytes)
        TBNZ x0, 2, 8f

4:
        FADD v16.4s, v16.4s, v18.4s
        FADD v17.4s, v17.4s, v19.4s

        # Clamp
        FMIN v16.4s, v16.4s, v4.4s
        FMIN v17.4s, v17.4s, v4.4s
        FMAX v16.4s, v16.4s, v5.4s
        FMAX v17.4s, v17.4s, v5.4s

        # Store full 1 x 8
        CMP x1, 8
        B.LO 9f

        STP q16, q17, [x6]
        ADD x6, x6, x14

        SUB  x3,  x3, x2 // a0 -= kc

        SUBS x1, x1, 8
        B.HI 0b

        RET

5:
        # Remainder- 4 floats of A (16 bytes)
        LDP q20, q21, [x5], 32
        LDR q0, [x3], 16
        FMLA v16.4s, v20.4s, v0.s[0]
        FMLA v17.4s, v21.4s, v0.s[0]
        LDP q22, q23, [x5], 32
        LDP q24, q25, [x5], 32
        LDP q26, q27, [x5], 32
        FMLA v18.4s, v22.4s, v0.s[1]
        FMLA v19.4s, v23.4s, v0.s[1]
        FMLA v16.4s, v24.4s, v0.s[2]
        FMLA v17.4s, v25.4s, v0.s[2]
        FMLA v18.4s, v26.4s, v0.s[3]
        FMLA v19.4s, v27.4s, v0.s[3]

        TBZ x0, 3, 7f
6:
        # Remainder- 2 floats of A (8 bytes)
        LDP q20, q21, [x5], 32
        LDR d0, [x3], 8
        FMLA v16.4s, v20.4s, v0.s[0]
        FMLA v17.4s, v21.4s, v0.s[0]
        LDP q22, q23, [x5], 32
        FMLA v18.4s, v22.4s, v0.s[1]
        FMLA v19.4s, v23.4s, v0.s[1]
7:
        TBZ x0, 2, 4b
8:
        # Remainder- 1 float of A (4 bytes)
        LDP q20, q21, [x5], 32
        LDR s0, [x3], 4
        FMLA v16.4s, v20.4s, v0.s[0]
        FMLA v17.4s, v21.4s, v0.s[0]
        B 4b

        # Store odd channels
9:
        TBZ x1, 2, 10f
        STR q16, [x6], 16
        MOV v16.16b, v17.16b

10:
        TBZ x1, 1, 11f
        STR d16, [x6], 8
        DUP d16, v16.d[1]

11:
        TBZ x1, 0, 12f
        STR s16, [x6]
12:
        RET

END_FUNCTION xnn_f32_gemminc_ukernel_1x8__aarch64_neonfma_cortex_a57

#ifdef __ELF__
.section ".note.GNU-stack","",%progbits
#endif

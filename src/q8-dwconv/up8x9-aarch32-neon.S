# Copyright (c) Facebook, Inc. and its affiliates.
# All rights reserved.
#
# Copyright 2019 Google LLC
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree.

#include <xnnpack/assembly.h>

.syntax unified

# void xnn_q8_dwconv_ukernel_up8x9__aarch32_neon(
#     size_t channels,
#     size_t output_width,
#     const uint8_t** input,
#     const void* weights,
#     uint8_t* output,
#     size_t input_stride,
#     size_t output_increment,
#     const union xnn_q8_gemm_params params[restrict static 1])
BEGIN_FUNCTION xnn_q8_dwconv_ukernel_up8x9__aarch32_neon
	.arm
#ifndef __APPLE__
	.arch armv7-a
	.fpu neon
#endif

	# Load params
	# - r12 = params
	LDR r12, [sp, 12]

	PUSH {r4, r5, r6, r7, r8, r9, r10, r11, lr}
	VPUSH {d8-d15}

	STR r0, [sp, #-8]
	STR r3, [sp, #-4]

	MOV r4, 4

	# Load o:
	# - lr = o = output
	LDR lr, [sp, 100]

	# Load kernel zero point:
	# - d31 = vkernel_zero_point
	VLD1.8 {d31[]}, [r12], r4

	# Load multiplier:
	# - q14 = d28:d29 = vmultiplier
	VLD1.32 {d28[], d29[]}, [r12]!

	# Load right shift:
	# - q13 = d26:d27 = vright_shift
	VLD1.32 {d26[], d27[]}, [r12]!

	# Load output zero point:
	# - q12 = d24:d25 = voutput_zero_point
	VLD1.16 {d24[], d25[]}, [r12]!

	# Compute vzero_shift_mask
	# - q11 = vzero_shift_mask
	VCEQ.S32 q11, q13, 0

	# Load output max:
	# - d20 = voutput_max
	VLD1.8 {d20[]}, [r12]!

	# Load output min:
	# - d21 = voutput_min
	VLD1.8 {d21[]}, [r12]

	.p2align 3
0:
	# Load input stride
	# - r3 = input_stride
	LDR r3, [sp, 104]

	# Load c:
	# - r0 = c = channels
	LDR r0, [sp, #-8]

	# Load i0, i1, i2, i3, i4, i5, i6, i7, i8
	# - r4 = i0
	# - r5 = i1
	# - r6 = i2
	# - r7 = i3
	# - r8 = i4
	# - r9 = i5
	# - r10 = i6
	# - r11 = i7
	# - r12 = i8
	LDM r2, {r4, r5, r6, r7, r8, r9, r10, r11, r12}

	# Pre-decrement c
	SUBS r0, r0, 8

	# Increment input by input stride
	# - input = r2 := input + input_stride
	ADD r2, r2, r3

	# Load w:
	# - r3 = w = weights
	LDR r3, [sp, #-4]

	BLO 2f

	.p2align 4
1:
	VLDM r3!, {d0-d3}

	VLD1.8 {d4}, [r4]!
	VLD1.8 {d6}, [r3]!

	VLD1.8 {d8}, [r5]!
	VLD1.8 {d10}, [r3]!

	VMOVL.U8 q2, d4
	VSUBL.U8 q3, d6, d31

	VLD1.8 {d12}, [r6]!
	VLD1.8 {d14}, [r3]!

	VMOVL.U8 q4, d8
	VSUBL.U8 q5, d10, d31

	VMLAL.S16 q0, d4, d6
	VMLAL.S16 q1, d5, d7

	VLD1.8 {d4}, [r7]!
	VLD1.8 {d6}, [r3]!

	VMOVL.U8 q6, d12
	VSUBL.U8 q7, d14, d31

	VMLAL.S16 q0, d8, d10
	VMLAL.S16 q1, d9, d11

	VLD1.8 {d8}, [r8]!
	VLD1.8 {d10}, [r3]!

	VMOVL.U8 q2, d4
	VSUBL.U8 q3, d6, d31

	VMLAL.S16 q0, d12, d14
	VMLAL.S16 q1, d13, d15

	VLD1.8 {d12}, [r9]!
	VLD1.8 {d14}, [r3]!

	VMOVL.U8 q4, d8
	VSUBL.U8 q5, d10, d31

	VMLAL.S16 q0, d4, d6
	VMLAL.S16 q1, d5, d7

	VLD1.8 {d4}, [r10]!
	VLD1.8 {d6}, [r3]!

	VMOVL.U8 q6, d12
	VSUBL.U8 q7, d14, d31

	VMLAL.S16 q0, d8, d10
	VMLAL.S16 q1, d9, d11

	VLD1.8 {d8}, [r11]!
	VLD1.8 {d10}, [r3]!

	VMOVL.U8 q2, d4
	VSUBL.U8 q3, d6, d31

	VMLAL.S16 q0, d12, d14
	VMLAL.S16 q1, d13, d15

	VLD1.8 {d12}, [r12]!
	VLD1.8 {d14}, [r3]!

	VMOVL.U8 q4, d8
	VSUBL.U8 q5, d10, d31

	VMLAL.S16 q0, d4, d6
	VMLAL.S16 q1, d5, d7

	VMOVL.U8 q6, d12
	VSUBL.U8 q7, d14, d31

	VMLAL.S16 q0, d8, d10
	VMLAL.S16 q1, d9, d11

	VMLAL.S16 q0, d12, d14
	VMLAL.S16 q1, d13, d15

	VQRDMULH.S32 q0, q0, q14
	VQRDMULH.S32 q1, q1, q14

	VBIC q2, q0, q11
	VBIC q3, q1, q11

	VSRA.S32 q0, q2, 31
	VSRA.S32 q1, q3, 31

	VRSHL.S32 q0, q0, q13
	VRSHL.S32 q1, q1, q13

	VQMOVN.S32 d0, q0
	VQMOVN.S32 d1, q1

	VQADD.S16 q0, q12
	VQMOVUN.S16 d0, q0
	VMIN.U8 d0, d0, d20
	VMAX.U8 d0, d0, d21

	VST1.8 {d0}, [lr]!
	SUBS r0, r0, 8
	BHS 1b

2:
	CMP r0, -8
	BEQ 5f

	VLDM r3!, {d0-d3}

	VLD1.8 {d4}, [r4]!
	VLD1.8 {d6}, [r3]!

	VLD1.8 {d8}, [r5]!
	VLD1.8 {d10}, [r3]!

	VMOVL.U8 q2, d4
	VSUBL.U8 q3, d6, d31

	VLD1.8 {d12}, [r6]!
	VLD1.8 {d14}, [r3]!

	VMOVL.U8 q4, d8
	VSUBL.U8 q5, d10, d31

	VMLAL.S16 q0, d4, d6
	VMLAL.S16 q1, d5, d7

	VLD1.8 {d4}, [r7]!
	VLD1.8 {d6}, [r3]!

	VMOVL.U8 q6, d12
	VSUBL.U8 q7, d14, d31

	VMLAL.S16 q0, d8, d10
	VMLAL.S16 q1, d9, d11

	VLD1.8 {d8}, [r8]!
	VLD1.8 {d10}, [r3]!

	VMOVL.U8 q2, d4
	VSUBL.U8 q3, d6, d31

	VMLAL.S16 q0, d12, d14
	VMLAL.S16 q1, d13, d15

	VLD1.8 {d12}, [r9]!
	VLD1.8 {d14}, [r3]!

	VMOVL.U8 q4, d8
	VSUBL.U8 q5, d10, d31

	VMLAL.S16 q0, d4, d6
	VMLAL.S16 q1, d5, d7

	VLD1.8 {d4}, [r10]!
	VLD1.8 {d6}, [r3]!

	VMOVL.U8 q6, d12
	VSUBL.U8 q7, d14, d31

	VMLAL.S16 q0, d8, d10
	VMLAL.S16 q1, d9, d11

	VLD1.8 {d8}, [r11]!
	VLD1.8 {d10}, [r3]!

	VMOVL.U8 q2, d4
	VSUBL.U8 q3, d6, d31

	VMLAL.S16 q0, d12, d14
	VMLAL.S16 q1, d13, d15

	VLD1.8 {d12}, [r12]!
	VLD1.8 {d14}, [r3]!

	VMOVL.U8 q4, d8
	VSUBL.U8 q5, d10, d31

	VMLAL.S16 q0, d4, d6
	VMLAL.S16 q1, d5, d7

	VMOVL.U8 q6, d12
	VSUBL.U8 q7, d14, d31

	VMLAL.S16 q0, d8, d10
	VMLAL.S16 q1, d9, d11

	VMLAL.S16 q0, d12, d14
	VMLAL.S16 q1, d13, d15

	VQRDMULH.S32 q0, q0, q14
	VQRDMULH.S32 q1, q1, q14

	VBIC q2, q0, q11
	VBIC q3, q1, q11

	VSRA.S32 q0, q2, 31
	VSRA.S32 q1, q3, 31

	VRSHL.S32 q0, q0, q13
	VRSHL.S32 q1, q1, q13

	VQMOVN.S32 d0, q0
	VQMOVN.S32 d1, q1

	VQADD.S16 q0, q12
	VQMOVUN.S16 d0, q0
	VMIN.U8 d0, d0, d20
	VMAX.U8 d0, d0, d21

	TST r0, 4
	BEQ 3f
	VST1.32 {d0[0]}, [lr]!
	VEXT.8 d0, d0, 4

3:
	TST r0, 2
	BEQ 4f
	VST1.16 {d0[0]}, [lr]!
	VEXT.8 d0, d0, 2

4:
	TST r0, 1
	BEQ 5f
	VST1.8 {d0[0]}, [lr]!

5:
	# Load output increment
	# - r3 = output_increment
	LDR r3, [sp, 108]

	# Decrement output width
	SUBS r1, r1, 1

	# Increment output by output_increment
	ADD lr, lr, r3

	# If output width is non-zero, process another pixel
	BNE 0b

	VPOP {d8-d15}
	POP {r4, r5, r6, r7, r8, r9, r10, r11, pc}
END_FUNCTION xnn_q8_dwconv_ukernel_up8x9__aarch32_neon

#ifdef __ELF__
.section ".note.GNU-stack","",%progbits
#endif

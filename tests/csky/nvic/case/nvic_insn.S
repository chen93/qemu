/* ---------------------------------------------------------------------------
 * Copyright (C) 2016 CSKY Limited. All rights reserved.
 *
 * Redistribution and use of this software in source and binary forms,
 * with or without modification, are permitted provided that the following
 * conditions are met:
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *   * Neither the name of CSKY Ltd. nor the names of CSKY's contributors may
 *     be used to endorse or promote products derived from this software without
 *     specific prior written permission of CSKY Ltd.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
 * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 * -------------------------------------------------------------------------- */
   .file   "nvic_insn.S"

#undef  TEST_FUNC
#define TEST_FUNC(name) TEST_FUNC_M name
    .macro TEST_FUNC_M name
    .text
    .align  2
    .global \name
    .type   \name, @function
\name:
    .endm

TEST_FUNC(test_ipop)
    push    r4-r11, r15
    lrw     r4, 0x00000000
    lrw     r5, 0x00000001
    lrw     r6, 0x12345678
    lrw     r7, 0x7fffffff
    lrw     r8, 0x80000000
    lrw     r9, 0xffffffff
    push    r4-r9
    ipop
    cmpne   r0, r4
    bt      ipop_false
    cmpne   r1, r5
    bt      ipop_false
    cmpne   r2, r6
    bt      ipop_false
    cmpne   r3, r7
    bt      ipop_false
    cmpne   r12, r8
    bt      ipop_false
    cmpne   r13, r9
    bt      ipop_false
    movi    a0, 0
    br      ipop_end
ipop_false:
    movi    a0, 1
ipop_end:
    pop r4-r11, r15
    rts
    .size   test_ipop, .-test_ipop

TEST_FUNC(test_ipush)
    push    r4-r8
    lrw     r0, 0x00000000
    lrw     r1, 0x00000001
    lrw     r2, 0x12345678
    lrw     r3, 0x7fffffff
    lrw     r12, 0x80000000
    lrw     r13, 0xffffffff
    ipush
    mov     r8, sp
    ld.w    r4, (r8, 0)
    cmpne   r0, r4
    bt      ipush_false
    ld.w    r4, (r8, 4)
    cmpne   r1, r4
    bt      ipush_false
    ld.w    r4, (r8, 8)
    cmpne   r2, r4
    bt      ipush_false
    ld.w    r4, (r8, 12)
    cmpne   r3, r4
    bt      ipush_false
    ld.w    r4, (r8, 16)
    cmpne   r12, r4
    bt      ipush_false
    ld.w    r4, (r8, 20)
    cmpne   r13, r4
    bt      ipush_false
    movi    a0, 0
    br      ipush_end
ipush_false:
    movi    a0, 1
ipush_end:
    addi sp, sp, 24
    pop     r4-r8
    rts
    .size   test_ipush, .-test_ipush

TEST_FUNC(test_nie)
    push r4-r11, r15
    psrclr  ee, ie
    mfcr    r4, cr<2,0>   //epsr
    mfcr    r5, cr<4,0>   //epc
    nie
    mov     r8, sp
    ld.w    r6, (r8, 0)
    cmpne   r4, r6
    bt      nie_fail
    ld.w    r6, (r8, 4)
    cmpne   r5, r6
    bt      nie_fail
    mfcr    r4, cr<0,0>   //psr
    andi    r4, r4, 0x140 //psr{ee, ie} = 1
    cmpnei  r4, 0x140
    bt      nie_fail
    movi    a0, 0
    br      nie_end
nie_fail:
    movi    a0, 1
nie_end:
    addi sp, sp, 8
    pop r4-r11, r15
    rts
    .size   test_nie, .-test_nie

TEST_FUNC(test_sub_nir)
    mfcr    r4, cr<0,0>   //psr
    push    r4, r15
    mov     a0, r4
    nir
    .size   test_sub_nir, .-test_sub_nir

TEST_FUNC(test_nir)
    push r4, r15
    bsr test_sub_nir
    mfcr    r4, cr<0,0>   //psr
    cmpne   a0, r4
    bt      nir_fail
    movi    a0, 0
    br      nir_end
nir_fail:
    movi    a1, 1
nir_end:
    pop r4, r15
    .size   test_nir, .-test_nir


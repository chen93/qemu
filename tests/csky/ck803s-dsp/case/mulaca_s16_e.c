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
#include "testsuite.h"
#include "test_device.h"
#include "dsp_insn.h"
#define TEST_TIMES      21
int main(void)
{
    int i = 0;

    init_testsuite("Testing insn MULACA.S16.E \n");

    /*
     * MULACA.S16.E
     * {rn, rz} = {rn, rz} + rx[15:0] * ry[15:0] + rx[31:16] * ry[31:16],
     * signed
     */
    struct ternary64_calculation ter64_sample[TEST_TIMES] = {
        {0x00010001, 0x00010001, 0x0000000000000001, 0x0000000000000003},
        {0x80007fff, 0x80007fff, 0x8000000000000000, 0x800000007fff0001},
        {0x80007fff, 0x80007fff, 0xffffffffffffffff, 0x000000007fff0000},
        {0x80007fff, 0x80007fff, 0x7fffffffffffffff, 0x800000007fff0000},
        {0x7fff7fff, 0x80008000, 0x8000000000000000, 0x7fffffff80010000},
        {0x7fff7fff, 0x80008000, 0xffffffffffffffff, 0xffffffff8000ffff},
        {0x7fff7fff, 0x80008000, 0x7fffffffffffffff, 0x7fffffff8000ffff},
        {0xffffffff, 0xffffffff, 0x8000000000000000, 0x8000000000000002},
        {0xffffffff, 0xffffffff, 0xffffffffffffffff, 0x0000000000000001},
        {0xffffffff, 0xffffffff, 0x7fffffffffffffff, 0x8000000000000001},
        {0xffffffff, 0x80008000, 0x8000000000000000, 0x8000000000010000},
        {0xffffffff, 0x80008000, 0xffffffffffffffff, 0x000000000000ffff},
        {0xffffffff, 0x80008000, 0x7fffffffffffffff, 0x800000000000ffff},
        {0x8000ffff, 0x8000ffff, 0x8000000000000000, 0x8000000040000001},
        {0x8000ffff, 0x8000ffff, 0xffffffffffffffff, 0x0000000040000000},
        {0x8000ffff, 0x8000ffff, 0x7fffffffffffffff, 0x8000000040000000},
        {0x00010000, 0xffffffff, 0x0000000000000000, 0xffffffffffffffff},
        {0x0001ffff, 0xffff0000, 0x0000000000000000, 0xffffffffffffffff},
        {0x00000001, 0xffffffff, 0x0000000000000000, 0xffffffffffffffff},
        {0x0000ffff, 0xffff0001, 0x0000000000000000, 0xffffffffffffffff},
        {0x00000000, 0x00000000, 0x0000000000000000, 0x0000000000000000},
    };

    for (i = 0; i < TEST_TIMES; i++) {
        TEST(test_mulaca_s16_e(ter64_sample[i].op1, ter64_sample[i].op2,
                               ter64_sample[i].op3) == ter64_sample[i].result);
    }

    return done_testing();
}


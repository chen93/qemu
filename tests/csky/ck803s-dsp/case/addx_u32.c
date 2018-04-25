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
#define TEST_TIMES      22
int main(void)
{
    int i = 0;

    init_testsuite("Testing insn ADDX.U32 \n");

    /*
     * ADDX.U32
     * rz = rx + ry[15:0], unsigned
     *
     * TEST(test_addx_u32(0x12345678, 0x12345678) == 0x2468acf0)
     */
    struct binary_calculation bin_sample[TEST_TIMES] = {
        {0x12345678, 0x12345678, 0x1234acf0},
        {0x12345678, 0x7f000000, 0x12345678},
        {0xffffffff, 0x11111111, 0x00001110},
        {0x12345678, 0x88888888, 0x1234df00},
        {0x00000000, 0x80000000, 0x00000000},
        {0X00000000, 0X00000000, 0x00000000},
        {0X00000000, 0X00000001, 0x00000001},
        {0X00000000, 0XFFFFFFFF, 0x0000ffff},
        {0X00000001, 0X00000000, 0x00000001},
        {0X00000001, 0X00000001, 0x00000002},
        {0X00000001, 0XFFFFFFFF, 0x00010000},
        {0XFFFFFFFF, 0X00000000, 0xffffffff},
        {0XFFFFFFFF, 0X00000001, 0x00000000},
        {0XFFFFFFFF, 0XFFFFFFFF, 0x0000fffe},
        {0X00000000, 0XFFFF0000, 0x00000000},
        {0X00000000, 0X00008000, 0x00008000},
        {0X00000001, 0XFFFF0000, 0x00000001},
        {0X00000001, 0X00008000, 0x00008001},
        {0XFFFFFFFF, 0XFFFF0000, 0xffffffff},
        {0XFFFFFFFF, 0X00008000, 0x00007fff},
        {0X7FFFFFFF, 0XFFFF7FFF, 0x80007ffe},
        {0X80000000, 0X00008000, 0x80008000},
    };

    for (i = 0; i < TEST_TIMES; i++) {
        TEST(test_addx_u32(bin_sample[i].op1, bin_sample[i].op2)
                     == bin_sample[i].result);
    }

    return done_testing();
}


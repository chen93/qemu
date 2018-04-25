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
#define TEST_TIMES      12
int main(void)
{
    int i = 0;

    init_testsuite("Testing insn MULCS.S16 \n");

    /*
     * MULCS.S16
     * rz = rx[15:0] * ry[15:0] - rx[31:16] * ry[31:16], signed
     */
    struct binary_calculation bin_sample[TEST_TIMES] = {
        {0x00010001, 0x00000001, 0x00000001},
        {0x00010001, 0x7FFF7FFF, 0x00000000},
        {0x00010010, 0x80007FFF, 0x00087FF0},
        {0x00010001, 0x0000FFFF, 0xFFFFFFFF},
        {0x00010002, 0x7FFF8000, 0xFFFE8001},
        {0x00017FFF, 0x8000FFFF, 0x00000001},
        {0x0001FFFF, 0x0000FFFF, 0x00000001},
        {0x0001FFFF, 0x7FFF8000, 0x00000001},
        {0x00018000, 0x80008000, 0x40008000},
        {0x00010000, 0x00000000, 0x00000000},
        {0x00010000, 0x7FFF7FFF, 0xFFFF8001},
        {0x00010000, 0x80008000, 0x00008000},
    };

    for (i = 0; i < TEST_TIMES; i++) {
        TEST(test_mulcs_s16(bin_sample[i].op1, bin_sample[i].op2)
                     == bin_sample[i].result);
    }

    return done_testing();
}


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
#define TEST_TIMES      17
int main(void)
{
    int i = 0;

    init_testsuite("Testing insn MULA.32.LF \n");

    /*
     * MULA.32.LF
     * rz = rn + (rx * ry) << 1, fraction
     */
    struct ternary_calculation ter_sample[TEST_TIMES] = {
        {0x00000001, 0x00000001, 0x00000000, 0x00000002},
        {0x00000002, 0x20000000, 0x00000000, 0x80000000},
        {0x00000001, 0x7FFFFFFF, 0x00000000, 0xFFFFFFFE},
        {0x00000001, 0x00000001, 0x00000001, 0x00000003},
        {0x00000001, 0xFFFFFFFF, 0x80000000, 0x7FFFFFFE},
        {0x00000002, 0x80000000, 0x00000000, 0x00000000},
        {0x00000002, 0x80000001, 0x00000000, 0x00000004},
        {0xFFFFFFFF, 0xFFFFFFFF, 0x00000000, 0x00000002},
        {0x80000000, 0x80000000, 0x00000000, 0x00000000},
        {0x00000100, 0x10000001, 0xFFFFFFFF, 0x000001FF},
        {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000001},
        {0x00000000, 0x00000001, 0x00000000, 0x00000000},
        {0x00000000, 0x00000000, 0x00000000, 0x00000000},
        {0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000},
        {0x00000000, 0x00000001, 0x00000001, 0x00000001},
        {0x00000000, 0x00000000, 0x00000001, 0x00000001},
        {0x00000000, 0xFFFFFFFF, 0x00000001, 0x00000001},
    };

    for (i = 0; i < TEST_TIMES; i++) {
        TEST(test_mula_32_lf(ter_sample[i].op1, ter_sample[i].op2,
                            ter_sample[i].op3) == ter_sample[i].result);
    }

    return done_testing();
}


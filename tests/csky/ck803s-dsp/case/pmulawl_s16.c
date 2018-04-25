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
#define TEST_TIMES      7
int main(void)
{
    int i = 0;

    init_testsuite("Testing insn PMULAWL.S16 \n");

    /*
     * PMULAWL.S16
     * rz = rz + rx[15:0] * ry[15:0], rn = rn + rx[31:16] * ry[15:0],
     * signed
     */
    struct ternary64_calculation sample[TEST_TIMES] = {
        {0x7fff8000, 0x80008000, 0x00000000ffffffff, 0xc00080003fffffff},
        {0x76540000, 0x8000abcd, 0x80000000ffffffff, 0x5914dd44ffffffff},
        {0x76540000, 0x7fff7654, 0x0000000000000000, 0x36b18b9000000000},
        {0xabcd0000, 0x80000000, 0x0123456789abcdef, 0x0123456789abcdef},
        {0xabcdffff, 0x7fffabcd, 0x0000000100000001, 0x1bb1822a00005434},
        {0x7fffffff, 0x7fff7654, 0x7fffffffffffffff, 0xbb2989abffff89ab},
        {0xffffffff, 0xffffffff, 0x7fffffff7fffffff, 0x8000000080000000},
    };

    for (i = 0; i < TEST_TIMES; i++) {
        TEST(test_pmulawl_s16(sample[i].op1, sample[i].op2, sample[i].op3)
                     == sample[i].result);
    }

    return done_testing();
}


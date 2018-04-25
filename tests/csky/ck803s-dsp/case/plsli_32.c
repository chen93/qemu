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
#define TEST_TIMES      4
int main(void)
{
    init_testsuite("Testing insn PLSLI.32 \n");

    /*
     * PLSLI.32
     * rz = rx << imm5, r(z+1) = r(x+1) << imm5
     */
    struct binary64_calculation sample[TEST_TIMES] = {
        {0Xffffffff, 0X00000000, 0x00000000ffffffff}, /* imm = 0 */
        {0X12345678, 0X00000001, 0x000000022468ACF0}, /* imm = 1 */
        {0Xffffffff, 0X7fffffff, 0xfff00000fff00000}, /* imm = 20 */
        {0X80000000, 0X7fffffff, 0x8000000000000000}, /* imm = 31 */
    };

    TEST(test_plsli_32_0(sample[0].op1, sample[0].op2) == sample[0].result);
    TEST(test_plsli_32_1(sample[1].op1, sample[1].op2) == sample[1].result);
    TEST(test_plsli_32_20(sample[2].op1, sample[2].op2) == sample[2].result);
    TEST(test_plsli_32_31(sample[3].op1, sample[3].op2) == sample[3].result);
    return done_testing();
}


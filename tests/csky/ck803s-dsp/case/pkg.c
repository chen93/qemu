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
    init_testsuite("Testing insn PKG \n");

    /*
     * PKG
     * rz = {(ry >> oimm4)[15:0], (rx >> imm4)[15:0], logical shift
     */
    struct binary_calculation bin_sample[TEST_TIMES] = {
        {0Xffff0000, 0X0000ffff, 0x00000000}, /* imm = 0,  oimm = 16 */
        {0X00007fff, 0X0001fffe, 0xffff0000}, /* imm = 15, oimm = 1  */
        {0Xffff0000, 0X0000ffff, 0x7fff0000}, /* imm = 0,  oimm = 1  */
        {0X00007fff, 0X0001fffe, 0x00010000}, /* imm = 15, oimm = 16 */
    };

    TEST(test_pkg_0_16(bin_sample[0].op1, bin_sample[0].op2)
         == bin_sample[0].result);
    TEST(test_pkg_15_1(bin_sample[1].op1, bin_sample[1].op2)
         == bin_sample[1].result);
    TEST(test_pkg_0_1(bin_sample[2].op1, bin_sample[2].op2)
         == bin_sample[2].result);
    TEST(test_pkg_15_16(bin_sample[3].op1, bin_sample[3].op2)
         == bin_sample[3].result);
    return done_testing();
}


#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn lsli.s32.s\n");

    for (i = 0;
         i < sizeof(samples_lsli_s32_s)/sizeof(struct binary_calculation);
         i++) {
        if (samples_lsli_s32_s[i].op2 == 32) {
            TEST(test_lsli_s32_s_32(samples_lsli_s32_s[i].op1)
                 == samples_lsli_s32_s[i].result);
        } else if (samples_lsli_s32_s[i].op2 == 2) {
            TEST(test_lsli_s32_s_2(samples_lsli_s32_s[i].op1)
                 == samples_lsli_s32_s[i].result);
        } else if (samples_lsli_s32_s[i].op2 == 4) {
            TEST(test_lsli_s32_s_4(samples_lsli_s32_s[i].op1)
                 == samples_lsli_s32_s[i].result);
        } else if (samples_lsli_s32_s[i].op2 == 31) {
            TEST(test_lsli_s32_s_31(samples_lsli_s32_s[i].op1)
                 == samples_lsli_s32_s[i].result);
        }
    }
    return done_testing();
}

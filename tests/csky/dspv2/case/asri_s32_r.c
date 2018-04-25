#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn asri.s32.r\n");

    for (i = 0;
         i < sizeof(samples_asri_s32_r)/sizeof(struct binary_calculation);
         i++) {
        if (samples_asri_s32_r[i].op2 == 32) {
            TEST(test_asri_s32_r_32(samples_asri_s32_r[i].op1)
                 == samples_asri_s32_r[i].result);
        } else if (samples_asri_s32_r[i].op2 == 1) {
            TEST(test_asri_s32_r_1(samples_asri_s32_r[i].op1)
                 == samples_asri_s32_r[i].result);
        } else if (samples_asri_s32_r[i].op2 == 2) {
            TEST(test_asri_s32_r_2(samples_asri_s32_r[i].op1)
                 == samples_asri_s32_r[i].result);
        } else if (samples_asri_s32_r[i].op2 == 31) {
            TEST(test_asri_s32_r_31(samples_asri_s32_r[i].op1)
                 == samples_asri_s32_r[i].result);
        }
    }
    return done_testing();
}

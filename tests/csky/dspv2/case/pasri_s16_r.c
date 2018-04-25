#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn pasri.s16.r\n");

    for (i = 0;
         i < sizeof(samples_pasri_s16_r)/sizeof(struct binary_calculation);
         i++) {
        if (samples_pasri_s16_r[i].op2 == 1) {
            TEST(test_pasri_s16_r_1(samples_pasri_s16_r[i].op1)
                 == samples_pasri_s16_r[i].result);
        } else if (samples_pasri_s16_r[i].op2 == 2) {
            TEST(test_pasri_s16_r_2(samples_pasri_s16_r[i].op1)
                 == samples_pasri_s16_r[i].result);
        } else if (samples_pasri_s16_r[i].op2 == 15) {
            TEST(test_pasri_s16_r_15(samples_pasri_s16_r[i].op1)
                 == samples_pasri_s16_r[i].result);
        }
    }
    return done_testing();
}

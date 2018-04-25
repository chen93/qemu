#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn pasri.s16\n");

    for (i = 0;
         i < sizeof(samples_pasri_s16)/sizeof(struct binary_calculation);
         i++) {
        if (samples_pasri_s16[i].op2 == 1) {
            TEST(test_pasri_s16_1(samples_pasri_s16[i].op1)
                 == samples_pasri_s16[i].result);
        } else if (samples_pasri_s16[i].op2 == 2) {
            TEST(test_pasri_s16_2(samples_pasri_s16[i].op1)
                 == samples_pasri_s16[i].result);
        } else if (samples_pasri_s16[i].op2 == 15) {
            TEST(test_pasri_s16_15(samples_pasri_s16[i].op1)
                 == samples_pasri_s16[i].result);
        } else if (samples_pasri_s16[i].op2 == 16) {
            TEST(test_pasri_s16_16(samples_pasri_s16[i].op1)
                 == samples_pasri_s16[i].result);
        }
    }
    return done_testing();
}

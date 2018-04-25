#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn dexti\n");

    for (i = 0;
         i < sizeof(samples_dexti)/sizeof(struct ternary_calculation);
         i++) {
        if (samples_dexti[i].op3 == 0) {
            TEST(test_dexti_0(samples_dexti[i].op1, samples_dexti[i].op2)
                            == samples_dexti[i].result);
        } else if (samples_dexti[i].op3 == 2) {
            TEST(test_dexti_2(samples_dexti[i].op1, samples_dexti[i].op2)
                            == samples_dexti[i].result);
        } else if (samples_dexti[i].op3 == 5) {
            TEST(test_dexti_5(samples_dexti[i].op1, samples_dexti[i].op2)
                            == samples_dexti[i].result);
        } else if (samples_dexti[i].op3 == 31) {
            TEST(test_dexti_31(samples_dexti[i].op1, samples_dexti[i].op2)
                            == samples_dexti[i].result);
        }
    }
    return done_testing();
}

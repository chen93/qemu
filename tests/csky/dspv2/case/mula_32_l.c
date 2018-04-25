#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn mula.32.l\n");

    for (i = 0;
         i < sizeof(samples_mula_32_l)/sizeof(struct ternary_calculation);
         i++) {
        TEST(test_mula_32_l(samples_mula_32_l[i].op1, samples_mula_32_l[i].op2,
                           samples_mula_32_l[i].op3)
                     == samples_mula_32_l[i].result);
    }
    return done_testing();
}

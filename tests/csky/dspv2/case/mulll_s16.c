#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn mulll.s16\n");

    for (i = 0;
         i < sizeof(samples_mulll_s16)/sizeof(struct binary_calculation);
         i++) {
        TEST(test_mulll_s16(samples_mulll_s16[i].op1, samples_mulll_s16[i].op2)
                     == samples_mulll_s16[i].result);
    }
    return done_testing();
}

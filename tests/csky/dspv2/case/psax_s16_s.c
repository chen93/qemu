#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn psax.s16.s\n");

    for (i = 0;
         i < sizeof(samples_psax_s16_s)/sizeof(struct binary_calculation);
         i++) {
        TEST(test_psax_s16_s(samples_psax_s16_s[i].op1, samples_psax_s16_s[i].op2)
                     == samples_psax_s16_s[i].result);
    }
    return done_testing();
}

#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn psax.16\n");

    for (i = 0;
         i < sizeof(samples_psax_16)/sizeof(struct binary_calculation);
         i++) {
        TEST(test_psax_16(samples_psax_16[i].op1, samples_psax_16[i].op2)
                     == samples_psax_16[i].result);
    }
    return done_testing();
}

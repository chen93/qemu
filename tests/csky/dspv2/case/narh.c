#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn narh\n");

    for (i = 0;
         i < sizeof(samples_narh)/sizeof(struct binary_calculation);
         i++) {
        TEST(test_narh(samples_narh[i].op1, samples_narh[i].op2)
                     == samples_narh[i].result);
    }
    return done_testing();
}

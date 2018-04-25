#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn pkghh\n");

    for (i = 0;
         i < sizeof(samples_pkghh)/sizeof(struct binary_calculation);
         i++) {
        TEST(test_pkghh(samples_pkghh[i].op1, samples_pkghh[i].op2)
                     == samples_pkghh[i].result);
    }
    return done_testing();
}

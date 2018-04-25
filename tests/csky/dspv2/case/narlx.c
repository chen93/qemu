#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn narlx\n");

    for (i = 0;
         i < sizeof(samples_narlx)/sizeof(struct binary_calculation);
         i++) {
        TEST(test_narlx(samples_narlx[i].op1, samples_narlx[i].op2)
                     == samples_narlx[i].result);
    }
    return done_testing();
}

#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn narhx\n");

    for (i = 0;
         i < sizeof(samples_narhx)/sizeof(struct binary_calculation);
         i++) {
        TEST(test_narhx(samples_narhx[i].op1, samples_narhx[i].op2)
                     == samples_narhx[i].result);
    }
    return done_testing();
}

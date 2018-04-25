#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn sub.64\n");

    for (i = 0;
         i < sizeof(samples_sub_64)/sizeof(struct binary64_64_64_calculation);
         i++) {
        TEST(test_sub_64(samples_sub_64[i].op1, samples_sub_64[i].op2)
                     == samples_sub_64[i].result);
    }
    return done_testing();
}

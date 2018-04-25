#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn narl\n");

    for (i = 0;
         i < sizeof(samples_narl)/sizeof(struct binary_calculation);
         i++) {
        TEST(test_narl(samples_narl[i].op1, samples_narl[i].op2)
                     == samples_narl[i].result);
    }
    return done_testing();
}

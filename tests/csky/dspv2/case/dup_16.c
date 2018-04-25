#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn dup.16\n");

    for (i = 0;
         i < sizeof(samples_dup_16)/sizeof(struct binary_calculation);
         i++) {
        if (samples_dup_16[i].op2 == 0) {
            TEST(test_dup_16_0(samples_dup_16[i].op1)
                 == samples_dup_16[i].result);
        } else if (samples_dup_16[i].op2 == 1) {
            TEST(test_dup_16_1(samples_dup_16[i].op1)
                 == samples_dup_16[i].result);
        }
    }
    return done_testing();
}

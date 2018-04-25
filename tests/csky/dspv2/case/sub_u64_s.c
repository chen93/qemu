#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn sub.u64.s\n");

    for (i = 0;
         i < sizeof(samples_sub_u64_s)/sizeof(struct binary64_64_64_calculation);
         i++) {
        TEST(test_sub_u64_s(samples_sub_u64_s[i].op1, samples_sub_u64_s[i].op2)
                     == samples_sub_u64_s[i].result);
    }
    return done_testing();
}

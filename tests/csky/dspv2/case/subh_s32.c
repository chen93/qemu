#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn subh.s32\n");

    for (i = 0;
         i < sizeof(samples_subh_s32)/sizeof(struct binary_calculation);
         i++) {
        TEST(test_subh_s32(samples_subh_s32[i].op1, samples_subh_s32[i].op2)
                     == samples_subh_s32[i].result);
    }
    return done_testing();
}

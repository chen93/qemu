#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn mul.s32.rh\n");

    for (i = 0;
         i < sizeof(samples_mul_s32_rh)/sizeof(struct binary_calculation);
         i++) {
        TEST(test_mul_s32_rh(samples_mul_s32_rh[i].op1, samples_mul_s32_rh[i].op2)
                     == samples_mul_s32_rh[i].result);
    }
    return done_testing();
}

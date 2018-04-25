#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn mulaxl.s32.rs\n");

    for (i = 0;
         i < sizeof(samples_mulaxl_s32_rs)/sizeof(struct ternary_calculation);
         i++) {
        TEST(test_mulaxl_s32_rs(samples_mulaxl_s32_rs[i].op1, samples_mulaxl_s32_rs[i].op2, samples_mulaxl_s32_rs[i].op3)
                     == samples_mulaxl_s32_rs[i].result);
    }
    return done_testing();
}

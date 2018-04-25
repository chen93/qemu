#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn muls.u32\n");

    for (i = 0;
         i < sizeof(samples_muls_u32)/sizeof(struct ternary64_calculation);
         i++) {
        TEST(test_muls_u32(samples_muls_u32[i].op1, samples_muls_u32[i].op2, samples_muls_u32[i].op3)
                     == samples_muls_u32[i].result);
    }
    return done_testing();
}

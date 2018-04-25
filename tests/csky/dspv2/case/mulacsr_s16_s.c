#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn mulacsr.s16.s\n");

    for (i = 0;
         i < sizeof(samples_mulacsr_s16_s)/sizeof(struct ternary_calculation);
         i++) {
        TEST(test_mulacsr_s16_s(samples_mulacsr_s16_s[i].op1, samples_mulacsr_s16_s[i].op2, samples_mulacsr_s16_s[i].op3)
                     == samples_mulacsr_s16_s[i].result);
    }
    return done_testing();
}

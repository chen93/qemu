#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn neg.s32.s\n");

    for (i = 0;
         i < sizeof(samples_neg_s32_s)/sizeof(struct unary_calculation);
         i++) {
        TEST(test_neg_s32_s(samples_neg_s32_s[i].op1)
                     == samples_neg_s32_s[i].result);
    }
    return done_testing();
}

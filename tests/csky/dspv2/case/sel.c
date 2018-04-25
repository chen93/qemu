#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn sel\n");

    for (i = 0;
         i < sizeof(samples_sel)/sizeof(struct ternary_calculation);
         i++) {
        TEST(test_sel(samples_sel[i].op1, samples_sel[i].op2, samples_sel[i].op3)
                     == samples_sel[i].result);
    }
    return done_testing();
}

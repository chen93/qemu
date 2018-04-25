#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn dext\n");

    for (i = 0;
         i < sizeof(samples_dext)/sizeof(struct ternary_calculation);
         i++) {
        TEST(test_dext(samples_dext[i].op1, samples_dext[i].op2, samples_dext[i].op3)
                     == samples_dext[i].result);
    }
    return done_testing();
}

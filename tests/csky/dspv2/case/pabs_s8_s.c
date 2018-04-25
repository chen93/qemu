#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn pabs.s8.s\n");

    for (i = 0;
         i < sizeof(samples_pabs_s8_s)/sizeof(struct unary_calculation);
         i++) {
        TEST(test_pabs_s8_s(samples_pabs_s8_s[i].op1)
                     == samples_pabs_s8_s[i].result);
    }
    return done_testing();
}

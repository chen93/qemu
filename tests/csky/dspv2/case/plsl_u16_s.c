#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn plsl.u16.s\n");

    for (i = 0;
         i < sizeof(samples_plsl_u16_s)/sizeof(struct binary_calculation);
         i++) {
        TEST(test_plsl_u16_s(samples_plsl_u16_s[i].op1, samples_plsl_u16_s[i].op2)
                     == samples_plsl_u16_s[i].result);
    }
    return done_testing();
}

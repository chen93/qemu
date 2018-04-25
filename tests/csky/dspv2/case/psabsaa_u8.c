#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn psabsaa.u8\n");

    for (i = 0;
         i < sizeof(samples_psabsaa_u8)/sizeof(struct ternary_calculation);
         i++) {
        TEST(test_psabsaa_u8(samples_psabsaa_u8[i].op1, samples_psabsaa_u8[i].op2, samples_psabsaa_u8[i].op3)
                     == samples_psabsaa_u8[i].result);
    }
    return done_testing();
}

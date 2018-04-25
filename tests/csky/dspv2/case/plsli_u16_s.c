#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn plsli.u16.s\n");

    for (i = 0;
         i < sizeof(samples_plsli_u16_s)/sizeof(struct binary_calculation);
         i++) {
        if (samples_plsli_u16_s[i].op2 == 1) {
        TEST(test_plsli_u16_s_1(samples_plsli_u16_s[i].op1)
                     == samples_plsli_u16_s[i].result);
        } else if (samples_plsli_u16_s[i].op2 == 9) {
        TEST(test_plsli_u16_s_9(samples_plsli_u16_s[i].op1)
                     == samples_plsli_u16_s[i].result);
        } else if (samples_plsli_u16_s[i].op2 == 16) {
        TEST(test_plsli_u16_s_16(samples_plsli_u16_s[i].op1)
                     == samples_plsli_u16_s[i].result);
        }
    }
    return done_testing();
}

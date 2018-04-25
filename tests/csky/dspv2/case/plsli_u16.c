#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn plsli.u16\n");

    for (i = 0;
         i < sizeof(samples_plsli_u16)/sizeof(struct binary_calculation);
         i++) {
        if (samples_plsli_u16[i].op2 == 1) {
        TEST(test_plsli_u16_1(samples_plsli_u16[i].op1)
                     == samples_plsli_u16[i].result);
        } else if (samples_plsli_u16[i].op2 == 9) {
        TEST(test_plsli_u16_9(samples_plsli_u16[i].op1)
                     == samples_plsli_u16[i].result);
        } else if (samples_plsli_u16[i].op2 == 16) {
        TEST(test_plsli_u16_16(samples_plsli_u16[i].op1)
                     == samples_plsli_u16[i].result);
        }
    }
    return done_testing();
}

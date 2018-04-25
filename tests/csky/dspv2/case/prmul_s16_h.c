#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn prmul.s16.h\n");

    for (i = 0;
         i < sizeof(samples_prmul_s16_h)/sizeof(struct binary_calculation);
         i++) {
        TEST(test_prmul_s16_h(samples_prmul_s16_h[i].op1, samples_prmul_s16_h[i].op2)
                     == samples_prmul_s16_h[i].result);
    }
    return done_testing();
}

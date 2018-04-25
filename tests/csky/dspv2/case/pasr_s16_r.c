#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn pasr.s16.r\n");

    for (i = 0;
         i < sizeof(samples_pasr_s16_r)/sizeof(struct binary_calculation);
         i++) {
        TEST(test_pasr_s16_r(samples_pasr_s16_r[i].op1, samples_pasr_s16_r[i].op2)
                     == samples_pasr_s16_r[i].result);
    }
    return done_testing();
}

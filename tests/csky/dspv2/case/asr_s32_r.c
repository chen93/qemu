#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn asr.s32.r\n");

    for (i = 0;
         i < sizeof(samples_asr_s32_r)/sizeof(struct binary_calculation);
         i++) {
        TEST(test_asr_s32_r(samples_asr_s32_r[i].op1, samples_asr_s32_r[i].op2)
                     == samples_asr_s32_r[i].result);
    }
    return done_testing();
}

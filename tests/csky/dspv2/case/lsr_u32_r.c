#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn lsr.u32.r\n");

    for (i = 0;
         i < sizeof(samples_lsr_u32_r)/sizeof(struct binary_calculation);
         i++) {
        TEST(test_lsr_u32_r(samples_lsr_u32_r[i].op1, samples_lsr_u32_r[i].op2)
                     == samples_lsr_u32_r[i].result);
    }
    return done_testing();
}

#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn max.u8\n");

    for (i = 0;
         i < sizeof(samples_pmax_u8)/sizeof(struct binary_calculation);
         i++) {
        TEST(test_pmax_u8(samples_pmax_u8[i].op1, samples_pmax_u8[i].op2)
                     == samples_pmax_u8[i].result);
    }
    return done_testing();
}

#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn pasxh.u16\n");

    for (i = 0;
         i < sizeof(samples_pasxh_u16)/sizeof(struct binary_calculation);
         i++) {
        TEST(test_pasxh_u16(samples_pasxh_u16[i].op1, samples_pasxh_u16[i].op2)
                     == samples_pasxh_u16[i].result);
    }
    return done_testing();
}

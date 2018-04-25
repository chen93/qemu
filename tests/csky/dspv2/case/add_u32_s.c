#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn add.u32.s\n");

    for (i = 0;
         i < sizeof(samples_add_u32_s)/sizeof(struct binary_calculation);
         i++) {
        TEST(test_add_u32_s(samples_add_u32_s[i].op1, samples_add_u32_s[i].op2)
                     == samples_add_u32_s[i].result);
    }
    return done_testing();
}

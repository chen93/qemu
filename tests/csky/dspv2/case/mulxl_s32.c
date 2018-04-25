#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn mulxl.s32\n");

    for (i = 0;
         i < sizeof(samples_mulxl_s32)/sizeof(struct binary_calculation);
         i++) {
        TEST(test_mulxl_s32(samples_mulxl_s32[i].op1, samples_mulxl_s32[i].op2)
                     == samples_mulxl_s32[i].result);
    }
    return done_testing();
}

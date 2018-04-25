#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn rmulxh.s32.r\n");

    for (i = 0;
         i < sizeof(samples_rmulxh_s32_r)/sizeof(struct binary_calculation);
         i++) {
        TEST(test_rmulxh_s32_r(samples_rmulxh_s32_r[i].op1, samples_rmulxh_s32_r[i].op2)
                     == samples_rmulxh_s32_r[i].result);
    }
    return done_testing();
}

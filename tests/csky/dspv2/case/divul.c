#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn divul\n");

    for (i = 0;
         i < sizeof(samples_divul)/sizeof(struct binary64_64_calculation);
         i++) {
        TEST(test_divul(samples_divul[i].op1, samples_divul[i].op2)
                     == samples_divul[i].result);
    }
    return done_testing();
}

#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn divsl\n");

    for (i = 0;
         i < sizeof(samples_divsl)/sizeof(struct binary64_64_calculation);
         i++) {
        TEST(test_divsl(samples_divsl[i].op1, samples_divsl[i].op2)
                     == samples_divsl[i].result);
    }
    return done_testing();
}

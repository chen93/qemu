#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn dup.8\n");

    for (i = 0;
         i < sizeof(samples_dup_8)/sizeof(struct binary_calculation);
         i++) {
        if (samples_dup_8[i].op2 == 0) {
            TEST(test_dup_8_0(samples_dup_8[i].op1) == samples_dup_8[i].result);
        } else if (samples_dup_8[i].op2 == 1) {
            TEST(test_dup_8_1(samples_dup_8[i].op1) == samples_dup_8[i].result);
        } else if (samples_dup_8[i].op2 == 2) {
            TEST(test_dup_8_2(samples_dup_8[i].op1) == samples_dup_8[i].result);
        } else if (samples_dup_8[i].op2 == 3) {
            TEST(test_dup_8_3(samples_dup_8[i].op1) == samples_dup_8[i].result);
        }
    }
    return done_testing();
}

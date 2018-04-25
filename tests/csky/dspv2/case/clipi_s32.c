#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn clipi.s32\n");

    for (i = 0;
         i < sizeof(samples_clipi_s32)/sizeof(struct binary_calculation);
         i++) {
        if (samples_clipi_s32[i].op2 == 0) {
            TEST(test_clipi_s32_0(samples_clipi_s32[i].op1)
                 == samples_clipi_s32[i].result);
        } else if (samples_clipi_s32[i].op2 == 1) {
            TEST(test_clipi_s32_1(samples_clipi_s32[i].op1)
                 == samples_clipi_s32[i].result);
        } else if (samples_clipi_s32[i].op2 == 2) {
            TEST(test_clipi_s32_2(samples_clipi_s32[i].op1)
                 == samples_clipi_s32[i].result);
        } else if (samples_clipi_s32[i].op2 == 31) {
            TEST(test_clipi_s32_31(samples_clipi_s32[i].op1)
                 == samples_clipi_s32[i].result);
        }
    }
    return done_testing();
}

#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    int res = 0;
    init_testsuite("Testing insn pkg\n");

    for (i = 0;
         i < sizeof(samples_pkg)/sizeof(struct quanary_calculation);
         i++) {
        if ((samples_pkg[i].op2 == 4) && (samples_pkg[i].op4 == 16)) {
            res = test_pkg_4_16(samples_pkg[i].op1, samples_pkg[i].op3);
            TEST(res == samples_pkg[i].result);
        } else if ((samples_pkg[i].op2 == 2) && (samples_pkg[i].op4 == 3)) {
            res = test_pkg_2_3(samples_pkg[i].op1, samples_pkg[i].op3);
            TEST(res == samples_pkg[i].result);
        } else if ((samples_pkg[i].op2 == 4) && (samples_pkg[i].op4 == 4)) {
            res = test_pkg_4_4(samples_pkg[i].op1, samples_pkg[i].op3);
            TEST(res == samples_pkg[i].result);
        } else if ((samples_pkg[i].op2 == 8) && (samples_pkg[i].op4 == 8)) {
            res =test_pkg_8_8(samples_pkg[i].op1, samples_pkg[i].op3);
            TEST(res == samples_pkg[i].result);
        } else if ((samples_pkg[i].op2 == 0) && (samples_pkg[i].op4 == 15)) {
            res = test_pkg_0_15(samples_pkg[i].op1, samples_pkg[i].op3);
            TEST(res == samples_pkg[i].result);
        } else if ((samples_pkg[i].op2 == 15) && (samples_pkg[i].op4 == 15)) {
            res = test_pkg_15_15(samples_pkg[i].op1, samples_pkg[i].op3);
            TEST(res == samples_pkg[i].result);
        }
    }
    return done_testing();
}

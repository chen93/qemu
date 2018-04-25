#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn plsri.u16.r\n");

    for (i = 0;
         i < sizeof(samples_plsri_u16_r)/sizeof(struct binary_calculation);
         i++) {
        if(samples_plsri_u16_r[i].op2 == 0x1)
            TEST(test_plsri_u16_r_1(samples_plsri_u16_r[i].op1, samples_plsri_u16_r[i].op2)
                     == samples_plsri_u16_r[i].result);
        else if(samples_plsri_u16_r[i].op2 == 0x2)
            TEST(test_plsri_u16_r_2(samples_plsri_u16_r[i].op1, samples_plsri_u16_r[i].op2)
                     == samples_plsri_u16_r[i].result);
        else if(samples_plsri_u16_r[i].op2 == 0x3)
            TEST(test_plsri_u16_r_3(samples_plsri_u16_r[i].op1, samples_plsri_u16_r[i].op2)
                     == samples_plsri_u16_r[i].result);
        else if(samples_plsri_u16_r[i].op2 == 0xf)
            TEST(test_plsri_u16_r_f(samples_plsri_u16_r[i].op1, samples_plsri_u16_r[i].op2)
                     == samples_plsri_u16_r[i].result);
        else if(samples_plsri_u16_r[i].op2 == 0x10)
            TEST(test_plsri_u16_r_10(samples_plsri_u16_r[i].op1, samples_plsri_u16_r[i].op2)
                     == samples_plsri_u16_r[i].result);
    }
    return done_testing();
}

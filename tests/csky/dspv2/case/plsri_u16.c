#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn plsri.u16\n");
    for (i = 0;
         i < sizeof(samples_plsri_u16)/sizeof(struct binary_calculation);
         i++) {
        if(samples_plsri_u16[i].op2 == 0x1)
            TEST(test_plsri_u16_1(samples_plsri_u16[i].op1, samples_plsri_u16[i].op2)
                     == samples_plsri_u16[i].result);
        else if(samples_plsri_u16[i].op2 == 0x2)
            TEST(test_plsri_u16_2(samples_plsri_u16[i].op1, samples_plsri_u16[i].op2)
                     == samples_plsri_u16[i].result);
        else if(samples_plsri_u16[i].op2 == 0x3)
            TEST(test_plsri_u16_3(samples_plsri_u16[i].op1, samples_plsri_u16[i].op2)
                     == samples_plsri_u16[i].result);
        else if(samples_plsri_u16[i].op2 == 0xf)
            TEST(test_plsri_u16_f(samples_plsri_u16[i].op1, samples_plsri_u16[i].op2)
                     == samples_plsri_u16[i].result);
        else if(samples_plsri_u16[i].op2 == 0x10)
            TEST(test_plsri_u16_10(samples_plsri_u16[i].op1, samples_plsri_u16[i].op2)
                     == samples_plsri_u16[i].result);
    }
    return done_testing();
}

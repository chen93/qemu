#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn pext.u8.e\n");

    for (i = 0;
         i < sizeof(samples_pext_u8_e)/sizeof(struct unary64_calculation);
         i++) {
        TEST(test_pext_u8_e(samples_pext_u8_e[i].op1)
                     == samples_pext_u8_e[i].result);
    }
    return done_testing();
}

#include "testsuite.h"
#include "test_device.h"
#include "dspv2_insn.h"
#include "sample_array.h"
int main(void)
{
    int i = 0;
    init_testsuite("Testing insn pkgll\n");

    for (i = 0;
         i < sizeof(samples_pkgll)/sizeof(struct binary_calculation);
         i++) {
        TEST(test_pkgll(samples_pkgll[i].op1, samples_pkgll[i].op2)
                     == samples_pkgll[i].result);
    }
    return done_testing();
}

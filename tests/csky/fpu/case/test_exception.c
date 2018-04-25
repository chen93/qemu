#include "testsuite.h"
#include "test_device.h"
#include "fpu_insn.h"

void init_fesr()
{
    __asm("movi  r0, 0");
    __asm("mtcr r0, cr<2, 2>");
}

void enable_float_exception()
{
    __asm("mfcr  r0, cr<1, 2>");
    __asm("ori   r0, r0, 0x3f");
    __asm("mtcr  r0, cr<1, 2>");
}


int main(void)
{
    int i = 0;
    init_testsuite("Testing fpu insn exception.\n");
    printf("[A]. Float Exception Disable Mode:\n");
    init_fesr();
    printf("  1. test Input Denormalized Exception.\n");
    TEST(test_ide() == 0xa0a0);

    init_fesr();
    printf("  2. test Invalid Operation Exception.\n");
    TEST(test_ioe() == 0x8181);

    init_fesr();
    printf("  3. test Divide by Zero Exception.\n");
    TEST(test_dze() == 0x8282);

    init_fesr();
    printf("  4. test Overflow Exception.\n");
    TEST(test_ofe() == 0x9494);

    init_fesr();
    printf("  5. test Underflow Exception.\n");
    TEST(test_ufe() == 0x9898);

    init_fesr();
    printf("  6. test InExact Exception.\n");
    TEST(test_ixe() == 0x9090);

    /*-----------------------------------------------*/

    printf("[B]. Float Exception Ensable Mode:\n");
    enable_float_exception();
    printf("  1. test Input Denormalized Exception.\n");
    TEST(test_ide() == 0xa0);

    init_fesr();
    printf("  2. test Invalid Operation Exception.\n");
    TEST(test_ioe() == 0x81);

    init_fesr();
    printf("  3. test Divide by Zero Exception.\n");
    TEST(test_dze() == 0x82);

    init_fesr();
    printf("  4. test Overflow Exception.\n");
    TEST(test_ofe() == 0x94);

    init_fesr();
    printf("  5. test Underflow Exception.\n");
    TEST(test_ufe() == 0x98);

    init_fesr();
    printf("  6. test InExact Exception.\n");
    TEST(test_ixe() == 0x90);

    return done_testing();
}

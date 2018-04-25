/* ---------------------------------------------------------------------------
 * Copyright (C) 2016 CSKY Limited. All rights reserved.
 *
 * Redistribution and use of this software in source and binary forms,
 * with or without modification, are permitted provided that the following
 * conditions are met:
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *   * Neither the name of CSKY Ltd. nor the names of CSKY's contributors may
 *     be used to endorse or promote products derived from this software without
 *     specific prior written permission of CSKY Ltd.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
 * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 * -------------------------------------------------------------------------- */
#include "testsuite.h"
#include "test_device.h"

#define USER1_INT_PRIO   3
#define USER2_INT_PRIO   2
#define USER3_INT_PRIO   1
#define USER4_INT_PRIO   0
#define NVIC_THRESHOLD   0
#define USER1_IRQ        3
#define USER2_IRQ        4
#define USER3_IRQ        5
#define USER4_IRQ        6

void user1_int_irq_handler(void)
{
	int NVIC_Pend=0;
	int NVIC_Active = 0;
	printf("--------start user1 irq handler!\n");

	NVIC_Active=NVIC_GetActive(USER1_IRQ);
        TEST(NVIC_Active);
        if(NVIC_Active)
		printf("User1  NVIC_Active successed!\n");
        __disable_irq();
	NVIC_SetPendingIRQ(USER2_IRQ );
	NVIC_Pend= NVIC_GetPendingIRQ(USER2_IRQ);
        __enable_irq();
        TEST(NVIC_Pend);
        if(NVIC_Pend)
            printf("User2 NVIC_SetPending successed!\n");

        printf("--------User1 irq handle successed!\n");
}

void user2_int_irq_handler(void)
{
	int NVIC_Pend=0;
	int NVIC_Active = 0;
	printf("--------start user2 irq handler!\n");

	NVIC_Active=NVIC_GetActive(USER2_IRQ);
        TEST(NVIC_Active);
        if(NVIC_Active)
		printf("User2  NVIC_Active successed!\n");
        __disable_irq();
	NVIC_SetPendingIRQ(USER3_IRQ );
	NVIC_Pend= NVIC_GetPendingIRQ(USER3_IRQ);
        __enable_irq();
        TEST(NVIC_Pend);
        if(NVIC_Pend)
            printf("User3 NVIC_SetPending successed!\n");
        printf("--------User2 irq handle successed!\n");
}

void user3_int_irq_handler(void)
{
	int NVIC_Pend=0;
	int NVIC_Active = 0;
	printf("--------start user3 irq handler!\n");

	NVIC_Active=NVIC_GetActive(USER3_IRQ);
        TEST(NVIC_Active);
        if(NVIC_Active)
		printf("User3  NVIC_Active successed!\n");
        __disable_irq();
        NVIC_SetThreshold(USER1_IRQ,NVIC_THRESHOLD);
	NVIC_SetPendingIRQ(USER4_IRQ );
	NVIC_Pend= NVIC_GetPendingIRQ(USER4_IRQ);
        __enable_irq();
        TEST(NVIC_Pend);
        if(NVIC_Pend)
            printf("User4 NVIC_SetPending successed!\n");
        printf("--------User3 irq handle successed!\n");
}

void user4_int_irq_handler(void)
{
	int NVIC_Active = 0;
	printf("--------start user4 irq handler!\n");

	NVIC_Active=NVIC_GetActive(USER4_IRQ);
        TEST(NVIC_Active);
        if(NVIC_Active)
		printf("User4  NVIC_Active successed!\n");
        printf("--------User4 irq handle successed!\n");
}

void user1_int(IRQn_Type IRQn, uint32_t priority)
{
	int NVIC_Priority = 0;
        int NVIC_Active = 0;
        init_testsuite("Testing User1 int  function!\n");
	NVIC_SetPriority(IRQn, priority);
	NVIC_EnableIRQ(IRQn);
        NVIC_Priority=NVIC_GetPriority(IRQn);
        TEST(NVIC_Priority==USER1_INT_PRIO);
        if(NVIC_Priority==USER1_INT_PRIO)
            printf("User1 NVIC_SetPriority IRQ successed!\n");
        printf("----------------------------------------\n");
}

void user2_int(IRQn_Type IRQn, uint32_t priority)
{
	int NVIC_Priority = 0;
	int NVIC_Active = 0;
        init_testsuite("Testing User2 int  function!\n");
	NVIC_SetPriority(IRQn, priority);
        NVIC_EnableIRQ(IRQn);
        NVIC_Priority=NVIC_GetPriority(IRQn);
        TEST(NVIC_Priority==USER2_INT_PRIO);
        if(NVIC_Priority==USER2_INT_PRIO)
            printf("User2 NVIC_SetPriority IRQ successed!\n");
        printf("----------------------------------------\n");
}

void user3_int(IRQn_Type IRQn, uint32_t priority)
{
	int NVIC_Priority = 0;
	int NVIC_Active = 0;
        init_testsuite("Testing User3 int  function!\n");
	NVIC_SetPriority(IRQn, priority);
        NVIC_EnableIRQ(IRQn);
        NVIC_Priority=NVIC_GetPriority(IRQn);
        TEST(NVIC_Priority==USER3_INT_PRIO);
        if(NVIC_Priority==USER3_INT_PRIO)
            printf("User3 NVIC_SetPriority IRQ successed!\n");
        printf("----------------------------------------\n");
}

void user4_int(IRQn_Type IRQn, uint32_t priority)
{
	int NVIC_Priority = 0;
	int NVIC_Active = 0;
        init_testsuite("Testing User4 int  function!\n");
	NVIC_SetPriority(IRQn, priority);
        NVIC_EnableIRQ(IRQn);
        NVIC_Priority=NVIC_GetPriority(IRQn);
        TEST(NVIC_Priority==USER4_INT_PRIO);
        if(NVIC_Priority==USER4_INT_PRIO)
            printf("User4 NVIC_SetPriority IRQ successed!\n");
        printf("----------------------------------------\n");
}

int main(void)
{
	int i = 0;
        int NVIC_Priority;
	int NVIC_Pend=0;

	init_testsuite("-**********Testing functions NVIC threshold function***********\n");

	NVIC_SetPendingIRQ(USER1_IRQ);
	NVIC_Pend= NVIC_GetPendingIRQ(USER1_IRQ);
        TEST(NVIC_Pend);
	if(NVIC_Pend)
            printf("User1 NVIC_SetPending successed!\n");
        __enable_irq();

        user4_int(USER4_IRQ,USER4_INT_PRIO);
        user3_int(USER3_IRQ,USER3_INT_PRIO);
	user2_int(USER2_IRQ,USER2_INT_PRIO);
	user1_int(USER1_IRQ,USER1_INT_PRIO);

	return done_testing();
}

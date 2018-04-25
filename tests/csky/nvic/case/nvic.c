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

int main(void)
{
	int i = 0;
	uint8_t *p;

	init_testsuite("Testing NVIC api\n");

	TEST(&(NVIC->ISER) == (uint32_t *)0xE000E100);
	TEST(&(NVIC->IWER) == (uint32_t *)0xE000E140);
	TEST(&(NVIC->ICER) == (uint32_t *)0xE000E180);
	TEST(&(NVIC->ICPR) == (uint32_t *)0xE000E280);
	TEST(&(NVIC->IABR) == (uint32_t *)0xE000E300);
	TEST(&(NVIC->IPR) == (uint32_t *)0xE000E400);
	TEST(&(NVIC->ISR) == (uint32_t *)0xE000EC00);
	TEST(&(NVIC->IPTR) == (uint32_t *)0xE000EC04);

	unsigned char free_mem[0x1000];

#undef NVIC
#define NVIC	((NVIC_Type *) free_mem)

	p = (uint8_t *)free_mem;

	NVIC->IWER[0] = 0x12345678;
	TEST(*(uint32_t *)(p + 0x40) == 0x12345678);

	NVIC->IABR[0] = 0x22345678;
	TEST(*(uint32_t *)(p + 0x200) == 0x22345678);

	NVIC->IPTR = 0x32345678;
	TEST(*(uint32_t *)(p + 0xB04) == 0x32345678);

	return done_testing();
}

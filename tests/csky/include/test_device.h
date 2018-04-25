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
#ifndef TEST_DEVICE_H
#define TEST_DEVICE_H

#include "smartl_ck803s.h"
#define CSKY_MATH_CK803S


struct unary_calculation {
    uint32_t op1;
    uint32_t result;
};

struct unary64_calculation {
    uint32_t op1;
    uint64_t result;
};

struct binary_calculation {
    uint32_t op1;
    uint32_t op2;
    uint32_t result;
};

struct binary64_calculation {
    uint32_t op1;
    uint32_t op2;
    uint64_t result;
};

struct binary64_64_calculation {
   uint64_t op1;
   uint32_t op2;
   uint64_t result;
};

struct ternary_calculation {
    uint32_t op1;
    uint32_t op2;
    uint32_t op3;
    uint32_t result;
};

struct ternary64_calculation {
    uint32_t op1;
    uint32_t op2;
    uint64_t op3;
    uint64_t result;
};

struct quanary_calculation {
   uint32_t op1;
   uint32_t op2;
   uint32_t op3;
   uint32_t op4;
   uint32_t result;
};

struct binary64_64_64_calculation {
    uint64_t op1;
    uint64_t op2;
    uint64_t result;
};
#endif  /* TEST_DEVICE_H */

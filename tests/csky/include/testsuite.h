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

/* vi: set sw=4 ts=4: */
/*
 * Some simple macros for use in test applications.
 * Copyright (C) 2000-2006 by Erik Andersen <andersen@uclibc.org>
 *
 * Licensed under the LGPL v2.1, see the file COPYING.LIB in this tarball.
 */

#ifndef TESTSUITE_H
#define TESTSUITE_H

#ifdef __NO_TESTCODE__
extern int test_number;
#endif
#include <stdio.h>
extern void init_testsuite(const char* testname);
extern int  done_testing(void) ;//__attribute__((noreturn));
extern void success_msg(int result, const char* command);
extern void error_msg(int result, int line, const char* file, const char* command);

#ifndef __NO_TESTCODE__

int test_number = 0;
static int failures = 0;

void error_msg(int result, int line, const char* file, const char* command)
{
	failures++;

	printf("\nFAILED TEST %lu: \n\t%s\n", (unsigned long)test_number, command);
	printf("AT LINE: %d, FILE: %s\n\n", line, file);
}

void success_msg(int result, const char* command)
{
#if 0
	printf("passed test: %s == 0\n", command);
#endif
}

int  done_testing(void)
{
    if (0 < failures) {
		printf("Failed %d tests\n", failures);
		//exit(EXIT_FAILURE);
	} else {
		printf("All functions tested sucessfully\n");
		///exit(EXIT_SUCCESS);
	}
	return failures;
}

void init_testsuite(const char* testname)
{
	printf("%s", testname);
	test_number = 0;
	failures = 0;
#if !defined(__UCLIBC__) || defined(__UCLIBC_DYNAMIC_ATEXIT__)
//	atexit(done_testing);
#endif
}

#endif /* __NO_TESTCODE__ */


#define TEST_STRING_OUTPUT(command, expected_result) \
	do { \
		int result = strcmp(command, expected_result); \
		test_number++; \
		if (result == 0.000000) { \
			success_msg(result, "command"); \
		} else { \
			error_msg(result, __LINE__, __FILE__, command); \
		}; \
	} while (0)

#define TEST_NUMERIC(command, expected_result) \
	do { \
		int result = (command); \
		test_number++; \
		if (result == expected_result) { \
			success_msg(result, # command); \
		} else { \
			error_msg(result, __LINE__, __FILE__, # command); \
		}; \
	} while (0)


#define TEST(command) \
	do { \
		int __result = (command); \
		test_number++; \
		if (__result == 1) { \
			success_msg(__result, # command); \
		} else { \
			error_msg(__result, __LINE__, __FILE__,  # command); \
		}; \
	} while (0)

#define TEST_NULL(command) \
    do { \
        int result = (command); \
        test_number++; \
        if (result == NULL) { \
            success_msg(result, # command); \
        } else { \
            error_msg(result, __LINE__, __FILE__,  # command); \
        }; \
    } while (0)

#define TEST_NUMERIC_LONG(command, expected_result) \
    do { \
        long result = (command); \
        test_number++; \
        if (result == expected_result) { \
            success_msg(result, # command); \
        } else { \
            error_msg(result, __LINE__, __FILE__, # command); \
        }; \
    } while (0)

#define TEST_NUMERIC_LONGLONG(command, expected_result) \
    do { \
       long long result = (command); \
        test_number++; \
        if (result == expected_result) { \
            success_msg(result, # command); \
        } else { \
            error_msg(result, __LINE__, __FILE__, # command); \
        }; \
    } while (0)

#define TEST_NUMERIC_FLOAT(command, expected_result) \
    do { \
       float result = (command); \
        test_number++; \
        if (result == expected_result) { \
            success_msg(result, # command); \
        } else { \
            error_msg(result, __LINE__, __FILE__, # command); \
        }; \
    } while (0)

#define TEST_NUMERIC_DOUBLE(command, expected_result) \
    do { \
        double result = (command); \
        test_number++; \
        if (result == expected_result) { \
            success_msg(result, # command); \
        } else { \
            error_msg(result, __LINE__, __FILE__, # command); \
        }; \
    } while (0)

#define STR_CMD(cmd) cmd

#endif	/* TESTSUITE_H */

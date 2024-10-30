/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef __STDDEF_H__
#define __STDDEF_H__	1

#include <internal/types.h>
typedef int time_t;

#endif
struct timespec {
    time_t	tv_sec;
    long    tv_nsec;
};
int nanosleep(const struct timespec *req, struct timespec *rem);

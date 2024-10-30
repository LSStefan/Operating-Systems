// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <stdarg.h>
#include <errno.h>
#include <internal/syscall.h>


#define SYS_close 3

int close(int fd)
{
    int result = syscall(SYS_close, fd);
    if (result == -1)
    {
        errno = -result;
        return -1;
    }
    return 0;
}

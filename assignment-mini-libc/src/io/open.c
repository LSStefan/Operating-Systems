// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <stdarg.h>
#include <errno.h>
#include <unistd.h>
#include <internal/syscall.h>

#define SYS_Open 2

int open(const char *filename, int flags, ...)
{
    /* TODO: Implement open system call. */
    // pt argumente variabile
    // va_list args;
    // mode_t mode = 0;

    // if (flags & O_CREAT)
    // {
    //     va_start(args, flags);
    //     mode = va_arg(args, mode_t);
    //     va_end(args);
    // }

    // file descriptor
    int fd = syscall(SYS_Open, filename, flags);

    // verifica erori
    if (fd < 0)
    {
        errno = -fd;
        return -1;
    }

    return fd;
}

// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <internal/syscall.h>

#define SYS_stat 4
#define SYS_Open 2

int stat(const char *restrict path, struct stat *restrict buf)
{
    /* TODO: Implement stat(). */

    // verifica daca fisierul exista
    int fd = open(path, O_RDONLY);
    if (fd == -1)
    {
        errno = ENOENT;
        return -1;
    }

    if (path == NULL || buf == NULL)
    {
        errno = EINVAL;
        return -1;
    }

    int result = syscall(SYS_stat, path, buf);

    if (result < 0)
    {
        errno = -result;
        return -1;
    }

    return 0; // Success

    return 0;
}

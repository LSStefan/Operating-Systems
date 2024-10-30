// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <internal/syscall.h>


#define SYS_fstat 5

int fstat(int fd, struct stat *st)
{
	/* TODO: Implement fstat(). */
	// verifica daca fd este valid
	if (fd < 0)
	{
		errno = EBADF;
		return -1;
	}

	int result = syscall(SYS_fstat, fd, st);

	if (result < 0)
	{
		errno = -result;
		return -1;
	}

	return 0;
}

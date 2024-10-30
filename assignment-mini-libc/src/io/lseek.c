// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <errno.h>
#include <internal/syscall.h>
#define SYS_lseek 8
#define Seek_SET 0
#define Seek_CUR 1
#define Seek_END 2

typedef long off_t;

off_t lseek(int fd, off_t offset, int whence)
{
	/* TODO: Implement lseek(). */
	// invalid file descriptor
	if (fd < 0)
	{
		errno = EBADF;
		return -1;
	}

	// invalid whence
	if (whence != SEEK_SET && whence != SEEK_CUR && whence != SEEK_END)
	{
		errno = EINVAL;
		return -1;
	}

	int result = syscall(SYS_lseek, fd, offset, whence);

	if (result < 0)
	{
		errno = -result;
		return -1;
	}
	return result;
}

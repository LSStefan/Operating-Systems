// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <internal/syscall.h>


#define SYS_ftruncate 77

int ftruncate(int fd, off_t length)
{
	/* Perform the system call to truncate the file. */

	// // verifica lungimea
	// if (length < 0)
	// {
	// 	errno = EINVAL;
	// 	return -1;
	// }

	// // bad file descriptor
	// if (fd < 0)
	// {
	// 	errno = EBADF;
	// 	return -1;
	// }

	// // verifica daca fisierul este director
	// if (open(fd, O_DIRECTORY) == -1)
	// {
	// 	errno = EISDIR;
	// 	return -1;
	// }

	// syscall
	int result = syscall(SYS_ftruncate, fd, length);

	if (result < 0)
	{
		errno = -result;
		return -1;
	}

	return 0;
}

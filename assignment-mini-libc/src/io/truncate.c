// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <internal/syscall.h>


#define SYS_truncate 76

int truncate(const char *path, off_t length)
{
	/* TODO: Implement truncate(). */

	// verifica lungimea
	//  if(length < 0)
	//  {
	//  	errno = EINVAL;
	//  	return -1;
	//  }

	// //verifica daca fisierul exista
	// int fd = open(path, O_RDONLY);
	// if (fd == -1) {
	//     errno = ENOENT;
	// 	return -1;
	// }

	// //verifica daca fisierul este director
	// if(open(path , O_DIRECTORY) == -1){
	// 	errno = EISDIR;
	// 	return -1;
	// }

	// apel syscall
	int result = syscall(SYS_truncate, path, length);

	if (result < 0)
	{
		errno = -result;
		return -1;
	}

	return 0;
}

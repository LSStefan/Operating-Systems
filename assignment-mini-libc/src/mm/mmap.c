// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

#define SYS_mmap 9
#define SYS_mremap 25
#define SYS_munmap 11

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */

	// file descriptor invalid
	//  if(fd != -1 && flags == MAP_ANONYMOUS)
	//  {
	//  	errno = EBADF;
	//  	return MAP_FAILED;
	//  }
	//  if(fd < -1){
	//  	errno = EBADF;
	//  	return MAP_FAILED;
	//  }

	// //bad flags
	// if(flags != MAP_SHARED && flags != MAP_PRIVATE && flags != MAP_ANON)
	// {
	// 	errno = EINVAL;
	// 	return MAP_FAILED;
	// }

	void *result = (void *)syscall(SYS_mmap, addr, length, prot, flags, fd, offset);
	if ((long)result > 0)
	{
		return result;
	}
	errno = -(long)result;
	return MAP_FAILED;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */

	void *result = (void *)syscall(SYS_mremap, old_address, old_size, new_size, flags);
	if ((long)result > 0)
	{
		return result;
	}
	errno = -(long)result;
	return MAP_FAILED;
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */
	int result = syscall(SYS_munmap, addr, length);
	if(result == 0)
	{
		return 0;
	}
	errno = -result;
	return -1;
}

// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	void *pointer;
	pointer = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (pointer != MAP_FAILED)
	{
		return pointer;
	}
	return NULL;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	void *pointer;
	pointer = mmap(NULL, nmemb * size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (pointer != MAP_FAILED)
	{
		memset(pointer, 0, nmemb * size);
		return pointer;
	}

	return NULL;
}
void free(void *ptr)
{
	/* TODO: Implement free(). */
	void *actualPTR = ptr - sizeof(uint32_t);
	uint32_t size = *(uint32_t*)actualPTR;
	munmap(actualPTR, size);
}
void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */

	if(ptr == NULL)
	{
		return malloc(size);
	}

	void *pointer = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	if (pointer != MAP_FAILED)
	{
		memcpy(pointer, ptr, size);
		return pointer;
	}

	return NULL;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	void *pointer = mmap(NULL, nmemb * size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if(pointer != MAP_FAILED)
	{
		memcpy(pointer, ptr, nmemb * size);
		return pointer;
	}
	return NULL;
}

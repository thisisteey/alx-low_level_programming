#include "main.h"
#include <stdlib.h>

/**
 * _realloc - function that relocates a memory block
 * @ptr: pointer to the memor previously allocated
 * @old_size: size, in bytes of the allocated space of the ptr
 * @new_size: new size in bytes of the new memory block
 * Return: ptr
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		ptr = malloc(new_size);
	if (new_size == old_size)
		return (ptr);
	free(ptr);
	ptr = malloc(new_size);

	return (ptr);
}

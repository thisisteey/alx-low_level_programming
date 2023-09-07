#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * malloc_checked - functio that allocates memory
 * @b: the size to allocate
 * Return: nothing
 */
void *malloc_checked(unsigned int b)
{
	void *x;

	x = malloc(b);
	if (x == NULL)
		exit(98);
	return (x);
}

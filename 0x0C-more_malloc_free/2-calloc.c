#include "main.h"
#include <stdlib.h>

/**
 * _calloc - function that allocates memory of an array
 * @nmemb: number of elements
 * @size: size of bytes
 * Return: pointer to teh allocated memory,
 * if nmemb or size is 0, return NULL,
 * if malloc fails, return NULL
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *x;
	unsigned int a;

	if (nmemb == 0 || size == 0)
		return (NULL);
	x = malloc(nmemb * size);
	if (x == NULL)
		return (NULL);

	for (a = 0 ; a < (nmemb * size) ; a++)
		x[a] = 0;

	return (x);

}

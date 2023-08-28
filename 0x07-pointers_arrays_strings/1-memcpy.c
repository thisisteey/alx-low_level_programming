#include "main.h"

/**
 * *_memcpy - function that copies memory area
 * @dest: destination location of memory to be copied
 * @src: source location of memory to be copied
 * @n: number of byte(s)
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int a;

	for (a = 0 ; a < n ; a++)
		dest[a] = src[a];
	return (dest);
}

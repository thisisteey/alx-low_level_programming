#include "main.h"
#include <string.h>

/**
 * *_strncat - function to concatenate two strings
 * @dest: destination string
 * @src: source string
 * @n: amount of bytes used from src
 * Return: dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int len = strlen(dest);
	int a;

	for (a = 0 ; a < n && *src != '\0' ; a++)
	{
		dest[len + a] = *src;
		src++;
	}
	dest[len + a] = '\0';
	return (dest);
}

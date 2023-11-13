#include "main.h"

/**
 * _strspn - function that gets the lenght of a prefix substring
 * @s: string to search from
 * @accept: string to search
 * Return: number of characters matched
 */
unsigned int _strspn(char *s, char *accept)
{
	int x, y;

	for (x = 0 ; s[x] != '\0' ; x++)
	{
		for (y = 0 ; s[x] != accept[y] ; y++)
		{
			if (accept[y] == '\0')
				return (x);
		}
	}
	return (0);
}

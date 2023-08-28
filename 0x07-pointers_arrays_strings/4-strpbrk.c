#include "main.h"

/**
 * *_strpbrk - function that searches a string
 * for any of a set of byte
 * @s: string to be searched
 * @accept: string where bytes will be searched
 * Return: 0 on code success
 */
char *_strpbrk(char *s, char *accept)
{
	int a;

	while (*s)
	{
		for (a = 0 ; accept[a] ; a++)
		{
			if (*s == accept[a])
				return (s);
		}
		s++;
	}
	return ('\0');
}

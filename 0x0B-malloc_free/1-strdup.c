#include "main.h"
#include <stdlib.h>

/**
 * _strdup - function that duplicates a string
 * @str: string to duplicate
 * Return: the duplicated string
 */
char *_strdup(char *str)
{
	int x = 0, y = 1;
	char *a;

	if (str == NULL)
		return (NULL);
	while (str[y])
	{
		y++;
	}
	a = malloc((sizeof(char) * y) + 1);
	if (a == NULL)
		return (NULL);
	while (x < y)
	{
		a[x] = str[x];
		x++;
	}
	a[x] = '\0';
	return (a);
}

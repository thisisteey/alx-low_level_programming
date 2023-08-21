#include "main.h"

/**
 * rev_string - reverses a string
 * @s: string to be reversed
 * Return: void
 */
void rev_string(char *s)
{
	int a;
	char b;
	int count = 0;

	for (a = 0 ; s[a] != '\0' ; a++)
		count++;
	for (a = 0 ; a < count / 2 ; a++)
	{
		b = s[a];
		s[a] = s[count - 1 - a];
		s[count - 1 - a] = b;
	}
}

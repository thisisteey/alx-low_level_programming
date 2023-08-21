#include "main.h"

/**
 * puts2 - prints every other character of a string
 * @str: string to be printed
 * Return: void
 */
void puts2(char *str)
{
	int a = 0;

	while (a >= 0)
	{
		if (str[a] == '\0')
		{
			_putchar('\n');
			break;
		}
		if (a % 2 == 0)
			_putchar(str[a]);
		a++;
	}
}

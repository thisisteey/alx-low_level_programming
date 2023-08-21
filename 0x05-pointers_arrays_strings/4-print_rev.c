#include "main.h"

/**
 * print_rev - prints a string in reverse
 * @s: string to be printed
 * Return: void
 */
void print_rev(char *s)
{
	int y;
	int count = 0;

	for (y = 0 ; s[y] != '\0' ; y++)
		count++;
	for (y = count - 1 ; y >= 0 ; y--)
		_putchar(s[y]);
	_putchar('\n');
}

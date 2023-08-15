#include "main.h"

/**
 * print_alphabet_x10 - function to print the alphabet in lowercase ten times
 *
 * Return: 0 on code success
 */

void print_alphabet_x10(void)
{
	int x;
	char y;

	for (x = 0 ; x < 10 ; x++)
	{
		for (y = 'a' ; y <= 'z' ; y++)
			_putchar(y);
		_putchar('\n');
	}
}

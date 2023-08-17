#include "main.h"

/**
 * more_numbers - function to print numbers 0 to 14 ten times
 * Return: void
 */
void more_numbers(void)
{
	int x;
	int y;

	for (x = 0 ; x < 10 ; x++)
	{
		for (y = 0 ; y <= 14 ; y++)
		{
			_putchar(y % 10 + '0');
		}
		_putchar('\n');
	}
	_putchar('\n');
}

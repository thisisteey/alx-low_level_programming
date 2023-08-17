#include "main.h"

/**
 * print_square - function to print a square
 * @size: parameter used as size of the square
 * Return: void
 */
void print_square(int size)
{
	if (size <= 0)
		_putchar('\n');
	else
	{
		int x, y;

		for (x = 1 ; x <= size ; x++)
		{
			for (y = 1 ; y <= size ; y++)
				_putchar('#');
			_putchar('\n');
		}
	}
}

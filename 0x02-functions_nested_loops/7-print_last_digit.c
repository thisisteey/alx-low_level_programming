#include "main.h"

/**
 * print_last_digit - function to print last digit of a number
 * @x: parameter to be checked
 * Return: y
 */

int print_last_digit(int x)
{
	int y;

	y = x % 10;
	if (x < 0)
		y = -y;
	_putchar(y + '0');
	return (y);
}

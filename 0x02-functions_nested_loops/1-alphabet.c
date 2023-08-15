#include "main.h"

/**
 * print_alphabet - fucntion to print alphabets in lowercase
 *
 * Return: 0 on code success
 */

void print_alphabet(void)
{
	char i;

	for (i = 'a' ; i <= 'z' ; i++)
		_putchar(i);
	_putchar('\n');
}

#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_numbers - prints numbers, followed by a new line
 * @separator: the string to be printed between numbers
 * @n: number of integers passed to the function
 * @...: variable number of numbers to be printed
 * Return: void
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int x;

	va_start(ap, n);
	for (x = 0 ; x < n ; x++)
	{
		printf("%d", va_arg(ap, int));
		if (x != (n - 1) && separator != NULL)
			printf("%s", separator);
	}
	printf("\n");
	va_end(ap);
}

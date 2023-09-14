#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_strings - prints strings, followed by a new line
 * @separator: the string to be printed between strings
 * @n: the number of strings passed into the function
 * @...: variable number of strings to be printed
 * Return: void
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int x;

	int *arr = malloc(sizeof(int) * n);

	va_start(ap, n);
	for (x = 0 ; x < n ; x++)
	{
		if (va_arg(ap, char *) == NULL)
			arr[x] = 1;
		else
			arr[x] = 0;
	}
	va_end(ap);
	va_start(ap, n);
	for (x = 0 ; x < n ; x++)
	{
		if (arr[x] == 1)
			printf("(nil)");
		else
			printf("%s", va_arg(ap, char *));
		if (x < (n - 1) && separator)
		{
			printf("%s", separator);
		}
	}
	va_end(ap);
	putchar('\n');
}

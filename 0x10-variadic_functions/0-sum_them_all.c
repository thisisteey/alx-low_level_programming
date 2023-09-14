#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - sum all of its parameters
 * @n: number of parameters passed to the funtion
 * @...: variable number of parameters to calculate the sum of
 * Return: an integer which is the sum
 */
int sum_them_all(const unsigned int n, ...)
{
	int sum = 0;
	unsigned int x;
	va_list ap;

	va_start(ap, n);

	for (x = 0 ; x < n ; x++)
		sum += va_arg(ap, int);
	va_end(ap);
	return (sum);
}

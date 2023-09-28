#include "main.h"

/**
 * flip_bits - returns the number of bits to change/flip to
 * get from one number to another
 * @n: first number
 * @m: second number
 * Return: number of bits to change/flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xls = n ^ m, b = 0;

	while (xls > 0)
	{
		b += (xls & 1);
		xls >>= 1;
	}
	return (b);
}

#include "main.h"
#include <stdio.h>

int _sqrt(int n, int x);

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to calculate the natural square root
 * Return: the natural square root
 */
int _sqrt_recursion(int n)
{
	return (_sqrt(n, 1));
}

/**
 * _sqrt - calculates natural square root of numbers
 * @n: number to calculate the natural square root
 * @x: number to be iterated
 * Return: the natural square root
 */
int _sqrt(int n, int x)
{
	int sqrt = x * x;

	if (sqrt > n)
		return (-1);
	if (sqrt == n)
		return (x);
	return (_sqrt(n, x + 1));
}

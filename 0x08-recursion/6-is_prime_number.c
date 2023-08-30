#include "main.h"
#include <stdio.h>

int check_prime(int n, int x);

/**
 * is_prime_number - returns if a number is prime
 * @n: the number to be checked
 * Return: integer value
 */
int is_prime_number(int n)
{
	return (check_prime(n, 1));
}

/**
 * check_prime - check if number is prime
 * @n: the number to be checked
 * @x: number of times of iteration
 * Return: 1 for prime or 0 otherwise
 */
int check_prime(int n, int x)
{
	if (n <= 1)
		return (0);
	if (n % x == 0 && x > 1)
		return (0);
	if ((n / x) < x)
		return (1);
	return (check_prime(n, x + 1));
}

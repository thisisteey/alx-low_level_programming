#include "main.h"

/**
 * swap_int - swaps the value of two integers
 * @a: first argument that will be swapped
 * @b: second argument that will be swapped
 * Return: void
 */
void swap_int(int *a, int *b)
{
	int p = *a;

	*a = *b;
	*b = p;
}

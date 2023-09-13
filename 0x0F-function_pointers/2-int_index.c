#include "function_pointers.h"
#include <stddef.h>

/**
 * int_index - function that searches for an integer
 * @array: interger array of size size
 * @size: size of the array
 * @cmp: the compare function to be used
 * Return: the index of the first element for which the cmp function
 * does not return 0
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int x;

	if (array == NULL || size <= 0 || cmp == NULL)
		return (-1);
	for (x = 0 ; x < size ; x++)
	{
		if (cmp(array[x]) != 0)
			return (x);
	}
	return (-1);
}

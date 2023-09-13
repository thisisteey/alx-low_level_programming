#include "function_pointers.h"

/**
 * array_iterator - prints each array element on a newline
 * @array: array
 * @size: number of elements to prints
 * @action: pointer to print in regular or hex
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int x = 0;

	if (array != NULL && action != NULL && size > 0)
	{
		while (x < size)
		{
			action(array[x]);
			x++;
		}
	}
}

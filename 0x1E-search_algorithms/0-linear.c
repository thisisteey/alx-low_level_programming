#include "search_algos.h"

/**
 * linear_search - locates integer in an array using Linear search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: is the integer/value to search for
 * Return: the first index where the value is locater or -1 if array is empty
 */
int linear_search(int *array, size_t size, int value)
{
	int idx;

	if (!array)
		return (-1);
	for (idx = 0 ; idx < (int)size ; idx++)
	{
		printf("Value checked array[%u] = [%d]\n", idx, array[idx]);
		if (value == array[idx])
			return (idx);
	}
	return (-1);
}

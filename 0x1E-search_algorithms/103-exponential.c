#include "search_algos.h"

int rec_binary_search(int *array, size_t start, size_t end, int value);

/**
 * rec_binary_search - finds a value in an array using binary search
 * @array: pointer to the first element of the array to search
 * @start: the starting index of the subarray
 * @end: the ending index of the subarray
 * @value: the value to search for in the array
 * Return: the first index where value is located or -1 if array is NULL
 */
int rec_binary_search(int *array, size_t start, size_t end, int value)
{
	size_t idx;

	if (!array)
		return (-1);
	while (end >= start)
	{
		printf("Searching in array: ");
		for (idx = start ; idx < end ; idx++)
			printf("%d, ", array[idx]);
		printf("%d\n", array[idx]);
		idx = start + (end - start) / 2;
		if (array[idx] == value)
			return (idx);
		if (array[idx] > value)
			end = idx - 1;
		else
			start = idx + 1;
	}
	return (-1);
}

/**
 * exponential_search - finds value in a sorted int array using exponential
 * @array: pointer to the first element of the array to search
 * @size: the number of elements in the array
 * @value: the value to search for in the array
 * Return: the first index where value is located or -1 if array is NULL
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t idx = 0, end;

	if (!array)
		return (-1);
	if (array[0] != value)
	{
		for (idx = 1 ; idx < size && array[idx] <= value ; idx = idx * 2)
			printf("Value checked array[%ld] = [%d]\n", idx, array[idx]);
	}
	end = idx < size ? idx : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", idx / 2, end);
	return (rec_binary_search(array, idx / 2, end, value));
}

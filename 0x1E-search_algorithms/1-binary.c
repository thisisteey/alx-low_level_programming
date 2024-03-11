#include "search_algos.h"

void get_array(int *array, int start, int end);

/**
 * get_array - prints elements of an array with a specific range
 * @array: pointer to the array to print
 * @start: starting index to print from
 * @end: ending index for printing
 * Return: void
 */
void get_array(int *array, int start, int end)
{
	int idx;

	printf("Searching in array: ");
	for (idx = start ; idx < end ; idx++)
	{
		printf("%d, ", array[idx]);
	}
	printf("%d\n", array[idx]);
}

/**
 * binary_search - finds value in sorted int array using binary search algo
 * @array: pointer to the first element in the array to search
 * @size: number of elements in the array
 * @value: value to search for in the array
 * Return: index where the value is located or -1 if array is NULL
 */
int binary_search(int *array, size_t size, int value)
{
	int start, end, middle;

	if (!array)
		return (-1);
	start = 0;
	end = size - 1;
	while (start <= end)
	{
		get_array(array, start, end);
		middle = (start + end) / 2;
		if (array[middle] > value)
			end = middle - 1;
		else if (array[middle] < value)
			start = middle + 1;
		else
			return (middle);
	}
	return (-1);
}

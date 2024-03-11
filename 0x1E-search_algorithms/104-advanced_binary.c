#include "search_algos.h"

int first_occurence(int *array, size_t start, size_t end, int value);

/**
 * first_occurence - finds the first occurence of a value using binary search
 * @array: pointer to the first element of the array to search
 * @start: the starting index of the subarray
 * @end: the ending index of the subarray
 * @value: the value to search for in the array
 * Return: index where the first occurence is located or -1 if array is NULL
 */
int first_occurence(int *array, size_t start, size_t end, int value)
{
	size_t idx;

	if (end < start)
		return (-1);
	printf("Searching in array: ");
	for (idx = start ; idx < end ; idx++)
		printf("%d, ", array[idx]);
	printf("%d\n", array[idx]);
	idx = start + (end - start) / 2;
	if (array[idx] == value && (idx == start || array[idx - 1] != value))
		return (idx);
	if (array[idx] >= value)
		return (first_occurence(array, start, idx, value));
	return (first_occurence(array, idx + 1, end, value));
}

/**
 * advanced_binary - finds value in an array of int using advanced binary
 * @array: pointer to the first element of the array to search
 * @size: the number of elements in the array
 * @value: the value to search for in the array
 * Return: the first index where value is located or -1 if array is NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1);
	return (first_occurence(array, 0, size - 1, value));
}

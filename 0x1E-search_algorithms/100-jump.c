#include "search_algos.h"

/**
 * jump_search - finds value in a sorted int array using jump search algo
 * @array: - pointer to the first element of the array to search
 * @size: the number of elements in the array
 * @value: the value to search for in the array of integers
 * Return: the first index where value is located or -1 if array is NULL
 */
int jump_search(int *array, size_t size, int value)
{
	int idx, jumpsz, jumpstp, previdx;

	if (!array || size == 0)
		return (-1);
	jumpsz = (int)sqrt((double)size);
	jumpstp = 0;
	previdx = idx = 0;
	do {
		printf("Value checked array[%d] = [%d]\n", idx, array[idx]);
		if (array[idx] == value)
			return (idx);
		jumpstp++;
		previdx = idx;
		idx = jumpstp * jumpsz;
	} while (idx < (int)size && array[idx] < value);
	printf("Value found between indexes [%d] and [%d]\n", previdx, idx);
	for (; previdx <= idx && previdx < (int)size ; previdx++)
	{
		printf("Value checked array[%d] = [%d]\n", previdx, array[previdx]);
		if (array[previdx] == value)
			return (previdx);
	}
	return (-1);
}

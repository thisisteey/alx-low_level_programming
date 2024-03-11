#include "search_algos.h"

/**
 * interpolation_search - finds value in a sorted array int using interpolation
 * @array: pointer to the first element of the array to search
 * @size: the number of the elements in the array
 * @value: the value to search for in the sorted array of int
 * Return: the first index where value is located or -1 if array is NULL
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t pos, low = 0, high = size - 1;
	double interpfact;

	if (!array)
		return (-1);
	while (size)
	{
		interpfact = ((double)(high - low) / (array[high] - array[low])
				* (value - array[low]));
		pos = (size_t)(low + interpfact);
		printf("Value checked array[%d]", (int)pos);
		if (pos >= size)
		{
			printf(" is out of range\n");
			break;
		}
		else
		{
			printf(" = [%d]\n", array[pos]);
		}
		if (array[pos] == value)
			return ((int)pos);
		if (array[pos] < value)
			low = pos + 1;
		else
			high = pos - 1;
		if (low == high)
			break;
	}
	return (-1);
}

#include "search_algos.h"

/**
 * linear_skip - finds value in a sorted skip list of integers
 * @list: pointer to the head of the list to search
 * @value: the value to search for in the list
 * Return: pointer to the first node where value is located or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	size_t start = 0, end = 0;
	skiplist_t *curnd, *nxtnd;

	if (!list)
		return (NULL);
	curnd = list;
	nxtnd = curnd->express ? curnd->express : curnd;
	while (nxtnd)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)nxtnd->index, nxtnd->n);
		if (nxtnd->n >= value)
			break;
		curnd = nxtnd;
		if ((curnd->n < value) && (curnd->express == NULL))
		{
			while (nxtnd->next)
				nxtnd = nxtnd->next;
			break;
		}
		nxtnd = curnd->express ? curnd->express : curnd;
	}
	start = curnd->index;
	end = nxtnd->index;
	printf("Value found between indexes [%d] and [%d]\n", (int)start, (int)end);
	while (curnd)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)curnd->index, curnd->n);
		if (curnd->n == value)
			return (curnd);
		curnd = curnd->next;
	}
	return (NULL);
}

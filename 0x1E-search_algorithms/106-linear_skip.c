#include "search_algos.h"

/**
 * linear_skip - finds value in a sorted skip list of integers
 * @list: pointer to the head of the list to search
 * @value: the value to search for in the list
 * Return: pointer to the first node where value is located or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *currnd;

	if (!list)
		return (NULL);
	currnd = list;
	do {
		list = currnd;
		currnd = currnd->express;
		printf("Value checked at index ");
		printf("[%d] = [%d]\n", (int)currnd->index, currnd->n);
	} while (currnd->express && currnd->n < value);
	if (!currnd->express)
	{
		list = currnd;
		while (currnd->next)
			currnd = currnd->next;
	}
	printf("Value found between indexes ");
	printf("[%d] and [%d]\n", (int)list->index, (int)currnd->index);
	while (list != currnd->next)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)list->index, list->n);
		if (list->n == value)
			return (list);
		list = list->next;
	}
	return (NULL);
}

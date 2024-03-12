#include "search_algos.h"

/**
 * jump_list - finds value in a sorted int list using jump search algo
 * @list: pointer to the head of the list to search
 * @size: the number of nodes in theb list
 * @value: the value to search for in the list
 * Return: pointer to the firs node where value is located or NULL
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t idx = 0, jumpsz = 0, stpcnt = (size_t)sqrt((double)size);
	listint_t *prvnd;

	if (!list || size == 0)
		return (NULL);
	do {
		prvnd = list;
		jumpsz++;
		idx = jumpsz * stpcnt;
		while (list->next && list->index < idx)
			list = list->next;
		if (!list->next && idx != list->index)
			idx = list->index;
		printf("Value checked at index [%d] = [%d]\n", (int)idx, list->n);
	} while (idx < size && list->next && list->n < value);
	printf("Value found between indexes ");
	printf("[%d] and [%d]\n", (int)prvnd->index, (int)list->index);
	for (; prvnd && prvnd->index <= list->index ; prvnd = prvnd->next)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)prvnd->index, prvnd->n);
		if (prvnd->n == value)
			return (prvnd);
	}
	return (NULL);
}

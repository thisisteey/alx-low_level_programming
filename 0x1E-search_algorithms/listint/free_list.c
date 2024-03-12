#include "../search_algos.h"

/**
 * free_list - deallocates a singly linked list
 * @list: the pointer to the linked list to be freed
 * Return: void
 */
void free_list(listint_t *list)
{
	listint_t *newnd;

	if (list)
	{
		newnd = list->next;
		free(list);
		free_list(newnd);
	}
}

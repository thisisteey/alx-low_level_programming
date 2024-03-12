#include "../search_algos.h"

/**
 * free_skiplist - deallocates a singly linked list
 * @list: the pointer to the linked list to be freed
 * Return: void
 */
void free_skiplist(skiplist_t *list)
{
	skiplist_t *newnd;

	if (list)
	{
		newnd = list->next;
		free(list);
		free_skiplist(newnd);
	}
}

#include "lists.h"

/**
 * listint_len - returns the number of elements in a linked list
 * @h: linked list to traverse
 * Return: number of nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t numnodes = 0;

	while (h)
	{
		numnodes++;
		h = h->next;
	}
	return (numnodes);
}

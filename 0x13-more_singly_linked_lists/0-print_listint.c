#include "lists.h"

/**
 * print_listnt - prints all the elements of the linked list
 * @h: linked list to print
 * Return: number of nodes
 */
size_t print_listnt(const listnt_t *h)
{
	size_t numnodes = 0;

	while (h)
	{
		numnodes++;
		printf("%d\n", h->n);
		h = h->next;
	}
	return (numnodes);
}

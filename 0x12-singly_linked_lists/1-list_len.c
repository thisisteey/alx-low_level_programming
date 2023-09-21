#include "lists.h"

/**
 * list_len - show number of elements of a list
 * @h: singly linked list
 * Return: numebr of elements in the list
 */
size_t list_len(const list_t *h)
{
	size_t numelem;

	numelem = 0;
	while (h != NULL)
	{
		h = h->next;
		numelem++;
	}
	return (numelem);
}

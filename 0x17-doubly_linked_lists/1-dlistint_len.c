#include "lists.h"

/**
 * dlistint_len - counts the number of elements in a linked dlistint_t list
 * @h: pointer to the head of the linked list
 * Return: the number of elements in the linked list
 */
size_t dlistint_len(const dlistint_t *h)
{
	int num = 0;

	while (h)
	{
		num++;
		h = h->next;
	}
	return (num);
}

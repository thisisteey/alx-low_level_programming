#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list
 * @head: pointer to the head of the linked list
 * @index: index of the nth node
 * Return: the nth node
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	while (index != 0)
	{
		if (!head)
			return (NULL);
		head = head->next;
		index--;
	}
	return (head);
}

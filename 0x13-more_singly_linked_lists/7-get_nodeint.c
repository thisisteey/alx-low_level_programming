#include "lists.h"

/**
 * get_nodeint_at_index - returns the nodes of a certain index in a linked list
 * @head: first node in the linked list
 * @index: index of the node to return
 * Return: located node
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int x;

	for (x = 0 ;  x < index ; x++)
	{
		if (head == NULL)
			return (NULL);

		head = head->next;
	}
	return (head);
}

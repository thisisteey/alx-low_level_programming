#include "lists.h"

/**
 * free_dlistint - frees a dlistint_t list
 * @head: pointer to the head of the linked list
 * Return: void
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *nxtnode;

	while (head)
	{
		nxtnode = head->next;
		free(head);
		head = nxtnode;
	}
}

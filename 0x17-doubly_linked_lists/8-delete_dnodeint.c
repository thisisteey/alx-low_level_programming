#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes node at index of a dlistint_t linked list
 * @head: double pointer to the head of the linked list
 * @index: index of the new node
 * Return: 1 on code success and -1 if otherwise
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int x;
	dlistint_t *fsthead, *scdhead;

	fsthead = *head;
	if (fsthead)
		while (fsthead->prev)
			fsthead = fsthead->prev;
	x = 0;
	while (fsthead)
	{
		if (x == index)
		{
			if (x == 0)
			{
				*head = fsthead->next;
				if (*head)
					(*head)->prev = NULL;
			}
			else
			{
				scdhead->next = fsthead->next;
				if (fsthead->next)
					fsthead->next->prev = scdhead;
			}
			free(fsthead);
			return (1);
		}
		scdhead = fsthead;
		fsthead = fsthead->next;
		x++;
	}
	return (-1);
}

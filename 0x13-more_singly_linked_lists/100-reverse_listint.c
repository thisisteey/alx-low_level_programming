#include "lists.h"

/**
 * reverse_listint - reverses a linked list
 * @head: pointer to the first node in the list
 * Return: pointer to the first node in the new list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prior, *rear;

	if (head == NULL || *head == NULL)
		return (NULL);
	rear = NULL;

	while ((*head)->next != NULL)
	{
		prior = (*head)->next;
		(*head)->next = rear;
		rear = *head;
		*head = prior;
	}
	(*head)->next = rear;

	return (*head);
}

#include "lists.h"

/**
 * pop_listint - deletes the head node of a linked list
 * @head: pointer to the first element in the linked list
 * Return: node element
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int nodeelem;

	if (*head == NULL)
		return (0);

	temp = *head;
	nodeelem = (*head)->n;
	*head = (*head)->next;

	free(temp);

	return (nodeelem);
}

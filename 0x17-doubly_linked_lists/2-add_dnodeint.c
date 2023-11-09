#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list
 * @head: double pointer to the head of the linked list
 * @n: value to be added to the new node
 * Return: pointer to the new node
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *nnode;

	if (!head)
		return (NULL);
	nnode = malloc(sizeof(dlistint_t));
	if (!nnode)
		return (NULL);
	nnode->n = n;
	nnode->prev = NULL;
	nnode->next = *head;
	*head = nnode;
	if (nnode->next)
		(nnode->next)->prev = nnode;
	return (nnode);
}

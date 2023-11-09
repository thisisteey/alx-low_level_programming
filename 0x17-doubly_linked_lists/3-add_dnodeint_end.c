#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: double pointer to the head of the linked list
 * @n: integer value to be added to the new node
 * Return: pointer to the new node
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *nnode, *headnode;

	nnode = malloc(sizeof(dlistint_t));
	if (!nnode)
		return (NULL);
	nnode->n = n;
	nnode->next = NULL;
	headnode = *head;
	if (headnode)
	{
		while (headnode->next)
			headnode = headnode->next;
		headnode->next = nnode;
	}
	else
	{
		*head = nnode;
	}
	nnode->prev = headnode;
	return (nnode);
}

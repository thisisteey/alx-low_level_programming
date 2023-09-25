#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node in a linkd list
 * @head: pointer to the first node in the list
 * @idx: index where the node will be added
 * @n: data to insert in the new node
 * Return: address of the new node or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *newnode, *cpy = *head;
	unsigned int x;

	newnode = malloc(sizeof(listint_t));
	if (newnode == NULL)
		return (NULL);

	newnode->n = n;

	if (idx == 0)
	{
		newnode->next = cpy;
		*head = newnode;
		return (newnode);
	}
	for (x = 0 ; x < (idx - 1) ; x++)
	{
		if (cpy == NULL || cpy->next == NULL)
			return (NULL);

		cpy = cpy->next;
	}
	newnode->next = cpy->next;
	cpy->next = newnode;

	return (newnode);
}

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
	listint_t *newnode, *tmp;
	unsigned int x = 0;

	newnode = malloc(sizeof(listint_t));

	if (!newnode)
	{
		return (NULL);
	}
	newnode->n = n;

	tmp = *head;
	while (tmp)
	{
		if (x == idx)
		{
			newnode->next = tmp;
		}
		tmp = tmp->next;
		x++;
	}
	return (newnode);
}

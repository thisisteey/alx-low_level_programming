#include "lists.h"

/**
 * insert_dnodeint_at_index -  inserts a new node at a given position
 * @h: double pointer to the head of the linked list
 * @idx: index to insert the new node
 * @n: value to be added to the new node
 * Return: pointer to the new node
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *nnode, *headnode;
	unsigned int x;

	nnode = NULL;
	if (idx == 0)
		nnode = add_dnodeint(h, n);
	else
	{
		headnode = *h;
		x = 1;
		if (headnode)
			while (headnode->prev)
				headnode = headnode->prev;
		while (headnode)
		{
			if (x == idx)
			{
				if (!headnode->next)
					nnode = add_dnodeint_end(h, n);
				else
				{
					nnode = malloc(sizeof(dlistint_t));
					if (nnode)
					{
						nnode->n = n;
						nnode->next = headnode->next;
						nnode->prev = headnode;
						headnode->next->prev = nnode;
						headnode->next = nnode;
					}
				}
				break;
			}
			headnode = headnode->next;
			x++;
		}
	}
	return (nnode);
}

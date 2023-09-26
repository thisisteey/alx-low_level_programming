#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to the head of the list
 * Return: address of the node where the loop starts,
 * or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tardy = head;
	listint_t *swift = head;

	if (!head)
		return (NULL);
	while (tardy && swift && swift->next)
	{
		swift = swift->next->next;
		tardy = tardy->next;
		if (swift == tardy)
		{
			tardy = head;
			while (tardy != swift)
			{
				tardy = tardy->next;
				swift = swift->next;
			}
			return (swift);
		}
	}
	return (NULL);
}

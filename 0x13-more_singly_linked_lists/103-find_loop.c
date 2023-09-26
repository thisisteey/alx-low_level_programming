#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to the head of the list
 * Return: address of the node where the loop starts,
 * or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tardy, *swift;

	if (head == NULL || head->next == NULL)
		return (NULL);

	tardy = head->next;
	swift = (head->next)->next;

	while (swift)
	{
		if (tardy == swift)
		{
			tardy = swift;

			while (tardy != swift)
			{
				tardy = tardy->next;
				swift = swift->next;
			}
			return (tardy);
		}
		tardy = tardy->next;
		swift = (swift->next)->next;
	}
	return (NULL);
}

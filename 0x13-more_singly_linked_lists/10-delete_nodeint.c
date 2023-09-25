#include "lists.h"

/**
 * delete_nodeint_at_index - deletes a node in a linked list at a certain index
 * @head: pointer to the first element in the list
 * @index: index of the node to delete
 * Return: 1 on success and -1 on failure
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *cpy = *head;
	unsigned int x;

	if (cpy == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(cpy);
		return (1);
	}
	for (x = 0 ; x < (index - 1); x++)
	{
		if (cpy->next == NULL)
			return (-1);
		cpy = cpy->next;
	}
	temp = cpy->next;
	cpy->next = temp->next;
	free(temp);
	return (1);
}

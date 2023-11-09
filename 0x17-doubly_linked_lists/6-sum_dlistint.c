#include "lists.h"

/**
 * sum_dlistint - sum up all the data (n) of a dlistint_t linked list
 * @head: pointer to the head of the linked list
 * Return: the sum of all the data (n) of the linked list
 */
int sum_dlistint(dlistint_t *head)
{
	int total = 0;

	if (head)
	{
		while (head->prev)
			head = head->prev;
		while (head)
		{
			total += head->n;
			head = head->next;
		}
	}
	return (total);
}

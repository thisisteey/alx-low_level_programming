#include "lists.h"

/**
 * sum_listint - calculates the sum of all the data in a list
 * @head: first node in the linked list
 * Return: sum of the data calculated
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}

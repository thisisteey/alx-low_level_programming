#include "lists.h"

/**
 * count_unique_nodes - count the number of uniques nodes
 * @head: pointer to the head of the list
 * Return: 0 on code success
 */
size_t count_unique_nodes(const listint_t *head)
{
	listint_t *slowptr, *fastptr;
	size_t unique_nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	slowptr = head->next;
	fastptr = (head->next)->next;

	while (fastptr)
	{
		if (slowptr == fastptr)
		{
			slowptr = fastptr;
			while (slowptr != fastptr)
			{
				unique_nodes++;
				slowptr = slowptr->next;
				fastptr = fastptr->next;
			}
			slowptr = slowptr->next;
			while (slowptr != fastptr)
			{
				unique_nodes++;
				slowptr = slowptr->next;
			}
			return (unique_nodes);
		}
		slowptr = slowptr->next;
		fastptr = (fastptr->next)->next;
	}
	return (0);
}

/**
 * print_listint_safe - prints a list safely
 * @head: pointer to the head of a list
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t unique_nodes, counter = 0;

	unique_nodes = count_unique_nodes(head);

	if (unique_nodes == 0)
	{
		for (; head != NULL ; unique_nodes++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}
	else
	{
		for (counter = 0 ; counter < unique_nodes ; counter++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
		printf("-> [%p] %d\n", (void *)head, head->n);
	}
	return (unique_nodes);
}

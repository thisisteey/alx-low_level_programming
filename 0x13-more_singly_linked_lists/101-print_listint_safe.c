#include "lists.h"

/**
 * print_listint_safe - prints a list safely
 * @head: pointer to the head of a list
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t numnode = 0;
	const listint_t *initialhead = NULL;

	if (head == NULL)
		return (0);

	while (head != NULL && head != initialhead)
	{
		if (initialhead == NULL)
			initialhead = head;
		printf("[%p] %d\n", (void *) head, head->n);
		head = head->next;
		numnode++;
	}
	if (head == initialhead)
	{
		printf("-> [%p] %d\n", (void *) head, head->n);
		exit(98);
	}
	return (numnode);
}

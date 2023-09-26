#include "lists.h"

/**
 * looped_listint_len - Counts the number of unique nodes
 * @head: A pointer to the head of the list
 * Return: return 0
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *slow, *fast;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	slow = head->next;
	fast = (head->next)->next;

	while (fast)
	{
		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				nodes++;
				slow = slow->next;
				fast = fast->next;
			}
			slow = slow->next;
			while (slow != fast)
			{
				nodes++;
				slow = slow->next;
			}

			return (nodes);
		}
		slow = slow->next;
		fast = (fast->next)->next;
	}
	return (0);
}

/**
 * print_listint_safe - Prints a list
 * @head: A pointer to the head of the list
 * Return: The number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes, index = 0;

	nodes = looped_listint_len(head);

	if (nodes == 0)
	{
		for (; head != NULL; nodes++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}
	else
	{
		for (index = 0; index < nodes; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
		printf("-> [%p] %d\n", (void *)head, head->n);
	}
	return (nodes);
}

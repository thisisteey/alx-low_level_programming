#include "../search_algos.h"

/**
 * print_list - prints the content of a listint_t
 * @list: the pointer to the head of the list
 * Return: void
 */
void print_list(const listint_t *list)
{
	printf("List:\n");
	while (list)
	{
		printf("Index[%lu] = [%d]\n", list->index, list->n);
		list = list->next;
	}
	printf("\n");
}

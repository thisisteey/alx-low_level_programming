#include "../search_algos.h"

/**
 * print_skiplist - dump the content of a skiplist_t
 * @list: the pointer to the head of the list
 * Return: void
 */
void print_skiplist(const skiplist_t *list)
{
	const skiplist_t *newnd;

	printf("List:\n");
	for (newnd = list; newnd; newnd = newnd->next)
	{
		printf("Index[%lu] = [%d]\n", newnd->index, newnd->n);
	}
	printf("\nExpress lane:\n");
	for (newnd = list; newnd; newnd = newnd->express)
	{
		printf("Index[%lu] = [%d]\n", newnd->index, newnd->n);
	}
	printf("\n");
}

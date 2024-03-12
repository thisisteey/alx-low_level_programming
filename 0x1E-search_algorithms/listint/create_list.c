#include "../search_algos.h"

void free_list(listint_t *list);

/**
 * create_list - creates a single linked list
 * @array: the pointer to the array to use to fill the list
 * @size: size of the array
 * Return: the pointer to the head of the created list or NULL
 */
listint_t *create_list(int *array, size_t size)
{
	listint_t *list;
	listint_t *newnd;

	list = NULL;
	while (array && size--)
	{
		newnd = malloc(sizeof(*newnd));
		if (!newnd)
		{
			free_list(list);
			return (NULL);
		}
		newnd->n = array[size];
		newnd->index = size;
		newnd->next = list;
		list = newnd;
	}
	return (list);
}

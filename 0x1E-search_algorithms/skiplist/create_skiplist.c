#include "../search_algos.h"

void free_skiplist(skiplist_t *list);
void init_exp_lane(skiplist_t *list, size_t size);

/**
 * init_exp_lane - initializes the express lane of the linked list
 * @list: the pointer to the head node of the list
 * @size: the number of nodes in the list
 * Return: void
 */
void init_exp_lane(skiplist_t *list, size_t size)
{
	const size_t step_size = sqrt(size);
	size_t idx;
	skiplist_t *prevnd;

	for (prevnd = list, idx = 0 ; idx < size ; ++idx, list = list->next)
	{
		if (idx % step_size == 0)
		{
			prevnd->express = list;
			prevnd = list;
		}
	}
}

/**
 * create_skiplist - Create a single linked list
 *
 * @array: Pointer to the array used to fill the list
 * @size: Size of the array
 *
 * Return: A pointer to the head of the created list (NULL on failure)
 */
skiplist_t *create_skiplist(int *array, size_t size)
{
	skiplist_t *list;
	skiplist_t *newnd;
	size_t save_size;

	list = NULL;
	save_size = size;
	while (array && size--)
	{
		newnd = malloc(sizeof(*newnd));
		if (!newnd)
		{
			free_skiplist(list);
			return (NULL);
		}
		newnd->n = array[size];
		newnd->index = size;
		newnd->express = NULL;
		newnd->next = list;
		list = newnd;
	}
	init_exp_lane(list, save_size);
	return (list);
}

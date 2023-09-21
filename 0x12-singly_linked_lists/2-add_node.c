#include "lists.h"

/**
 * add_node - adds a new node at the neginning of a list
 * @head: head of the linked list
 * @str: string to the be addes to the list
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *newn;
	unsigned int x, count = 0;

	newn = malloc(sizeof(list_t));
	if (newn == NULL)
		return (NULL);

	newn->str = strdup(str);
	for (x = 0 ; str[x] ; x++)
		count++;
	newn->len = count;
	newn->next = *head;
	*head = newn;

	return (*head);
}

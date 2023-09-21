#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a list
 * @head: heand on the singly linked list
 * @str: string to be added
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *newn, *temp;
	unsigned int x, count = 0;

	newn = malloc(sizeof(list_t));
	if (newn == NULL)
		return (NULL);
	newn->str = strdup(str);
	for (x = 0 ; str[x] != '\0' ; x++)
		count++;
	newn->len = count;
	newn->next = NULL;
	temp = *head;

	if (temp == NULL)
		*head = newn;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newn;
	}
	return (*head);

}

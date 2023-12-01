#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - function that creates a sorted hash table
 * @size: size of the sorted hash table to be created
 * Return: pointer to the created sorted hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *shsht;
	unsigned long int x;

	shsht = malloc(sizeof(shash_table_t));
	if (shsht == NULL)
		return (NULL);
	shsht->size = size;
	shsht->array = malloc(sizeof(shash_node_t *) * size);
	if (shsht->array == NULL)
		return (NULL);
	for (x = 0 ; x < size ; x++)
		shsht->array[x] = NULL;
	shsht->shead = NULL;
	shsht->stail = NULL;
	return (shsht);
}

/**
 * shash_table_set - adds elements to a sorted hash table
 * @ht: pointer to the sorted hash table
 * @key: ket to add to the sorted hash table
 * @value: value associated with the key
 * Return: 1 if successful, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *nnode, *tmpnode;
	char *valcpy;
	unsigned long int idx;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);
	valcpy = strdup(value);
	if (valcpy == NULL)
		return (0);
	idx = key_index((const unsigned char *)key, ht->size);
	tmpnode = ht->shead;
	while (tmpnode)
	{
		if (strcmp(tmpnode->key, key) == 0)
		{
			free(tmpnode->value);
			tmpnode->value = valcpy;
			return (1);
		}
		tmpnode = tmpnode->snext;
	}
	nnode = malloc(sizeof(shash_node_t));
	if (nnode == NULL)
	{
		free(valcpy);
		return (0);
	}
	nnode->key = strdup(key);
	if (nnode->key == NULL)
	{
		free(valcpy);
		free(nnode);
		return (0);
	}
	nnode->value = valcpy;
	nnode->next = ht->array[idx];
	ht->array[idx] = nnode;
	if (ht->shead == NULL)
	{
		nnode->sprev = NULL;
		nnode->snext = NULL;
		ht->shead = nnode;
		ht->stail = nnode;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		nnode->sprev = NULL;
		nnode->snext = ht->shead;
		ht->shead->sprev = nnode;
		ht->shead = nnode;
	}
	else
	{
		tmpnode = ht->shead;
		while (tmpnode->snext != NULL && strcmp(tmpnode->snext->key, key) < 0)
			tmpnode = tmpnode->snext;
		nnode->sprev = tmpnode;
		nnode->snext = tmpnode->snext;
		if (tmpnode->snext == NULL)
			ht->stail = nnode;
		else
			tmpnode->snext->sprev = nnode;
		tmpnode->snext = nnode;
	}
	return (1);
}

/**
 * shash_table_get - retrieves the value associated with a key
 * @ht: pointer to the sorted hash table
 * @key: key to retreieve the value for
 * Return: the value associated with the element or NULL otherwise
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *currnode;
	unsigned long int idx;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);
	idx = key_index((const unsigned char *)key, ht->size);
	if (idx >= ht->size)
		return (NULL);
	currnode = ht->shead;
	while (currnode != NULL && strcmp(currnode->key, key) != 0)
		currnode = currnode->snext;
	return ((currnode == NULL) ? NULL : currnode->value);
}

/**
 * shash_table_print - prints a sorted hash table
 * @ht: pointer to the sorted hash table
 * Return: void
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *currnode;

	if (ht == NULL)
		return;
	currnode = ht->shead;
	printf("{");
	while (currnode != NULL)
	{
		printf("'%s': '%s'", currnode->key, currnode->value);
		currnode = currnode->snext;
		if (currnode != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a sorted hash table in reverse
 * @ht: pointer to the sorted hash table
 * Return: void
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *currnode;

	if (ht == NULL)
		return;
	currnode = ht->stail;
	printf("{");
	while (currnode != NULL)
	{
		printf("'%s': '%s'", currnode->key, currnode->value);
		currnode = currnode->sprev;
		if (currnode != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash  table
 * @ht: pointer to the sorted hash table
 * Return: void
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *headnode = ht;
	shash_node_t *currnode, *tmpnode;

	if (ht == NULL)
		return;
	currnode = ht->shead;
	while (currnode)
	{
		tmpnode = currnode->snext;
		free(currnode->key);
		free(currnode->value);
		free(currnode);
		currnode = tmpnode;
	}
	free(headnode->array);
	free(headnode);
}

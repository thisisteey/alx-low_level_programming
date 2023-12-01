#include "hash_tables.h"

/**
 * hash_table_set - adds an element in a hash table
 * @ht: pointer to the hash table
 * @key: key to add
 * @value: value associated with the key
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *nnode;
	char *valcpy;
	unsigned long int idx, x;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);
	valcpy = strdup(value);
	if (valcpy == NULL)
		return (0);
	idx = key_index((const unsigned char *)key, ht->size);
	for (x = idx ; ht->array[x] ; x++)
	{
		if (strcmp(ht->array[x]->key, key) == 0)
		{
			free(ht->array[x]->value);
			ht->array[x]->value = valcpy;
			return (1);
		}
	}
	nnode = malloc(sizeof(hash_node_t));
	if (nnode == NULL)
	{
		free(valcpy);
		return (0);
	}
	nnode->key = strdup(key);
	if (nnode->key == NULL)
	{
		free(nnode);
		return (0);
	}
	nnode->value = valcpy;
	nnode->next = ht->array[idx];
	ht->array[idx] = nnode;
	return (1);
}

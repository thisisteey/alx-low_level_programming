#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value associated with a key in a hash table
 * @ht: pointer to the hash table
 * @key: key to retrieve the value for
 * Return: the value associated with the element, or NULL if otherwise
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *currnode;
	unsigned long int idx;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);
	idx = key_index((const unsigned char *)key, ht->size);
	if (idx >= ht->size)
		return (NULL);
	currnode = ht->array[idx];
	while (currnode && strcmp(currnode->key, key) != 0)
		currnode = currnode->next;
	return ((currnode == NULL) ? NULL : currnode->value);
}

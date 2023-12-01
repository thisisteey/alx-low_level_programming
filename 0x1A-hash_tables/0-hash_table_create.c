#include "hash_tables.h"

/**
 * hash_table_create - function to create a hash table
 * @size: size of the hash table array
 * Return: pointer to the newly created hash table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *newht;
	unsigned long int x;

	newht = malloc(sizeof(hash_table_t));
	if (newht == NULL)
		return (NULL);
	newht->size = size;
	newht->array = malloc(sizeof(hash_node_t *) * size);
	if (newht->array == NULL)
		return (NULL);
	for (x = 0 ; x < size ; x++)
		newht->array[x] = NULL;
	return (newht);
}

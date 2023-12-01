#include "hash_tables.h"

/**
 * key_index - retrieves the index for a given key in a hash table
 * @key: the key to get the index for
 * @size: the size of the hash table array
 * Return: the calculated index of the provided key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hashval = hash_djb2(key);

	unsigned long int idx = hashval % size;

	return (idx);
}

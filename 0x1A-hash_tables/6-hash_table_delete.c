#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table and its elements
 * @ht: pointer to the hash table
 * Return: void
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *headnode = ht;
	hash_node_t *currnode, *tmpnode;
	unsigned long int x;

	for (x = 0 ; x < ht->size ; x++)
	{
		if (ht->array[x] != NULL)
		{
			currnode = ht->array[x];
			while (currnode != NULL)
			{
				tmpnode = currnode->next;
				free(currnode->key);
				free(currnode->value);
				free(currnode);
				currnode = tmpnode;
			}
		}
	}
	free(headnode->array);
	free(headnode);
}

#include "hash_tables.h"

/**
 * hash_table_print - prints the content of a hash table
 * @ht: pointer to the hash table
 * Return: void
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *currnode;
	unsigned char comma = 0;
	unsigned long int x;

	if (ht == NULL)
		return;
	printf("{");
	for (x = 0 ; x < ht->size ; x++)
	{
		if (ht->array[x] != NULL)
		{
			if (comma == 1)
				printf(", ");
			currnode = ht->array[x];
			while (currnode != NULL)
			{
				printf("'%s': '%s'", currnode->key, currnode->value);
				currnode = currnode->next;
				if (currnode != NULL)
					printf(", ");
			}
			comma = 1;
		}
	}
	printf("}\n");
}

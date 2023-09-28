#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to the binary
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *b)
{
	int x;
	unsigned int num;

	num = 0;
	if (b == NULL)
		return (0);
	for (x = 0 ; b[x] != '\0' ; x++)
	{
		if (b[x] != '0' && b[x] != '1')
			return (0);
	}
	for (x = 0 ; b[x] != '\0' ; x++)
	{
		num <<= 1;
		if (b[x] == '1')
			num += 1;
	}
	return (num);
}

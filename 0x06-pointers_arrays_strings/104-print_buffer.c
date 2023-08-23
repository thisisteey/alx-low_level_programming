#include "main.h"
#include <stdio.h>

/**
 * print_buffer - prints a buffer
 * @b: buffer to be printed
 * @size: size of buffer
 * Return: void
 */

void print_buffer(char *b, int size)
{
	int x, y, a;

	x = 0;

	if (size <= 0)
	{
		printf("\n");
		return;
	}
	while (x < size)
	{
		y = size - x < 10 ? size - x : 10;
		printf("%08x: ", x);
		for (a = 0; a < 10; a++)
		{
			if (a < y)
				printf("%02x", *(b + x + a));
			else
				printf("  ");
			if (a % 2)
			{
				printf(" ");
			}
		}
		for (a = 0; a < y; a++)
		{
			int q = *(b + x + a);

			if (q < 32 || q > 132)
			{
				q = '.';
			}
			printf("%c", q);
		}
		printf("\n");
		x += 10;
	}
}

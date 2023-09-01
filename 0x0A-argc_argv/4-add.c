#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - prints the sum of two positive numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on code success
 */
int main(int argc, char *argv[])
{
	int x;
	unsigned int y, sum = 0;
	char *a;

	if (argc > 1)
	{
		for (x = 1 ; x < argc ; x++)
		{
			a = argv[x];
			for (y = 0 ; y < strlen(a) ; y++)
			{
				if (a[y] < 48 || a[y] > 57)
				{
					printf("Error\n");
					return (1);
				}
			}
			sum += atoi(a);
			a++;
		}
		printf("%d\n", sum);
	}
	else
	{
		printf("0\n");
	}
	return (0);
}

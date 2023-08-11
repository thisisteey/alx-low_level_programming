#include <stdio.h>

/**
 * main - the entry point of the code
 *
 * Return: 0 on each code success
 */

int main(void)
{
	int i;

	for (i = 0 ; i < 10 ; i++)
		putchar(i + '0');
	putchar('\n');
	return (0);
}

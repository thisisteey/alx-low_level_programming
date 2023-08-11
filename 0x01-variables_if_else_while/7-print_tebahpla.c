#include <stdio.h>

/**
 * main - the entry point of the code
 *
 * Return: 0 on success of each code
 */

int main(void)
{
	char i;

	for (i = 'z' ; i >= 'a' ; i--)
		putchar(i);
	putchar('\n');
	return (0);
}

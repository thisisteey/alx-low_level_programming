#include <stdio.h>

/**
 * main - the entry point of the code
 *
 * Return: 0 on code success
 */

int main(void)
{
	char i;

	for (i = 'a' ; i <= 'z' ; i++)
		if (i != 'q' && i != 'e')
			putchar(i);
	putchar('\n');
	return (0);
}

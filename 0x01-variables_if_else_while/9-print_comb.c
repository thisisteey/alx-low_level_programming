#include <stdio.h>

/**
 * main - the entry point of the code
 *
 * Return: 0 on success of the code
 */

int main(void)
{
	int i;

	for (i = 0 ; i < 10 ; i++)
	{
		if (i == '9')
			putchar(i + '0');
		else
		{
			putchar(i + '0');
			putchar(',');
			putchar(' ');
		}
	}
	return (0);
}

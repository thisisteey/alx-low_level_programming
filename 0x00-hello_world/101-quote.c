#include <stdio.h>
#include <unistd.h>
/**
 * main - the entry point of the code
 *
 * Return: 1 on code success
 */

int main(void)
{
	write(2, "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n", 59);
	return (1);
}

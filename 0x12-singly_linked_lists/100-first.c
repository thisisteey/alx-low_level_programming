#include <stdio.h>

/**
 * before_main - function executed before the main function
 * Return: void
 */
void __attribute__ ((constructor)) before_main()
{
	printf("You're beat! and yet, you must allow");
	printf(",\nI bore my house upon my back!\n");
}

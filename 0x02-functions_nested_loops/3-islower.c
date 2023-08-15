#include "main.h"

/**
 * _islower - function to check for lower case character
 * @c: parameter to be checked
 * Return: 1 or 0 on code usccess
 */

int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

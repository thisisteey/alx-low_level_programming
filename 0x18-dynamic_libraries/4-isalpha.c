#include "main.h"

/**
 * _isalpha - function to check alphabets in lower or upper case
 * @c: parameter to be checked
 * Return: 1 or 0
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

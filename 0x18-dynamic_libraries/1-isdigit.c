#include "main.h"

/**
 * _isdigit - function that checks for a digit from 0 through 9
 * @c: parameter to be checked
 * Return: 1 on code success and 0 if otherwise
 */

int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

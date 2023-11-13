#include "main.h"

/**
 * _abs - function to find the absolute value ofa number
 * @x: parameter to be checked
 * Return: -x or x on code success
 */

int _abs(int x)
{
	if (x < 0)
		return (-x);
	else if (x >= 0)
		return (x);
	return (0);
}

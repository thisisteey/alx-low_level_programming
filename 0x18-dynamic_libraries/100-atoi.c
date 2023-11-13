 #include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 * Return: 0 if there are no numbers in the string
 */
int _atoi(char *s)
{
	int x, y, a, len, b, digit;

	x = 0;
	y = 0;
	a = 0;
	len = 0;
	b = 0;
	digit = 0;

	while (s[len] != '\0')
		len++;
	while (x < len && b == 0)
	{
		if (s[x] == '-')
			++y;
		if (s[x] >= '0' && s[x] <= '9')
		{
			digit = s[x] - '0';
			if (y % 2)
				digit = -digit;
			a = a * 10 + digit;
			b = 1;
			if (s[x + 1] < '0' || s[x + 1] > '9')
				break;
			b = 0;
		}
		x++;
	}
	if (b == 0)
		return (0);
	return (a);
}

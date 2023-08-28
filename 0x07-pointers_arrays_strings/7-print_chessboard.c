#include "main.h"

/**
 * print_chessboard - function to print a chessboard
 * @a: array
 * Return: ) on code success
 */
void print_chessboard(char (*a)[8])
{
	int x;
	int y;

	for (x = 0 ; x < 8 ; x++)
	{
		for (y = 0 ; y < 8 ; y++)
			_putchar(a[x][y]);
		_putchar('\n');
	}
}

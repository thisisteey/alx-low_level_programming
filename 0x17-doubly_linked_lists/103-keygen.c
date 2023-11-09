#include "lists.h"

/**
 * main - generates key for the program crackme5
 * @argc: number of arguments in the program
 * @argv: pointer to the arguments
 * Return: 0 on code success
 */
int main(int argc, char *argv[])
{
	unsigned int x, y;
	size_t lent, sum;
	char *ch = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	char keygen[7] = "      ";

	if (argc != 2)
	{
		printf("Right usage: ./keygen5 username\n");
		return (1);
	}
	lent = strlen(argv[1]);
	keygen[0] = ch[(lent ^ 59) & 63];
	for (x = 0, sum = 0 ; x < lent ; x++)
		sum += argv[1][x];
	keygen[1] = ch[(sum ^ 79) & 63];
	for (x = 0, y = 1 ; x < lent ; x++)
		y *= argv[1][x];
	keygen[2] = ch[(y ^ 85) & 63];
	for (y = argv[1][0], x = 0 ; x < lent ; x++)
		if ((char)y <= argv[1][x])
			y = argv[1][x];
	srand(y ^ 14);
	keygen[3] = ch[rand() & 63];
	for (y = 0, x = 0 ; x < lent ; x++)
		y += argv[1][x] * argv[1][x];
	keygen[4] = ch[(y ^ 239) & 63];
	for (y = 0, x = 0 ; (char)x < argv[1][0] ; x++)
		y = rand();
	keygen[5] = ch[(y ^ 229) & 63];
	printf("%s\n", keygen);
	return (0);
}

#include "main.h"

/**
 * create_file - creates a file
 * @filename: name of the file to be created
 * @text_content: NULL terminated string to write to the file
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int o, w, lent = 0;

	if (!filename)
		return (-1);
	if (text_content != NULL)
	{
		for (lent = 0 ; text_content[lent];)
			lent++;
	}
	o = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(o, text_content, lent);

	if (o == -1 || w == -1)
		return (-1);
	close(o);
	return (1);
}

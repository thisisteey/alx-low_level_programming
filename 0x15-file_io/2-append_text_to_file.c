#include "main.h"

/**
 * append_text_to_file - appends text to the end of a file
 * @filename: pointer to the name of the file
 * @text_content: string to be added to the end of the file
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int o, w, lent = 0;

	if (!filename)
		return (-1);
	o = open(filename, O_WRONLY | O_APPEND);
	if (o == -1)
		return (-1);
	if (text_content  != NULL)
	{
		for (lent = 0 ; text_content[lent] ; lent++)
			;
		w = write(o, text_content, lent);
		if (w == -1)
			return (-1);
	}
	close(o);
	return (1);
}

#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX stdout
 * @filename: pointer to the filename
 * @letters: number of letters to be printed
 * Return: the actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t o, r, w;
	char *container;

	if (!filename)
		return (0);
	container = malloc(sizeof(char) * letters);
	if (!container)
		return (0);
	o = open(filename, O_RDONLY);
	r = read(o, container, letters);
	w = write(STDOUT_FILENO, container, r);

	if (o == -1 || r == -1 || w == -1 || w != r)
	{
		free(container);
		return (0);
	}
	free(container);
	close(o);
	return (w);
}

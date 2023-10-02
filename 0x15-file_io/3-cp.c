#include "main.h"

/**
 * allocate_memory - allocates 1024 bytes for a buffer
 * @filename: pointer to the name of the file
 * Return: pointer to the allocated buffer
 */
char *allocate_memory(char *filename)
{
	char *container;

	container = malloc(sizeof(char) * 1024);
	if (!container)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}
	return (container);
}

/**
 * close_fd - closes a file descriptor
 * @fd: file descriptor to be closed
 * Return: void
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * copy_file - copies the content ofa file to another
 * @argc: number of arguments
 * @argv: argument vector
 * Return: 0 on code success
 */
int copy_file(int argc, char *argv[])
{
	int src_fd, dest_fd, r, w;
	char *container;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	container = allocate_memory(argv[2]);
	src_fd = open(argv[1], O_RDONLY);
	r = read(src_fd, container, 1024);
	dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (src_fd == -1 || r == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(container);
			exit(98);
		}
		w = write(dest_fd, container, r);
		if (dest_fd == -1 || w == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(container);
			exit(99);
		}
		r = read(src_fd, container, 1024);
		dest_fd = open(argv[2], O_WRONLY | O_APPEND);
	} while (r > 0);
	free(container);
	close_fd(src_fd);
	close_fd(dest_fd);
	return (0);
}

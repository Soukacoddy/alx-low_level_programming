#include "main.h"

/**
 * read_textfile - read text file
 * @filename: The name of the file
 * @letters: number of letters
 * Return: number of letters
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	int i;
	int read_let;
	char *buf;

	if (filename == NULL)
		return (0);
	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buf);
		return (0);
	}

	read_let = read(fd, buf, letters);
	if (read_let == -1)
	{
		close(fd);
		free(buf);
		return (0);
	}

	for (i = 0; i < read_let; i++)
	{
		if (write(STDOUT_FILENO, &buf[i], 1) == -1)
		{
			close(fd);
			free(buf);
			return (0);
		}
	}
	close(fd);
	free(buf);
	return (read_let);
}

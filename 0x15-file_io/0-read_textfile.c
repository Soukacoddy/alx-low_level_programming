#include "main.h"

/**
 * read_textfile - Read a text file and prints the letters
 * @filename: filename.
 * @letters: numbers of letters printed.
 *
 * Return: number of letters printed. otherwise 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_data;
	ssize_t nrd, nwr;
	char *buf;

	if (filename)
	{
		file_data = open(filename, O_RDONLY);
		if (file_data == -1)
		{
			return (0);
		}
		buf = malloc(sizeof(char) * letters);
		if (buf == NULL)
		{
			close(file_data);
			return (0);
		}
		nrd = read(file_data, buf, letters);
		if (nrd == -1)
		{
			free(buf);
			close(file_data);
			return (0);
		}
		nwr = write(STDOUT_FILENO, buf, nrd);
		close(file_data);
		free(buf);
		if (nrd != nwr)
			return (0);
		return (nwr);
	}
	return (0);
}

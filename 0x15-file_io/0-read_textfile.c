#include "main.h"

/**
 * read_textfile - Read a text file and prints the letters
 * @filename: filename.
 * @letters: numbers of letters printed.
 *
 * Return: number of letters printed. otherwise 0
 */
ssize_t read_textfile(const char *filename, size_t letters);
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
		nrd = read(file_data, buf, letters);
		nwr = write(STDOUT_FILENO, buf, nrd);

		close(file_data);
		free(buf);
		return (nwr);
	}
	return (0);
}

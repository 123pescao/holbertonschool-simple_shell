#include "head.h"
/**
 * read_command - Reads a command from standard input.
 * @buffer: A character array where the read command will be stored.
 * Description: This function reads a line from standard input using getline.
 * Return: Returns 1 if a line is successfully read and stored,
 *         or 0 if end-of-file is reached or a read error occurs.
 */
int read_command(char *buffer)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&line, &len, stdin);

	if (read == -1)
	{
		free(line);
		return (0);
	}

	if (line[read - 1] == '\n')
	{
		line[read - 1] = '\0';
	}

	strcpy(buffer, line);
	free(line);
	return (1);
}

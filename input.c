#include "head.h"

void read_input(int fd, char *buffer)
{
	int bytes_read = read(fd, buffer, BUFFER_SIZE - 1);

	if (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
	}
	else if (bytes_read < 0)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}
}



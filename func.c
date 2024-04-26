#include "head.h"
/**
 * int_mode - Handles the interactive mode of the shell.
 *
 * Description: Continuously reads commands from the standard input,
 *              processes and executes them until "exit" is entered
 *              or an EOF is encountered.
 */
void int_mode(void)
{
	char buffer[BUFFER_SIZE];

	while (1)
	{
		printf("$ ");
		fflush(stdout);
		if (!read_command(buffer))
			break;

		process_input(buffer);
	}
}
/**
 * non_int_mode - Handles the non-interactive mode of the shell.
 * @stream: FILE stream from which to read the commands.
 *
 * Description: Reads commands from a given file stream, processes,
 *              and executes them until EOF.
 */
void non_int_mode(FILE *stream)
{
	char buffer[BUFFER_SIZE];
	int readStatus;

	(void)stream;

	while (1)
	{
		readStatus = read_command(buffer);
		if (!readStatus)
			break;

		process_input(buffer);
	}
}


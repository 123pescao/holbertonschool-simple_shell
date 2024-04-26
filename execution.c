#include "head.h"
/**
 * process_input - Processes the input string for execution.
 * @input: String containing the entire input to be parsed.
 *
 * Description: Takes a raw input string, parses it into arguments,
 *              and executes the command if valid.
 */
void process_input(char *input)
{
	char *args[MAX_ARGS];

	parse_command(input, args);

	if (args[0])
	{
		execute_command(args);
	}
}
/**
 * execute_command - Executes a command given an array of arguments.
 * @args: Array of strings where the first is the command and the rest
 *        are the arguments to that command.
 *
 * Description: Forks the current process and attempts to execute the
 *              command specified in args[0] with execve. The parent
 *              waits for the execution to finish.
 */
void execute_command(char *args[])
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
	}
	else
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
}
/**
 * parse_command - Parses a command line into an array of arguments.
 * @command: The command line string to parse.
 * @args: The array to populate with arguments.
 *
 * Description: Splits the command string into individual words,
 *              using space, tab, and newline as delimiters. The
 *              array of arguments is null-terminated.
 */
void parse_command(char *command, char *args[])
{
	int i = 0;

	args[i] = strtok(command, " \t\n");

	while (args[i] != NULL && i < MAX_ARGS - 1)
	{
		args[++i] = strtok(NULL, " \t\n");
	}
	args[i] = NULL;
}

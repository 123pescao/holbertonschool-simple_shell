#include "head.h"
#include <errno.h>
/**
 * execute- execute a command
 * @command: command
 */
void execute(char *args[])
{
	int status;
	pid_t pid;

	pid = fork();

	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			fprintf(stderr, "Error executing command: %s\n", strerror(errno));
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		do
		{
			waitpid(pid, &status, WUNTRACED);
		}
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	else
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
}
/**
 *parse_command: Parses the command input into an array of args
 *@command: input command string to arg
 *@args: the array to store the arguments
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
/**
 * dprompt- command prompt
 */
void dprompt(void)
{
	printf("$ ");
	fflush(stdout);
}
/**
 * int_mode- run shell in interactive
 */
void int_mode(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *args[MAX_ARGS];

	while (1)
	{
		dprompt();
		if (!fgets(command, MAX_COMMAND_LENGTH, stdin))
			break;

		if (strcmp(command, "exit\n") == 0)
			break;

		parse_command(command, args);
		execute(args);
	}
}
/**
 * non_int_mode- run shell in non_interactive
 * @stream: input stream
 */
void non_int_mode(FILE *stream)
{
	char command[MAX_COMMAND_LENGTH];
	char *args[MAX_ARGS];

	while (fgets(command, MAX_COMMAND_LENGTH, stream) != NULL)
	{
		parse_command(command, args);
		execute(args);
	}
}

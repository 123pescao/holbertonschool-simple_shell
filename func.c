#include "head.h"
/**
 * execute- execute a command
 * @command: command
 */
void execute(char *command)
{
	int status;
	char *args[4];
	pid_t pid;

	args[0] = "/bin/bash";
	args[1] = "-c";
	args[2] = command;
	args[3] = NULL;
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("execve");
			_exit(EXIT_FAILURE);
		}
	}
		else
		{
			waitpid(pid, &status, 0);
		}
}
/**
 * dprompt- command prompt
 */
void dprompt(void)
{
	printf("($) ");
	fflush(stdout);
}
/**
 * int_mode- run shell in interactive
 */
void int_mode(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		dprompt();

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\n");
			break;
		}
		command[strcspn(command, "\n")] = '\0';

		if (strcmp(command, "exit") == 0)
		{
			break;
		}

		execute(command);
	}
}
/**
 * non_int_mode- run shell in non_interactive
 * @stream: input stream
 */
void non_int_mode(FILE *stream)
{
	char command[MAX_COMMAND_LENGTH], c;
	int status, i = 0;
	pid_t pid;

	while (fgets(command, sizeof(command), stream) != NULL)
	{
		command[strcspn(command, "\n")] = '\0';
		execute(command);
	}
}

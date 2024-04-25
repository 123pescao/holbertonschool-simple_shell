#include "head.h"
/**
 * execute- execute a command
 * @command: command
 */
void execute(char *command)
{
	int status;
	char *args[4];

	args[0] = "/bin/bash";
	args[1] = "-c";
	args[2] = command;
	args[3] = NULL;
	
	pid_t = pid;
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
 * int_mode- run shell in interactive
 */
void int_mode(void)
{
	char command[MAX_COMMAND_LENGTH], c;
	pid_t pid;
	int status, i = 0;

	while (1)
	{
		printf("($) ");
		fflush(stdout);

		while (i < MAX_COMMAND_LENGTH - 1 && (c = getchar()) != EOF && c != '\n')
		{
			command[i++] = c;
		}

		command[i] = '\0';

		if (c == EOF)
		{
			printf("\n");
			break;
		}
		if (strcmp(command, "exit") == 0)
		{
			break;
		}

		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			execute(command);
		}
		else
		{
			waitpid(pid, &status, 0);
		}
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

	while ((c = fgetc(stream)) != EOF)
	{
		if (c == '\n' || i >= MAX_COMMAND_LENGTH - 1)
		{
			command[i] = '\0';

			pid = fork();

			if (pid == -1)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}
			else if (pid == 0)
			{
				execute(command);
			}
			else
			{
				waitpid(pid, &status, 0);
			}
		}
		else
		{
			command[i++] = c;
		}
	}

	if (i > 0)
	{
		command[i] = '\0';

		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			execute(command);
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}
}
/**
 *main- entry point
 *Return: 0
 */
int main(void)
{
	if (isatty(STDIN_FILENO))
	{
		int_mode();
	}
	else
	{
		non_int_mode(stdin);
	}
	return (0);
}

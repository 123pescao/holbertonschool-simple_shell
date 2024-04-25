#include "head.h"
/**
 * execute- execute a command
 * @command: command
 */
void execute(char *command)
{
	char *args[] = {command, NULL};

		if (execve(args[0], args, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
}
/**
 * int_mode- run shell in interactive
 */
void int_mode(void)
{
	int status;
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		printf("($) ");
		fflush(stdout);

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

		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
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
	char input[MAX_COMMAND_LENGTH];
	int status;

	while (fgets(command, sizeof(command), stream) != NULL)
	{
		command[strcspn(input, "\n")] = '\0';

		pid_t pid = fork();

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
 *main- entry point
 *Return: 0
 */
int main(void)
{
	if (isatty(fileno(stdin)))
	{
		int_mode();
	}
	else
	{
		non_int_mode(stdin);
	}
	return (0);
}

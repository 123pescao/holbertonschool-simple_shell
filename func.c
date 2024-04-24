#include "head.h"
/**
 * execute- execute a command
 * @command: command
 */
void execute(char *command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *args[] = {command. NULL};

		if (execve(args[0], args. NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}
}
/**
 * int_mode- run shell in interactive
 */
void int_mode(void)
{
	char input[MAX_INPUT_SIZE];

	while (1)
	{
		printf("($) ");

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("\n");
			break;
		}
		input[strcspn(input, "\n")] = '\0';
		if (strcmp(input, "exit") == 0)
		{
			break;
		}
		execute(input);
	}
}
/**
 * non_int_mode- run shell in non_interactive
 * @stream: input stream
 */
void non_int_mode(FILE *stream)
{
	char input[MAX_INPUT_SIZE];

	while (fgets(input, sizeof(input), stream) != NULL)
	{
		input[strcspn(input, "\n")] = '\0';
		execute(input);
	}
}
/**
 * main- entry point
 * @argc: number of coomand-line
 * @argv: array of command-line arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		int_mode();
	}
	else
	{
		FILE *input_stream = fopen(argv[1]. "r");

		if (input_stream == NULL)
		{
			perror("fopen");
			exit(EXIT_FAILURE);
		}
		non_int_mode(input_stream);
		fclose(input_stream);
	}
	return (0);
}

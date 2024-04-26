#include "head.h"
#include "head.h"
/**
 * process_input - Executes the command provided in the input string.
 * @input: String containing the command to be executed.
 *
 * Description: This function takes a raw input string, which is expected
 * to be a path to an executable file. It attempts to execute the command
 * using execve. If execve fails, it prints an appropriate error message.
 * The function assumes that no arguments are to be passed to the command
 * and that the environment will be minimal.
 *
 * Return: void. If an error occurs during execution, an error message is
 * printed to stderr using perror.
 */
void process_input(char *input)
{
	if (input && input[0])
	{
		char *argv[2];
		char *envp[] = { NULL };

		argv[0] = input;
		argv[1] = NULL;

		if (execve(input, argv, envp) == -1)
		{
			perror("Error executing command");
		}
	}
}


/**
 * execute_command - Executes a command in a child process.
 * @command: The command to execute.
 *
 * Description: Forks new process, attempts to execute command using execve.
 * The parent process waits for the execution to finish before continuing.
 */
void execute_command(char *command)
{
	pid_t pid;
	int status;
	char *argv[2];

	argv[0] = command;
	argv[1] = NULL;

	pid = fork();

	if (pid == 0)
	{
		if (execve(command, argv, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("fork");
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}

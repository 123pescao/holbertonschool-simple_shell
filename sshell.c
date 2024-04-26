#include "head.h"
/**
 * main - Entry point of the shell.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: Always returns 0.
 * Description: Starts the shell in either interactive or non-interactive
 *              mode based on whether the input is from a terminal.
 */
int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

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

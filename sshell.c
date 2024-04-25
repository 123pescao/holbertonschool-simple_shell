#include "head.h"
/**
 * main- Entry Point
 * Return: 0
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

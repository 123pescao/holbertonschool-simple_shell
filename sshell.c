#include "head.h"
#include "func.c"
/**
 * main- Entry Point
 * Return: 0
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		dprompt(void);

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		command[strcspn(command, "\n")] = '\0';

		execute(command);
	}
	return (0);
}

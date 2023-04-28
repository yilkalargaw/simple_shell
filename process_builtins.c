#include "shell.h"

/**
 * process_builtins - a function to process builtins
 * @command: the command
 * @args: the arguments
 *
 * Return: status
 */
int process_builtins(char *command, char *args[MAX_LENGTH])
{
	int i = 0, status = 0;

	if (_strncmp(command, "env", 3) == 0)
	{
		for (i = 0 ; environ[i] != NULL; i++)
			print_out_many(2, environ[i], "\n");
	}
	else if (_strncmp(command, "cd", 2) == 0)
	{
		if (args[1] == NULL)
			chdir(_getenv("HOME"));
		else if (chdir(args[1]) == -1)
			print_error("chdir failed");
	}
	else
		status = 1;

	return (status);
}

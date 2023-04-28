#include "shell.h"

/**
 * process_builtins - a function to process builtins
 * @command: the command
 * @args: the arguments
 *
 * Return: status
 */
int process_builtins(char *command, char *args[MAX_LENGTH], int count, char* argv0)
{
	int i = 0, status = 0;

	if (_strcmp(command, "env") == 0)
	{
		for (i = 0 ; environ[i] != NULL; i++)
			print_out_many(2, environ[i], "\n");
	}
	else if (_strcmp(command, "cd") == 0)
	{
		if (args[1] == NULL)
			chdir(_getenv("HOME"));
		else if (chdir(args[1]) == -1)
		{
			print_error_many(2, argv0, ": "); \
			print_int_stderr(count); \
			print_error_many(5, ": ", command, ": can't cd to ", args[1], "\n"); \
		}
	}
	else
		status = 1;

	return (status);
}

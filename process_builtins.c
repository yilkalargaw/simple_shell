#include "shell.h"

/**
 * process_builtins - a function to process builtins
 * @command: the command
 * @args: the arguments
 * @cnt: execution line count
 * @ag0: name of executable
 *
 * Return: status
 */
int process_builtins(char *command, char *args[MAX_LENGTH], int cnt, char *ag0)
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
			print_error_many(2, ag0, ": ");
			print_int_stderr(cnt);
			print_error_many(5, ": ", command, ": can't cd to ", args[1], "\n");
		}
	}
	else if (_strcmp(command, "setenv") == 0)
	{
		/* value = _getenv(arg[1]); */
		if (args[1] == NULL || args[2] == NULL)
			return (-10);
		_setenv(args[1], args[2], 1);
	}
	else if (_strcmp(command, "unsetenv") == 0)
	{
		/* value = _getenv(arg[1]); */
		if (args[1] == NULL)
			return (-10);
		_unsetenv(args[1]);
	}
	else
		status = 1;

	return (status);
}

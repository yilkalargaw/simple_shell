#include "shell.h"

/**
 * main - the main exec loop for the shell
 *
 * Return: status code
 */
int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	char *ps = "hsh-v01 > ", *command, *args[MAX_LENGTH], **env_var = environ;
	int i;
	ssize_t nread;

	while (1)
	{
		print_out(ps); /* displays prompt */
		nread = getline(&buffer, &bufsize, stdin); /* input */

		if (nread == -1)
			break;

		command = strtok(buffer, " \n"); /* tokenize */

		if (command == NULL) /* case for nocommand given*/
			continue;

		 /* if command is exit break */
		if (_strcmp(command, "exit") == 0)
			break;

		if (_strcmp(command, "env") == 0)
		{
			for (; *env_var != NULL; env_var++)
				print_out_many(2, *env_var, "\n");

			env_var = environ;
			continue;
		}

		args[0] = command;

		for (i = 1; i < MAX_LENGTH; i++) /* parse other tokens aka arguments */
		{
			args[i] = strtok(NULL, " \n");

			if (args[i] == NULL)
				break;
		}

		if (_strcmp(command, "cd") == 0)
		{
			if (args[1] == NULL)
				chdir(_getenv("HOME"));
			else if (chdir(args[1]) == -1)
			{
				print_error("chdir failed");
				continue;
			}
		}

		if (checkpath(command) == 0)
		{
			print_error("command not in path \n");
			continue;
		}

		if (fork() == 0)
			execvp(command, args);
		else
			wait(NULL);
	}

	return (0);
}

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

		if (command == NULL)
			continue;

		if (_strcmp(command, "exit") == 0)
			break;

		PARSE_ARGUMENTS();

		PROCESS_BUILTINS();

		if (checkpath(command) == 0)
		{
			print_error("command not in path \n");
			continue;
		}

		fork() == 0 ? execvp(command, args) : wait(NULL);

	}

	return (0);
}

#include "shell.h"

/**
 * main - the main exec loop for the shell
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: status code
 */
int main(int argc, char *argv[])
{
	char *buffer = NULL;
	size_t bufsize = 0;
	char *ps = "$ ", *command, *args[MAX_LENGTH], **env_var = environ;
	int i, count = 1;
	ssize_t nread;

	argc += 0;

	while (1)
	{
		PRINT_IF_TERMINAL(ps); /* displays prompt */
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
			PRINT_ERROR_ATTY(count);
			continue;
		}

		fork() == 0 ? execvp(command, args) : wait(NULL);
		count++;
	}

	FREE_MEM(buffer);
	return (0);
}

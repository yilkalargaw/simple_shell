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
	int i, count = 0, status = 0;
	ssize_t nread;
	pid_t pid;

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
		count++;

		EXIT_IF_COMMAND_IS_EXIT();

		PARSE_ARGUMENTS();
		PROCESS_BUILTINS();

		if (checkpath(command) == 0)
		{
			PRINT_ERROR_ATTY(count);
			continue;
		}

		MANAGE_FORKING(pid);
	}

	FREE_MEM(buffer);
	return (status);
}

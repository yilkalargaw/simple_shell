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
	char *buffer = NULL, *comment_start;
	size_t bufsize = 0;
	char *ps = "$ ", *command, *args[MAX_LENGTH]; /* **env_var = environ; */
	int i, count = 0, status = 0;
	ssize_t nread;
	pid_t pid;

	argc = (argv[0] != NULL) ? (argc + 0) : argc;

	while (1)
	{
		PRINT_IF_TERMINAL(ps); /* displays prompt */
		nread = getline(&buffer, &bufsize, stdin); /* input */

		if (nread == -1)
			break;

		PROCESS_COMMENTS_AND_BUFFER(buffer);

		command = _strtok(buffer, " \n"); /* tokenize */

		if (command == NULL)
		{
			status = 0;
			continue;
		}
		count++;
		EXIT_IF_COMMAND_IS_EXIT();

		PARSE_ARGUMENTS();
		if (process_builtins(command, args, count, argv[0]) == 0 ||
			process_builtins(command, args, count, argv[0]) == -10)
			continue;

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

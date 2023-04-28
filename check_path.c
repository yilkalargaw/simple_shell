#include "shell.h"

/**
 * checkpath - checks if command exists in path
 * @command: command to check
 *
 * Return: 1 if command exists in path, 0 otherwise
 */
int checkpath(char *command)
{
	char *path = _getenv("PATH");
	char *path_copy = _strdup(path);
	int argc = 0, found = 0, i = 0, j = 0;
	char *token = _strtok(path_copy, ":"); /* path commands */
	char *args[MAX_LINE / 2 + 1]; /* command line arguments */

	for (; token != NULL; token = _strtok(NULL, ":"))
		args[argc++] = token;

	args[argc] = NULL;
	FREE_MEM2(path_copy, token);

	if (access(command, F_OK) != -1)
		return (1);

	/* Check if command exists in path */
	for (i = 0; i < argc; i++)
	{
		char cmd[MAX_LINE], *p = cmd;

		for (j = 0; args[i][j] != '\0'; j++)
			*p++ = args[i][j];

		*p++ = '/';

		for (j = 0; command[j] != '\0'; j++)
		*p++ = command[j];

		*p = '\0';

		if (access(cmd, F_OK) != -1)
		{
			found = 1;
			break;
		}
	}
	return (found);
}

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
	char *ps = "hsh-v01 > "; /*prompt string*/
	char *command;
	char *args[MAX_LENGTH];
	int i;
	ssize_t nread;
	char **env_var = environ;

	while (1)
	{
		printf("%s", ps); /* displays prompt */
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
			while (*env_var != NULL)
			{
				printf("%s\n", *env_var);
				env_var++;
			}

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

		if (checkpath(command) == 0)
		{
			printf("command not in path \n");
			continue;
		}

		if (fork() == 0)
			execvp(command, args);
		else
			wait(NULL);
	}

	return (0);
}

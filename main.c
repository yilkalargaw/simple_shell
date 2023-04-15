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

	while (1)
	{
		printf("%s", ps); /* displays prompt */
		getline(&buffer, &bufsize, stdin); /* input */

		command = strtok(buffer, " \n"); /* tokenize */

		if (command == NULL) /* nocommand */
			continue;

		args[0] = command;

		for (i = 1; i < MAX_LENGTH; i++) /* parse other tokens aka arguments */
		{
			args[i] = strtok(NULL, " \n");

			if (args[i] == NULL)
				break;
		}

		if (fork() == 0)
			execvp(command, args);
		else
			wait(NULL);
	}

	return (0);
}

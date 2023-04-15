#include "shell.h"

int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	char *ps = "hsh-v01 > "; /*prompt string*/
	char *command;
	char *args[MAX_LENGTH];

	while (1)
	{
		printf("%s", ps); /* displays prompt */
		getline(&buffer, &bufsize, stdin); /* input */

		command = strtok(buffer, " \n");

		if (command == NULL)
			continue;

		args[0] = command;
		args[1] = NULL;

		if (fork() == 0)
			execvp(command, args);
		else
			wait(NULL);
	}

	return (0);
}

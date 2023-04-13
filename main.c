#include <stdio.h>
/* #include <stdlib.h> */

/**
 * main - the main exec loop for the shell
 * argc: argument count
 * argv: argument vector
 *
 * Return: status code
 */
int main(int argc, char *argv[])
{
	char *buffer = NULL;
	size_t bufsize = 0;
	char *ps = "hsh-v01 > ";

	argc = argc;
	argv[0] = argv[0];

	while (1)
	{
		printf("%s", ps);
		getline(&buffer, &bufsize, stdin);
	}

	return (0);
}

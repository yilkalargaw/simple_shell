#include "shell.h"
/**
 * *_strcpy - good old strcpy
 * @dest: destination
 * @src: source
 * Return: destination pointer
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != 0; i++)
		dest[i] = src[i];
	dest[i] = 0;

	return (dest);
}

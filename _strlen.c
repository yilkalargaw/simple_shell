#include "shell.h"

/**
 *_strlen - funct that returns length of a string
 * @s: pointer to the first char of string
 *
 *Return: length
 */
size_t _strlen(const char *s)
{
	size_t len = 0;

	while (*s++ != 0)
		len++;

	return (len);
}

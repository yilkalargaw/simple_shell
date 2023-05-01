#include "shell.h"

/**
 * _memcpy - copy memory form source to destination
 * @dest: destination pointer
 * @src: src pointer
 * @n: no. of bytes
 *
 * Return: pointer to output string
 */

char *_memcpy(char *dest, const char *src, unsigned int n)

{
	unsigned int i = 0;

	for (; i < n; ++i)
		dest[i] = src[i];

	return (dest);
}

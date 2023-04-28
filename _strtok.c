#include "shell.h"

/**
 * strspn - find length of the initial segment of a string that contains
 * characters from a specified set
 *
 * @s: string to search
 * @accept: allowed characters
 *
 * Return: length of the initial segment of a string
 */
size_t _strspn(const char *s, const char *accept)
{
	size_t i = 0, j = 0;

	for (; s[i]; i++)
	{
		j = 0;

		while (accept[j])
		{
			if (s[i] == accept[j])
				break;
			j++;
		}
		if (!accept[j])
			break;
	}
	return (i);
}
/**
 * strcspn - find length of the initial segment of a string that contains
 * characters not in a specified set
 *
 * @s: string to search
 * @reject: disallowed character string
 *
 * Return: length of the initial segment of a string
 */
size_t _strcspn(const char *s, const char *reject)
{
	size_t i = 0, j = 0;

	for (; s[i]; i++)
	{
		j = 0;

		while (reject[j])
		{
			if (s[i] == reject[j])
				return i;
			j++;
		}
	}
	return (i);
}


#include "shell.h"

/**
 * _strspn - find length of the initial segment of a string that contains
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
 * _strcspn - find length of the initial segment of a string that contains
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
				return (i);
			j++;
		}
	}
	return (i);
}

/**
 * _strtok - tokenize a string based on delimiter
 * @s: string to search
 * @delim: delimiter string
 *
 * Return: pointer to the first occurrence of the
 * delimiter string delim in the string s,
 * or NULL if the character is not found
 */

char *_strtok(char *s, const char *delim)
{
	static char *x;

	if (!s)
		return (NULL);
	s = x;
	if (!s)
		return (NULL);

	s += _strspn(s, delim);

	if (!*s)
		return (x = 0);

	x = s + _strcspn(s, delim);

	if (*x)
		*x++ = 0;
	else
		x = 0;

	return (s);
}

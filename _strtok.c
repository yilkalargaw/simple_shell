#include "shell.h"
/**
 * _strchr - locate character in string
 * @s: string to search
 * @c: character to locate
 *
 * Return: pointer to the first occurrence of the character c in the string s,
 * or NULL if the character is not found
 */
char *_strchr(const char *s, int c)
{
	while (*s != (char)c)
		if (!*s++)
			return (NULL);
	return ((char *)s);
}

/**
 * _strtok - A function that breaks a string into a sequence of zero or more nonempty tokens.
 * @str: The string to be parsed.
 * @delim: The delimiter characters.
 *
 * Return: A pointer to the next token, or NULL if there are no more tokens.
 */
char *_strtok(char *str, const char *delim)
{
	static char *last = NULL;
	char *token;

	if (str != NULL)
		last = str;

	if (last == NULL)
		return (NULL);

	token = last;

	while (*last != '\0') {
		if (strchr(delim, *last) != NULL)
		{
			*last++ = '\0';

			if (*token != '\0')
				return (token);
			else
				token = last;
		}
		else
			last++;
	}

	last = NULL;

	return (*token != '\0') ? (token) : (NULL);
}

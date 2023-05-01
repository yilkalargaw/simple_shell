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

#include "shell.h"

/**
 * _strdup - returns a pointer to allocated space
 * @str: the string to duplicate
 *
 * Return: a pointer to the duplicated string
 */
char *_strdup(char *str)
{
	char *dup;
	int i, len;

	if (str == NULL) /* check if str is NULL */
		return (NULL);

	len = 0;
	while (str[len]) /* get the length of str */
		len++;

	dup = malloc(sizeof(char) * (len + 1)); /* allocate memory for dup */
	if (dup == NULL) /* check if malloc failed */
		return (NULL);

	i = 0;

	for (; i < len; i++) /* copy str to dup */
		dup[i] = str[i];
	dup[len] = 0; /* add null terminator */

	return (dup); /* return the pointer to dup */
}

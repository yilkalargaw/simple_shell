#include "shell.h"

/**
 * _getenv - gets the value of an environment variable
 * @name: name of the environment variable
 *
 * Return: value of the environment variable, or NULL if it does not exist
 */
char *_getenv(const char *name)
{
	char **env;
	size_t len = _strlen(name);

	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(*env, name, len) == 0 && (*env)[len] == '=')
			return (&(*env)[len + 1]);
	}

	return (NULL);
}

/**
 * _putenv - sets an environment variable
 * @string: string to set as environment variable
 *
 * Return: 0 on success, -1 on failure
 */
int _putenv(char *string)
{
	char **ep;
	char *name = _strdup(string);
	char *old_value;

	if (!name)
		return (-1);

	for (ep = environ; *ep; ep++)
	{
		if (_strncmp(*ep, name, _strlen(name)) == 0 && (*ep)[_strlen(name)] == '=')
		{
			old_value = *ep;
			*ep = name;
			free(old_value);
			return (0);
		}
	}

	*ep = name;
	*(++ep) = NULL;

	FREE_MEM(name);
	return (0);
}

/**
 * _setenv - set an environment variable
 * @envtvar: name of environment variable
 * @value: value of environment variable
 * @overwrite: should varible be overwritten if it exists
 *
 * Return: status
 */
int _setenv(const char *envtvar, const char *value, int overwrite)
{
	size_t size;
	char *str;
	int i, j;
	int result;

	if (envtvar == NULL || envtvar[0] == '\0' || _strchr(envtvar, '=') != NULL)
		return (-1);

	size = _strlen(envtvar) + _strlen(value) + 2;
	str = malloc(size);

	if (str == NULL)
		return (-1);

	for (i = 0; i < (int)_strlen(envtvar); i++)
		str[i] = envtvar[i];

	str[i++] = '=';

	for (j = 0; j < (int)_strlen(value); j++)
		str[i + j] = value[j];

	str[i + j] = '\0';

	if (overwrite == 0)
		result = _setenv(envtvar, value, overwrite);
	else
		result = _putenv(str);

	FREE_MEM(str);

	return (result);
}

/**
 * _unsetenv - remove an environment variable
 * @envtvar: name of environment variable
 *
 * Return: status
 */
int _unsetenv(const char *envtvar)
{
	char **ep = environ;
	size_t len = _strlen(envtvar);
	char **dp;

	for (; *ep != NULL; ++ep)
	{
		if (_strncmp(*ep, envtvar, len) == 0 && (*ep)[len] == '=')
		{
			dp = ep;

			do
				dp[0] = dp[1];
			while (*dp++);
		}
	}
	return (0);
}

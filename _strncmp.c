#include "shell.h"

/**
 * _strncmp - funct that compare string values of given length n
 * @str1: string 1
 * @str2: string 2
 * @n: length char count
 *
 * Return: s1[i] - s2[i]
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i = 0;

	for (; i < n; i++)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	}
	return (0);
}

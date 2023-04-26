#include "shell.h"
/**
 * print_out - print string using write function
 * @str: input string
 *
 * Return: void
 */
void print_out(char *str)
{
	write(STDOUT_FILENO, str, strlen(str));
}

/**
 * print_out_many - print string using write function
 * @count: number of strings to print
 *
 * Return: void
 */
void print_out_many(int count, ...)
{
	va_list args;
	int i = 0;

	va_start(args, count);

	for (; i < count; i++)
	{
		char *str = va_arg(args, char *);

		write(STDOUT_FILENO, str, strlen(str));
	}
	va_end(args);
}


/**
 * print_error - print string using write function
 * @str: input string
 *
 * Return: void
 */
void print_error(char *str)
{
	write(STDERR_FILENO, str, strlen(str));
}

/**
 * print_error_many - print string using write function
 * @count: number of strings to print
 *
 * Return: void
 */
void print_error_many(int count, ...)
{
	va_list args;
	int i = 0;

	va_start(args, count);

	for (; i < count; i++)
	{
		char *str = va_arg(args, char *);

		write(STDERR_FILENO, str, strlen(str));
	}
	va_end(args);
}

#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdarg.h>

#define MAX_LENGTH 2048
#define MAX_LINE 2048

extern char **environ;

size_t _strlen(const char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strdup(char *str);
char *_strchr(const char *str, int ch);
char *_strtok(char *str, const char *delim);
char *_getenv(const char *name);
int checkpath(char *command);
void print_out(char *str);
void print_out_many(int count, ...);
void print_error(char *str);
void print_error_many(int count, ...);
void print_int_stderr(int num);
/* int process_builtins(char *command, char *args[MAX_LENGTH], int count); */
int process_builtins(char *command, char *args[MAX_LENGTH], int count, char* argv0);
size_t _strspn(const char *s, const char *accept);
size_t _strcspn(const char *s, const char *reject);

#define PRINT_IF_TERMINAL(prpt) \
	do { \
		if (isatty(STDIN_FILENO)) \
		{ \
			print_out(prpt); \
		} \
	} while (0)

#define PRINT_ERROR_ATTY(cnt) \
	do { \
		if (isatty(STDIN_FILENO)) \
		{ \
			print_error_many(2, argv[0], ": "); \
			print_int_stderr(cnt); \
			print_error_many(3, ": ", command, ": not found \n"); \
		} else \
		{ \
			print_error_many(2, argv[0], ": "); \
			print_int_stderr(cnt); \
			print_error_many(3, ": ", command, ": not found \n"); \
		} \
	} while (0)

#define PARSE_ARGUMENTS() \
	do { \
		args[0] = command; \
		for (i = 1; i < MAX_LENGTH; i++) \
		{ \
			args[i] = _strtok(NULL, " \n"); \
			if (args[i] == NULL) \
				break; \
		} \
	} while (0)

#define FREE_MEM(ptr) \
	do {\
		if (ptr != NULL) \
		{ \
			free(ptr); \
			ptr = NULL; \
		} \
	} while (0)

#define FREE_MEM2(ptr1, ptr2) \
	do { \
		free(ptr1); \
		ptr1 = NULL; \
		free(ptr2); \
		ptr2 = NULL; \
	} while (0)

#define MANAGE_FORKING(depid) \
	do { \
		pid = fork(); \
		if (depid == 0) \
		{ \
			execvp(command, args); \
			exit(1); \
		} \
		else if (depid > 0) \
		{ \
			waitpid(depid, &status, 0); \
			if (WIFEXITED(status)) \
				status = WEXITSTATUS(status); \
		} \
		else \
		{ \
			printf("Fork failed\n"); \
			exit(1); \
		} \
	} while (0)

#define EXIT_IF_COMMAND_IS_EXIT() \
	do { \
		if (_strcmp(command, "exit") == 0) \
		{ \
			FREE_MEM(buffer); \
			exit(status); \
			break; \
		} \
	} while (0)

#endif

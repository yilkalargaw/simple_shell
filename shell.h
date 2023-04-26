#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdarg.h>

#define MAX_LENGTH 1024
#define MAX_LINE 1024

extern char **environ;

size_t _strlen(const char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strdup(char *str);
char *_strchr(const char *str, int ch);
char *_getenv(const char *name);
int checkpath(char *command);
void print_out(char *str);
void print_out_many(int count, ...);
void print_error(char *str);
void print_error(char *str);

#define PRINT_IF_TERMINAL(prpt) \
	do { \
		if (isatty(STDIN_FILENO)) \
		{ \
			print_out(prpt); \
		} \
	} while (0)

#define PROCESS_BUILTINS() \
	do { \
		if (_strcmp(command, "env") == 0) \
		{ \
			for (; *env_var != NULL; env_var++) \
				print_out_many(2, *env_var, "\n"); \
			env_var = environ; \
			continue; \
		} \
		if (_strcmp(command, "cd") == 0) \
		{ \
			if (args[1] == NULL) \
				chdir(_getenv("HOME")); \
			else if (chdir(args[1]) == -1) \
			{ \
				print_error("chdir failed"); \
				continue; \
			} \
		} \
	} while (0)

/* #define CHECK_COMMAND_PATH() \ */
/*	do { \ */
/*		if (checkpath(command) == 0) \ */
/*		{ \ */
/*			print_error("command not in path \n"); \ */
/*			continue; \ */
/*		} \ */
/*	} while (0) */

#define PARSE_ARGUMENTS() \
	do { \
		args[0] = command; \
		for (i = 1; i < MAX_LENGTH; i++) \
		{ \
			args[i] = strtok(NULL, " \n"); \
			if (args[i] == NULL) \
				break; \
		} \
	} while (0)

#define FREE_MEM(ptr) \
	do {\
		if(ptr != NULL) { \
			free(ptr); \
			ptr = NULL; \
		} \
	} while (0)

/* #define FREE_MEM2(ptr1, ptr2)							\ */
/* 	do {\ */
/* 		free(ptr1); \ */
/* 		ptr1 = NULL; \ */
/* 		free(ptr2); \ */
/* 		ptr2 = NULL; \ */
/* 	} while (0) */

#endif

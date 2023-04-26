#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdarg.h>

#define MAX_LENGTH 1024
#define MAX_LINE 80

extern char **environ;

size_t _strlen(const char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strdup(char *str);
char *_getenv(const char *name);
int checkpath(char *command);
void print_out(char *str);
void print_out_many(int count, ...);
void print_error(char *str);
void print_error(char *str);

#endif

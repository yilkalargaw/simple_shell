#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LENGTH 1024
#define MAX_LINE 80

extern char **environ;

int _strcmp(char *s1, char *s2);
char *_getenv(const char *name);
int checkpath(char *command);

#endif

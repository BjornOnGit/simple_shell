#ifndef MAIN_H
#define MAIN_H

/* Libraries */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "str.h"

/* global environ variable */
extern char **environ;

/* Function Prototypes */
void exec_cmd(const char *filename, char **args);
void shell_interactive(const char *filename);
void shell_non_interactive(const char *filename);
ssize_t _getline(char **lineptr, size_t *n, int fd);
size_t readline(char *line, size_t *n, int fd);

void print_err(char *str, ...);
int _putchar(char c);
void print_string(char *s);
void print_unsigned_number(unsigned int n);
char *handle_path(char *cmd);
char *_getenv(const char *name);

#endif

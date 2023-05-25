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
#include <string.h>
#include <errno.h>
#include "str.h"

/**
 * struct built_in - data structure to handle builtin cmd
 * @name: name of command
 * @func: function pointer to appropriate function
 */
typedef struct built_in
{
	char *name;
	void (*func)(char **args);
} builtin;

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
<<<<<<< HEAD
char *handle_path(char *cmd);
char *_getenv(const char *name);
int check_builtin(char **args);
void handle_exit(char **argv);
void handle_clear(char **argv);
void handle_env(char **argv);
=======
>>>>>>> cc092655ba1707bb738a6f0cef9ada403dd5c502

#endif

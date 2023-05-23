#ifndef MAIN_H
#define MAIN_H

/* Libraties */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/wait.h>
#include "str.h"

/* Function Prototypes */
void exec_cmd(const char *filename, char **args);
void shell_interactive(const char *filename);
void shell_non_interactive(const char *filename);
ssize_t _getline(char **lineptr, size_t *n, int fd);

void print_err(char *str, ...);
int _putchar(char c);
void print_string(char *s);
void print_unsigned_number(unsigned int n);

#endif

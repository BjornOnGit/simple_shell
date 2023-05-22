#ifndef MAIN_H
#define MAIN_H

/* Libraties */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "str.h"

/* Function Prototypes */
void exec_cmd(const char *filename, char **args);
void shell_interactive(const char *filename);
ssize_t _getline(char **lineptr, size_t *n, int fd);

#endif

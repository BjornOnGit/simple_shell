#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_TOKBUFSIZE 128
#define MAX_COMM_LENG 1024

/* function prototypes*/
void execmd(char **argv);

#endif /* SHELL_H */

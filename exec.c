#include "main.h"

/**
 * exec_cmd - execute command from input
 * @filename: the program name
 * @args: command arguments
 */
void exec_cmd(const char *filename, char **args)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
			perror(filename);
	}
	else
	{
		wait(NULL);
	}
}

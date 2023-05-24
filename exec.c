#include "main.h"

/**
 * exec_cmd - execute command from input
 * @filename: the program name
 * @args: command arguments
 */
void exec_cmd(const char *filename, char **args)
{
	static int n = 0;
	pid_t pid = fork();

	n++;

	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			print_err("%s: %d: %s: not found\n", filename, n, args[0]);
		}
	}
	else
	{
		wait(NULL);
	}
}

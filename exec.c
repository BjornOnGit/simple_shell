#include "main.h"

/**
 * exec_cmd - execute command from input
 * @file: the program name
 * @args: command arguments
 */
void exec_cmd(const char *file, char **args)
{
	static int n;
	char *cmd;
	int built_in;
	pid_t pid;

	n = 0;
	n++;

	if (args != NULL)
	{
		built_in = check_builtin(args);

		if (built_in == 0)
			return;
		cmd = handle_path(args[0]);

		if (cmd == NULL)
		{
			if (execve(args[0], args, NULL) == -1)
				print_err("%s: %d: %s: %s\n", file, n, args[0], strerror(errno));
		}
		else
		{
			pid = fork();

			if (pid == -1)
				return;
			if (pid == 0)
			{
				if (execve(cmd, args, NULL) == -1)
					print_err("%s: %d: %s: %s\n", file, n, cmd, strerror(errno));
			}
			else
			{
				wait(NULL);
				return;
			}
		}
	}
}

/**
 * check_builtin - check if argument is a builtin arg
 * @args: argument
 *
 * Return: -1 if builtin or 0 if not
 */
int check_builtin(char **args)
{
	int i, builtins_len;

	builtin builtins[] = {
		{"exit", handle_exit},
		{"clear", handle_clear},
		{"env", handle_env}
	};

	builtins_len = sizeof(builtins) / sizeof(builtin);

	for (i = 0; i < builtins_len; i++)
	{
		if (_strcmp(args[0], builtins[i].name) == 0)
		{
			builtins[i].func(args);
			return (0);
		}
	}

	return (-1);
}

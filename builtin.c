#include "main.h"

/**
 * handle_exit - exits the shell
 * @argv: the argument
 */
void handle_exit(char **argv)
{
	if (argv != NULL)
	{
		free(*argv);
		exit(0);
	}
}

/**
 * handle_clear - clear console
 * @argv: arguments
 */
void handle_clear(char **argv)
{
	if (argv != NULL)
	{
		free(*argv);
		system("clear");
	}
}

void handle_env(char **argv)
{
	int i;

	if (argv)
	{
		if (argv[1] != NULL)
			print_err("%s: '%s': %s", strerror(ENOENT));
		else
		{
			for (i = 0; environ[i]; i++)
			{
				print_string(environ[i]);
				_putchar('\n');
			}
		}
	}
}

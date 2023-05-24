#include "main.h"

/**
 * shell_interactive - shell in interactive mode
 * @filename: the program name
 *
 * Discription: reads input from terminal, tokenize the input
 * and pass it to the execve for execution
 */
void shell_interactive(const char *filename)
{
	char **args = NULL;
	char *buff = NULL, *buff_copy = NULL, *token = NULL, *delim = " \n";
	size_t n;
	int argc = 0, i;

	while (1)
	{
		_getline(&buff, &n, STDIN_FILENO);

		buff_copy = _strdup(buff);

		token = _strtok(buff_copy, delim);

		while (token)
		{
			argc++;
			token = _strtok(NULL, delim);
		}
		argc++;

		token = _strtok(buff, delim);
		args = malloc(sizeof(char *) * argc);

		i = 0;

		while (token)
		{
			args[i++] = token;
			token = _strtok(NULL, delim);
		}
		args[i + 1] = NULL;
		exec_cmd(filename, args);

		free(args);
		free(buff_copy);
	}

	free(buff);
}

/**
 * shell_non_interactive - shell in non-interactive mode
 * @filename: program name
 */
void shell_non_interactive(const char *filename)
{
	char *buff = NULL, *buff_copy = NULL, *token = NULL, *delim = " \n";
	char **args = NULL;
	size_t n = 0;
	int i, argc = 0;

	while (_getline(&buff, &n, STDIN_FILENO) != -1)
	{
		buff_copy = _strdup(buff);
		token = _strtok(buff_copy, delim);

		while (token)
		{
			argc++;
			token = _strtok(NULL, delim);
		}
		argc++;

		token = _strtok(buff, delim);
		args = malloc(sizeof(char *) * argc);

		i = 0;
		while (token)
		{
			args[i++] = token;
			token = _strtok(NULL, delim);
		}
		args[i + 1] = NULL;

		exec_cmd(filename, args);

		free(args);
		free(buff_copy);
	}
	free(buff);
}

#include "main.h"

/**
 * handle_path - search path for the command
 * @cmd: the command to find
 *
 * Return: the full path or NULL
 */
char *handle_path(char *cmd)
{
	char *path, *path_copy, *file_path, *token, *delim = ":";
	int cmd_len, path_len;
	struct stat buff;

	cmd_len = _strlen(cmd);
	path = _getenv("PATH");

	if (path)
	{
		path_copy = _strdup(path);
		token = _strtok(path_copy, delim);

		while (token)
		{
			path_len = _strlen(token);
			file_path = malloc(cmd_len + path_len + 2);
			_strcpy(file_path, token);
			_strcat(file_path, "/");
			_strcat(file_path, cmd);
			_strcat(file_path, "\0");

			if (stat(file_path, &buff) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				token = _strtok(NULL, delim);
			}
		}
		free(path_copy);
		if (stat(cmd, &buff) == 0)
			return (cmd);
		return (NULL);
	}
	return (NULL);
}

#include <stdlib.h>
#include "main.h"

/**
 * _setenv - A function that sets an environment variable
 * @name: a string representing the environment variable.
 * @value: a string representing the value to be assigned
 * to the enviroment variable.
 * @overwrite: an integer flag to overwrite the environment variable,
 * if the variable already exists.
 * Return: 0 if successful and any other number if it fails.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	if (name == NULL || value == NULL)
	{
		return (1);
	}
	size_t name_length = _strlen(name);
	size_t value_length = _strlen(value);
	size_t str_length = name_length + value_length + 2;

	char  *temp_str = (char *)malloc(str_length);

	if (temp_str == NULL)
	{
		return (1);
	}

	snprintf(temp_str, str_length, "%s=%s", name, value);

	char **current = __environ;
	int index = 0;

	while (*current != NULL)
	{
		if (_strcmp(*current, name) == 0 && (*current)[name_length] == '=')
		{
			if (overwrite == 0)
			{
				free(temp_str);
				return (0);
			}
			else
			{
				free(*current);
				__environ[index] = _strdup(temp_str);
				free(temp_str);
				return (0);
			}
		}
		current++;
		index++;
	}
	int num_entries = 0;

	while (__environ[num_entries] != NULL)
	{
		num_entries++;
	}

	char **new_environ = realloc(__environ, (num_entries + 2) * sizeof(char *));

	if (new_environ == NULL)
	{
		free(temp_str);
		return (1);
	}
	__environ = new_environ;
	__environ[num_entries] = _strdup(temp_str);
	__environ[num_entries + 1] = NULL;

	free(temp_str);
	return (0);
}

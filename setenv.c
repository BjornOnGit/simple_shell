#include <stdlib.h>
#include "main.h"

/**
 * _setenv - A function that sets an environment variable
 * @name: a string representing the environment variable.
 * @value: a string representing the value to be assigned
 * to the enviroment variable.
 * @overwrite: an integer flag to overwrite the environment variable,
 * if the variable already exists.
 * Return: 0 if success any other number if it fails.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	char *env_var;

	if (name != NULL || value != NULL)
	{
		env_var = getenv(name);
		if (env_var != NULL && overwrite == 0)
		{
			return (0);
		}
		size_t str_length;

		str_length = _strlen(name) + 1 + _strlen(value) + 1;
		char *temp_str;

		temp_str = (char *)malloc(str_length);
		if (temp_str == NULL)
		{
			return (1);
		}
		snprintf(temp_str, str_length, "%s=%s", name, value);
		int existing_index = -1;
		char **current = __environ;
		int index = 0;

		while (*current != NULL)
		{
			if (_strcmp(*current, name, _strlen(name)) == 0 && (*current)[_strlen(name)] == ' = ')
			{
				existing_index = index;
				break;
			}
			current++;
			index++;
		}
		if (existing_index >= 0)
		{
			free(__environ[existing_index]);
			__environ[existing_index] = _strdup(temp_str);
		}
		else
		{
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
		}
		free(temp_str);
		return (0);
	}
	else
	{
		return (1);
	}
}

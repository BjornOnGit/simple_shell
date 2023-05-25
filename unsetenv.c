#include <stdlib.h>
#include "main.h"

/**
 * _unsetenv - function that removes
 * an environment variable
 * @name: a string representing the enviroment
 * variable.
 * Return: 0 if successful and any other number if it fails.
 */
int _unsetenv(const char *name)
{
	if (name == NULL)
	{
		return (1);
	}
	int existing_index = -1;
	char **current = __environ;

	while (*current != NULL)
	{
		if (_strcmp(*current, name) == 0 && (*current)[strlen(name)] == ' = ')
		{
			existing_index = current - __environ;
			break;
		}
		current++;
	}
	if (existing_index >= 0)
	{
		free(__environ[existing_index]);
	}
	for (int i = existing_index; __environ[i] != NULL; i++)
	{
		__environ = __environ[i + 1];
	}
	return (0);
}

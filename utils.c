#include "main.h"

/**
 * _getline - read line from stdin
 * @lineptr: a pointer to the address wher the string will be stored
 * @n: number of byte to read
 * @fd: file descriptor
 *
 * Return: number of byte read or -1
 */
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	size_t r = 0, total_read = 0;
	char *pos;

	if (*lineptr == NULL || *n <= 0)
	{
		*n = 120;
		(*lineptr) = malloc(sizeof(char) * (*n));
		if ((*lineptr) == NULL)
			return (-1);
	}

	pos = *lineptr;

	while (1)
	{
		if (total_read >= *n)
		{
			*n *= 2;
			(*lineptr) = realloc(*lineptr, *n);
			if ((*lineptr) == NULL)
				return (-1);
		}
		r = read(fd, pos, 1);
		if (r == 0)
			break;
		else if (r == (size_t)-1)
		{
			free(*lineptr);
			return (-1);
		}
		else
		{
			total_read += r;
			if (*pos == '\n')
				break;
			pos += r;
		}
	}
	*(pos + 1) = '\0';
	return (total_read > 0 ? total_read : (size_t)-1);
}

/**
 * _getenv - get an environment variable
 * @name: name of the variable
 *
 * Return: the value of `name` or NULL
 */
char *_getenv(const char *name)
{
	extern char **environ;
	char *n = NULL, *dup = NULL;
	int i = 0;

	if (name == NULL)
		return (NULL);

	while (environ[i])
	{
		dup = _strdup(environ[i]);
		
		n = _strtok(dup, "=");

		if (_strcmp(name, n) == 0)
		{
			n = _strtok(NULL, "=");
			return (n);
		}
		i++;
	}

	free(dup);

	return (NULL);
}

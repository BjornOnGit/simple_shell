#include "main.h"

size_t readline(char *line, size_t *n, int fd)
{
	size_t r = 0, total = 0;
	char *pos = line;

	while (1)
	{
		if (total >= *n)
		{
			*n *= 2;
			line = realloc(line, *n);

			if (line == NULL)
			{
				free(line);
				return (-1);
			}
		}
		r = read(fd, pos, 1);

		if (r == 0)
		{
			return (-1);
		}
		else if (r == (size_t)-1)
		{
			free(line);
			return (-1);
		}
		else
		{
			total += r;
			if (*pos == '\n')
				break;
			pos += r;
		}
	}
	*(pos + 1) = '\0';

	return (total > 0 ? total : (size_t)-1);
}

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
	size_t total_read = 0;

	if (*lineptr == NULL || *n <= 0)
	{
		*n = 120;
		(*lineptr) = malloc(sizeof(char) * (*n));
		if ((*lineptr) == NULL)
			return (-1);
	}

	total_read = readline(*lineptr, n, fd);

	return (total_read);
}

/**
 * _getenv - get an environment variable
 * @name: name of the variable
 *
 * Return: the value of `name` or NULL
 */
char *_getenv(const char *name)
{
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

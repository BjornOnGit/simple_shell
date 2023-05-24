#include "main.h"

/**
  * _strcmp - compares two strings
  * @s1: first string
  * @s2: second string
  * Return: 0 if s1 and s2 are equals,
  * another number if not.
  */
int _strcmp(const char *s1, const char *s2)
{
	int i = 0, op = 0;

	while (op == 0)
	{
		if ((*(s1 + i) == '\0') && (*(s2 + i) == '\0'))
		{
			break;
		}
		op = *(s1 + i) - *(s2 + i);
		i++;
	}

	return (op);
}

/**
 * _strtok - seperate string into tokens
 * @str: the strig to tokenize
 * @delim: the seperating charscter
 *
 * Return: the next string or NULL
 */
char *_strtok(char *str, const char *delim)
{
	static char *next;
	char *token = NULL;

	if (str != NULL)
		next = str;

	if (next == NULL)
		return (NULL);

	token = next;

	while (*next != '\0')
	{
		const char *d = delim;

		while (*d != '\0')
		{
			if (*d == *next)
			{
				*next = '\0';
				next++;

				if (*token == '\0')
				{
					token++;
					continue;
				}

				return (token);
			}
			d++;
		}
		next++;
	}

	next = NULL;

	return (*token != '\0' ? token : NULL);
}

/**
 * _strdup - create a copy of a string
 * @s: the string to copy
 *
 * Return: the duplicate string or NULL
 */
char *_strdup(const char *s)
{
	int i;
	int len = _strlen(s);
	char *dup = malloc(sizeof(char) * len + 1);

	if (dup == NULL)
		return (NULL);

	for (i = 0; s[i] != '\0'; i++)
		dup[i] = s[i];

	dup[len + 1] = '\0';

	return (dup);
}

/**
 * _strlen - calculates the length of a string
 * @s: the string
 *
 * Return: the string lenght
 */
size_t _strlen(const char *s)
{
	size_t len = 0, count = 0;

	while (s[count++])
		len++;

	return (len);
}

/**
 * _strcat - concatenate tow strings
 * @dest: the first string
 * @src: the second string to concatenate
 *
 * Return: A pointer to the resulting string dest
 */
char *_strcat(char *dest, const char *src)
{
	size_t dest_len = _strlen(dest);
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[dest_len + i] = src[i];
	}
	dest[dest_len + i] = '\0';

	return (dest);
}

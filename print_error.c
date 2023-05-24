#include "main.h"

/**
 * _putchar - write to stderr
 * @c: the character to write
 *
 * Return: Number of byte written or -1
 */
int _putchar(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}

/**
 * print_err - print error to stderr
 * @str: a strint to be printed
 *
 * Discription: This function have a variable number
 * of argument
 */
void print_err(char *str, ...)
{
	int i;
	va_list args;

	va_start(args, str);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (i != 0 && str[i - 1] == '%')
			continue;
		if (str[i] == '%')
		{
			if (str[i + 1] == 's')
			{
				char *s = va_arg(args, char *);

				print_string(s);
				continue;
			}
			else if (str[i + 1] == 'd')
			{
				size_t n = va_arg(args, size_t);

				print_unsigned_number(n);
				continue;
			}
		}
		_putchar(str[i]);
	}

	va_end(args);
}

/**
 * print_string - print a list of characters
 * @s: the string
 *
 * Return: Nothing
 */
void print_string(char *s)
{
	int i;

	if (s == NULL)
		return;

	for (i = 0; s[i] != '\0'; i++)
		_putchar(s[i]);
}

/**
 * print_unsigned_number - print an unsigned int
 * @n: the number
 *
 * Return: Nothing
 */
void print_unsigned_number(unsigned int n)
{
	int div;
	unsigned int num;

	div = 1;
	num = n;

	for (; num / div > 9;)
		div *= 10;
	for (; div != 0;)
	{
		_putchar('0' + num / div);
		num %= div;
		div /= 10;
	}
}

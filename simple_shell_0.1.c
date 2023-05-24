#include "main.h"

/**
  * main - The entry point of the program
  * @argc: parameter of type int .
  * @argv: parameter of type char const *.
  * Return: 0
 */
int main(int argc, char const *argv[])
{
	if (argc > 0)
	{
		if (isatty(STDIN_FILENO))
			shell_interactive(argv[0]);
		else
			shell_non_interactive(argv[0]);
	}
	return (0);
}

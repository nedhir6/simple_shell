#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "shell.h"

/**
 * input_shell - function that takes input from user
 * @string: the command line
 * Return: number of charater read or exit with 1 status
 */
ssize_t input_shell(char **string)
{
	/*size_t nbRd = 0;*/
	ssize_t n = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	/*n = getline(string, &nbRd, stdin);*/
	n = _getline(string);
	if (n == -1)
	{
		if (isatty(STDIN_FILENO))
			NEWLINE;
		free(*string);
		exit(EXIT_SUCCESS);
	}
	/*ELIMINATE_NEWLINE(*string, n);*/
	eliminate_NewLine(*string, n);

	return (n);
}

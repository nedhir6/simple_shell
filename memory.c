#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shell.h"

/**
 * input_shell - function that takes input from user
 * @string: the command line
 * Return: number of charater read or exit with 1 status
 */
ssize_t input_shell(char **string)
{
	size_t nbRd = 0;
	ssize_t n = 0;


	printf("#cisfun$ ");
	n = getline(string, &nbRd, stdin);

	if (n == -1)
	{
		NEWLINE;
		free(*string);
		exit(EXIT_SUCCESS);
	}
	/*ELIMINATE_NEWLINE(*string, n);*/
	eliminate_NewLine(*string, n);

	return (n);
}

/**
 * eliminate_NewLine - replace commandLine '\n' with '\0'
 * @string: commandLine
 * @n: length  of string
 */
void eliminate_NewLine(char *string, int n)
{
	string[n - 1] = '\0';
}

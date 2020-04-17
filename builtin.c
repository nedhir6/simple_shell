#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "shell.h"

/**
*builtin - builtin
*@commandLine: commandLine
*Return: status
*/
int builtin(char **commandLine)
{
	builtin_t built[] = {
		{"exit", exit_builtin},
		{"env", env_builtin},
		{NULL, NULL}
	};
	int status = -1, i = 0;
	int (*builtin_fn)(char *) = NULL;

	for (i = 0 ; built[i].command ; i++)
	{
		if (!_strcmp(built[i].command, commandLine[0]))
		{
			builtin_fn = built[i].function;
			break;
		}
	}

	if (builtin_fn)
		status = builtin_fn(commandLine[1]);

	return (status);
}

/**
*exit_builtin - exit builtin
*@commandArg: status exit
*Return: status
*/
int exit_builtin(char *commandArg)
{
	int status = 0;

	if (commandArg)
		status = _atoi(commandArg);

	if (status < 0)
		status = 2;
	return (status);
}
/**
 * env_builtin - display all environment variables
 * @commandArg: unused
 * Return: -2
 */
int env_builtin(char *commandArg __attribute__((__unused__)))
{
	int i = 0;

	for (i = 0 ; environ[i] ; i++)
		_puts(environ[i]);

	return (-2);
}

/**
* _atoi - convert string to integer
* @s: string to convert
* Return: the integer
*/
int _atoi(char *s)
{
	unsigned int number = 0;
	int i = 0, sign = 1;

	while (s[i] != '\0' && !(s[i] >= '0' && s[i] <= '9'))
	{
		if (s[i] == '-')
			sign *= -1;

		i++;
	}

	if (s[i] == '\0')
		number = 0;

	while (s[i] != '\0' && (s[i] >= '0' && s[i] <= '9'))
	{
		if (s[i] >= '0' && s[i] <= '9')
			number = (number * 10) + (s[i] - '0');

		i++;
	}

	number *= sign;

	return (number);
}

/**
* _strcmp - compare two strings
* @s1: first string
* @s2: second string
* Return: 0 if s1 = s2
*/
int _strcmp(char *s1, char *s2)
{
	int i = 0, cmp = 0;

	while (s1[i] != '\0' || s2[i] != '\0')
	{
		cmp = s1[i] - s2[i];
		if (cmp)
			break;

		i++;
	}

	return (cmp);
}

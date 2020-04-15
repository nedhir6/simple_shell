#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#include "shell.h"

/**
 * main - simple shell project
 * Return: always 0
 */
int main(void)
{
	char **arg;
	char *commandLine = NULL;
	int size = 0;
	bool running = TRUE;
	int status = -1;
	pid_t pid;

	while (running)
	{
		if (signal(SIGINT, set_signal) == SIG_ERR)
			exitWithError("signal ", 1);
		input_shell(&commandLine);
		arg = strToArray(commandLine);
		size = get_NumberOfWords(commandLine);
		RESET(commandLine);

		status = builtin(arg);
		if (status != -1)
			running = FALSE;

		else
		{
		pid = createProcess();
			switch (pid)
			{
				case 0:

					childProcess(arg, size);
					break;

				default:

					fatherProcess();
					break;
			}
		}
		free_ArrayOfWords(arg, size);
	}

	return (status);
}

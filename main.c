#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

	pid_t pid;


	while (running)
	{
		input_shell(&commandLine);
		arg = strToArray(commandLine);
		size = get_NumberOfWords(commandLine);
		RESET(commandLine);

		pid = createProcess();

		switch (pid)
		{
			case 0:

				/*printf("child: %p\n", commandLine);*/
				childProcess(arg, size);
				break;

			default:
				/*printf("father: %p\n", commandLine);*/
				fatherProcess();
				break;
		}
		/*RESET(commandLine);*/
		free_ArrayOfWords(arg, size);
	}

	return (EXIT_SUCCESS);
}

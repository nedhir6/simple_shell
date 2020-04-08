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
	char *commandLine = NULL;
	/*int n = 0;*/
	bool running = TRUE;

	pid_t pid;


	while (running)
	{
		input_shell(&commandLine);
		pid = createProcess();

		switch (pid)
		{
			case 0:

				/*printf("child: %p\n", commandLine);*/
				childProcess(commandLine);
				break;

			default:
				/*printf("father: %p\n", commandLine);*/
				fatherProcess();
				break;
		}
		RESET(commandLine);
	}

	return (EXIT_SUCCESS);
}

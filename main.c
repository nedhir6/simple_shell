#include <stdio.h>
#include <stdlib.h>

#include "shell.h"


int main(void)
{
	char *commandLine = NULL;
	size_t n = 0;
	bool running = TRUE;

	pid_t pid;

	while (running)
	{
		pid = createProcess();

		switch (pid)
		{
			case 0:
				printf("#cisfun$ ");
				n = getline(&commandLine, &n, stdin);
				commandLine[n - 1] = '\0';
				/*printf("child: %p\n", commandLine);*/
				childProcess(commandLine);
				break;
			
			default:
				/*printf("father: %p\n", commandLine);*/
				fatherProcess();
				
				break;
		}

	}

	return (EXIT_SUCCESS);
}

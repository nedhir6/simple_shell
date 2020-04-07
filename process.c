#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include "shell.h"


pid_t createProcess(void)
{
	pid_t pid;

	do
	{
		pid = fork();
	}
	while (pid < 0);

	return (pid);
}

void fatherProcess(void)
{
	int status;
	if (wait(&status) == -1)
		exitWithError("wait ", 1);
}


void childProcess(char *commandLine)
{
	char *arg[2] = {NULL, NULL};

	arg[0] = commandLine;

	if (execve(arg[0], arg, NULL) == -1)
		exitWithError("execve ", 126);
}


void exitWithError(const char *log, int status)
{
	perror(log);
	exit(status);
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include "shell.h"

/**
 * createProcess - create new process
 * Return: pid of the new process
 */
pid_t createProcess(void)
{
	pid_t pid;

		pid = fork();

		if (pid == -1)
			exitWithError("fork ", 1);

	return (pid);
}

/**
 * fatherProcess - instructions executed by the father
 */
void fatherProcess(void)
{
	int status;

	if (wait(&status) == -1)
		exitWithError("wait ", 1);
}

/**
 * childProcess - instructions executed by the child
 * @commandLine: input
 */
void childProcess(char *commandLine)
{
	char *arg[2] = {NULL, NULL};

	arg[0] = commandLine;

	if (execve(arg[0], arg, NULL) == -1)
	{
		RESET(commandLine);
		exitWithError("execve ", 126);
	}
}

/**
 * exitWithError - call perror and exit with status
 * @log: error message
 * @status: exit status
 */
void exitWithError(const char *log, int status)
{
	perror(log);
	exit(status);
}

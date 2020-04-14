#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

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
 * @size: size of the array
 */
void childProcess(char **commandLine, int size)
{
	if (commandLine[0][0] == '\n')
	{
		free_ArrayOfWords(commandLine, size);
		exit(0);
	}
	if (execve(commandLine[0], commandLine, NULL) == -1)
	{
		free_ArrayOfWords(commandLine, size);
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

/**
 * set_signal - handle signal
 * @sig: signal
 */
void set_signal(int sig __attribute__((__unused__)))
{
	write(STDOUT_FILENO, "\n$ ", 3);
	if (fflush(stdin) == EOF)
		exitWithError("fflush ", 1);
}

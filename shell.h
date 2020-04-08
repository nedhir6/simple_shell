#ifndef __SHELL__
#define __SHELL__

/*---------------------STRUCT--&--ENUM---------------------*/

/**
 * enum bool - boolean type
 * @FALSE: 0
 * @TRUE: 1
 */
typedef enum bool
{
	FALSE,
	TRUE
} bool;

/*---------------------STRUCT--&--ENUM---------------------*/

#define RESET(__MEMORY__) {free(__MEMORY__); \
							__MEMORY__ = NULL; }

#define NEWLINE printf("\n")


pid_t createProcess(void);
void fatherProcess(void);
void childProcess(char *commandLine);

void exitWithError(const char *log, int status);

ssize_t input_shell(char **string);
void eliminate_NewLine(char *string, int n);

#endif

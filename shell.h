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



pid_t createProcess(void);
void fatherProcess(void);
void childProcess(char *commandLine);

void exitWithError(const char *log, int status);

#endif

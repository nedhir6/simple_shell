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

/**
 * struct builtin_t - built_in
 * @command: command line
 * @function: function
 */
typedef struct builtin_t
{
	char *command;
	int (*function)(char *commandArg);
} builtin_t;

/*---------------------STRUCT--&--ENUM---------------------*/

#define RESET(__MEMORY__) {free(__MEMORY__); \
							__MEMORY__ = NULL; }

#define NEWLINE write(STDOUT_FILENO, "\n", 1)

#define BUFFER_SIZE 1024

extern char **environ;


pid_t createProcess(void);
void fatherProcess(void);
void childProcess(char **commandLine, int size);
void set_signal(int sig __attribute__((__unused__)));

void exitWithError(const char *log, int status);

ssize_t input_shell(char **string);
void eliminate_NewLine(char *string, int n);
int get_NumberOfWords(char *str);
char *_memcpy(char *dest, char *src, unsigned int n);
char **strToArray(char *str);
void free_ArrayOfWords(char *arrayOfWords[], int size);

ssize_t _getline(char **buffer);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void set_memory(char *array, char *src, unsigned int new_size,
unsigned int old_size);

char *_strcpy(char *dest, char *src);
int builtin(char **commandLine);
int exit_builtin(char *commandArg);
int env_builtin(char *commandArg __attribute__((__unused__)));
int _atoi(char *s);
int _strcmp(char *s1, char *s2);
void _puts(char *str);
#endif


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "shell.h"


/**
 * eliminate_NewLine - replace commandLine '\n' with '\0'
 * @string: commandLine
 * @n: length  of string
 */
void eliminate_NewLine(char *string, int n)
{
	string[n - 1] = '\0';
}

/**
 * get_NumberOfWords - get number of words in string
 * @str: string
 * Return: number of words
 */
int get_NumberOfWords(char *str)
{
	int sizeArray = 0, i = 0;

	while (1)
	{
		while (str[i] == ' ' && str[i])
			i++;

		if (!str[i])
			return (0);

		sizeArray++;
		while (str[i] != ' ' && str[i])
			i++;

		if (!str[i])
			break;

	}
	return (sizeArray);

}

/**
 * _memcpy - copy memories area
 * @dest: destination
 * @src: source
 * @n: number of character
 * Return: dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	for (i = 0 ; i < n ; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}

/**
 * strToArray - convert a string to array of words
 * @str: string to convert
 * Return: array of words null terminated
 */
char **strToArray(char *str)
{
	char **arrayOfWords = NULL;
	int i = 0, j = 0, sizeStr = 0, sizeArray = 0, arrayIndex = 0;

	sizeArray = get_NumberOfWords(str);

	arrayOfWords = malloc((sizeof(char *) * sizeArray) + 8);

	if (!arrayOfWords)
		exitWithError("allocation failure ! ", 1);

	while (str[i])
	{
		while (str[i] == ' ' && str[i])
			i++;

		if (!str[i])
			return (arrayOfWords);

		/*i++;*/

		while (str[i] != ' ' && str[i])
			sizeStr++, i++;

		arrayOfWords[arrayIndex] = malloc((sizeof(char) * sizeStr) + 1);
		if (!arrayOfWords[arrayIndex])
		{
			for (j = 0 ; j < arrayIndex ; j++)
				free(arrayOfWords[j]);
			free(arrayOfWords);

			exitWithError("Malloc failure ! ", 1);
		}
		arrayOfWords[arrayIndex] = _memcpy(arrayOfWords[arrayIndex],
&str[i - sizeStr], sizeStr);
		arrayOfWords[arrayIndex][sizeStr] = '\0';

		arrayIndex++, sizeStr = 0;
	}
	arrayOfWords[arrayIndex] = NULL;
	return (arrayOfWords);
}

/**
 * free_ArrayOfWords - release memory
 * @arrayOfWords: array to free
 * @size: size of the array
 */
void free_ArrayOfWords(char *arrayOfWords[], int size)
{
	int i = 0;

	for (i = 0 ; i < size ; i++)
		free(arrayOfWords[i]);
	free(arrayOfWords);
}

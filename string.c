#include <stdlib.h>
#include "shell.h"
/**
 * _strcpy - copy a string from src to dest
 * @dest: destination
 * @src: source
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	for (i = 0 ; src[i] ; i++)
		dest[i] = src[i];

	dest[i++] = ' ';
	dest[i] = '\0';

	return (dest);
}

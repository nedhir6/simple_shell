#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "shell.h"

/**
 * set_memory - copy the containing of src into array
 * @array: destination
 * @src: source
 * @new_size: new size
 * @old_size: old size
 */
void set_memory(char *array, char *src, unsigned int new_size,
unsigned int old_size)
{
	unsigned int i = 0;

	while (!(i + 1 > old_size) && !(i + 1 > new_size))
	{
		array[i] = src[i];
		i++;
	}
}

/**
 * _realloc - reserve new spaces of memory for an existing array
 * @ptr: existing array
 * @old_size: size of ptr
 * @new_size: size of the new array
 * Return: dynamic array
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{

	char *dynamic_array;

	if (!new_size && ptr)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	dynamic_array = malloc(new_size);

	if (!dynamic_array)
		return (NULL);

	if (!ptr)
		return (dynamic_array);

	set_memory(dynamic_array, ptr, new_size, old_size);

	free(ptr);
	return (dynamic_array);
}

/**
 * _getline - read from standar input
 * @buffer: buffer
 * Return: number of characters read
 */
ssize_t _getline(char **buffer)
{
	size_t nb = BUFFER_SIZE;
	ssize_t nbRd = 0, n = 0;
	unsigned int old_size = BUFFER_SIZE, i = 1;

	*buffer = malloc(nb * sizeof(char));

	if (!*buffer)
		exitWithError("Malloc failure .", 1);

	do {
		if (i >= 2)
		{
			*buffer = _realloc(*buffer, old_size, old_size * i);
			/**buffer = realloc(*buffer, old_size * i);*/

			if (!*buffer)
				exitWithError("Malloc failure .", 1);
			old_size *= i;
		}
		nbRd = read(STDIN_FILENO, *buffer + n, nb);

		if (!nbRd)
			return (-1);

		n += nbRd;
		i++;

	} while (buffer[0][n - 1] != '\n' && nbRd);

	if (n == 1)
		n++;

	if (n != old_size)
	{
		*buffer = _realloc(*buffer, old_size, n);

		if (!*buffer)
			exitWithError("Malloc failure .", 1);
	}
	return (n);
}


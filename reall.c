#include "shell.h"

/**
 * _memset - fills memory with a constant byte
 * @s: pointer to the memory area to fill
 * @b: the constant byte to fill with
 * @n: the number of bytes to fill
 *
 * Return: a pointer to the filled memory area (s)
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int v;

	for (v = 0; v < n; v++)
	{
		s[v] = b;
	}
	return (s);
}

/**
 * ffree - Frees a double pointer array and its contents
 *
 * @pp: The double pointer array to free
 *
 * Return: Nothing
 */
void ffree(char **pp)
{
    char **a = pp;

    if (!pp)
        return;
    while (*pp)
        free(*pp++);
    free(a);
}

/**
 * _realloc - reallocates a memory block
 * @ptr: pointer to the memory previously allocated
 * @old_size: size of the old memory block
 * @new_size: size of the new memory block
 *
 * Return: pointer to the new memory block or NULL on failure
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr, *old_ptr;
	unsigned int i;

	if (!new_size)
	{
		free(ptr);
		return (NULL);
	}

	if (!ptr)
	{
		return (malloc(new_size));
	}

	if (new_size == old_size)
	{
		return (ptr);
	}

	new_ptr = malloc(new_size);
	if (!new_ptr)
	{
		return (NULL);
	}

	old_ptr = ptr;
	for (i = 0; i < old_size && i < new_size; i++)
	{
		new_ptr[i] = old_ptr[i];
	}

	free(ptr);
	return (new_ptr);
}


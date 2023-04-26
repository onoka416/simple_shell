#include "shell.h"

/**
 * bfree - Frees memory and sets the pointer to NULL
 * @ptr: Pointer to a pointer to memory that needs to be freed
 *
 * Return: 1 on success, 0 otherwise
 */
int bfree(void **ptr)
{
	if (ptr != NULL && *ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}

	return (0);
}


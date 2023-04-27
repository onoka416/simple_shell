#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
/* This function is the entry point for the shell. */

	info_t info[] = { INFO_INIT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));
 /* Check if there is only one argument. */
	if (ac == 2)
	{
		/* Open the file specified in the argument. */
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			/* If there are more than one argument, print an error message and exit. */
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	  /* Populate the environment list. */
	populate_env_list(info);
	read_history(info);
	/* Run the shell. */

	hsh(info, av);
	return (EXIT_SUCCESS);
}

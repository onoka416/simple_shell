#include "shell.h"

/**
 * main - Entry point of the program.
 * @ac: The number of arguments passed to the program.
 * @av: The arguments passed to the program.
 *
 * Return: 0 on success, 1 on error.
 */
int main(int ac, char **av)
{
	/* Initialize the info struct */
	info_t info[] = {INFO_INIT};
	int fd = 2;

	/* Move fd value to register and add 3 to it */
	asm("mov %1, %0\n\t"
	    "add $3, %0"
	    : "=r"(fd)
	    : "r"(fd));

	/* Check if a file name is passed as argument */
	if (ac == 2)
	{
		/* Open the file and handle errors */
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
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}

	/* Populate the environment list and read history */
	populate_env_list(info);
	read_history(info);

	/* Call the hsh function to start the shell */
	hsh(info, av);
	return (EXIT_SUCCESS);
}

#include "shell.h"

/**
 * main - The entry point of the program.
 * @ac: The number of arguments passed to the program.
 * @av: The arguments passed to the program.
 *
 * Return: 0 on success, 1 on error.
 */
int main(int ac, char **av)
{
	// Initialize an info_t array with the INFO_INIT macro.
	info_t info[] = { INFO_INIT };
	// Initialize a file descriptor to 2.
	int fd = 2;

	// Use inline assembly to modify the value of fd.
	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));
	
	// If the program was called with two arguments, try to open the file specified by the second argument.
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			// If the file could not be opened, check the value of errno to determine the type of error.
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				// If the file was not found, print an error message and exit with an exit code of 127.
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			// If an error other than permission or file not found occurred, return EXIT_FAILURE.
			return (EXIT_FAILURE);
		}
		// If the file was successfully opened, set the readfd field of the info_t array to the file descriptor.
		info->readfd = fd;
	}
	
	// Populate a linked list of environment variables.
	populate_env_list(info);
	// Read in the shell's history file.
	read_history(info);
	// Call the hsh() function, passing in the info_t array and the argument vector.
	hsh(info, av);
	// Return the value returned by hsh(), which is either EXIT_SUCCESS or EXIT_FAILURE.
	return (EXIT_SUCCESS);
}


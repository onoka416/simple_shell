#include "shell.h"

/**
 * main - Entry point of the shell program
 * @argc: The number of arguments
 * @argv: An array of strings containing the arguments
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
    /* Initialize a struct containing information about the shell */
    shell_info_t shell_info[] = { SHELL_INFO_INIT };

    int file_descriptor = 2;

    /* Inline assembly to add 3 to the file descriptor */
    asm ("mov %1, %0\n\t"
         "add $3, %0"
         : "=r" (file_descriptor)
         : "r" (file_descriptor));

    /* If an input file is provided, open it for reading */
    if (argc == 2)
    {
        file_descriptor = open(argv[1], O_RDONLY);
        if (file_descriptor == -1)
        {
            /* Handle errors when opening the file */
            if (errno == EACCES)
                exit(126);
            if (errno == ENOENT)
            {
                _eputs(argv[0]);
                _eputs(": 0: Can't open ");
                _eputs(argv[1]);
                _eputchar('\n');
                _eputchar(BUF_FLUSH);
                exit(127);
            }
            return (EXIT_FAILURE);
        }
        /* Set the read file descriptor to the opened file */
        shell_info->readfd = file_descriptor;
    }
    /* Populate the environment list */
    populate_env_list(shell_info);
    /* Read command history */
    read_history(shell_info);
    /* Start the shell program */
    start_shell(shell_info, argv);

    return (EXIT_SUCCESS);
}


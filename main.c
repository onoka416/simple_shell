#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av) {
  info_t info = INFO_INIT;
  int fd = 2;

  /* Check if there is only one argument */
  if (ac == 2) {
    /* Open the file specified in the argument */
    fd = open(av[1], O_RDONLY);
    if (fd == -1) {
      /* Check for errors */
      if (errno == EACCES) {
        exit(126);
      } else if (errno == ENOENT) {
        _eputs(av[0]);
        _eputs(": 0: Can't open ");
        _eputs(av[1]);
        _eputs(CRLF);
        _eputchar(BUF_FLUSH);
        exit(127);
      } else {
        return EXIT_FAILURE;
      }
    }
    /* Set the file descriptor for reading */
    info.readfd = fd;
  }

  /* Populate the environment list */
  populate_env_list(&info);
  /* Read the history */
  read_history(&info);
  /* Run the shell */
  hsh(&info, av);

  return EXIT_SUCCESS;
}


#ifndef SHELL_H
#define SHELL_H

/* headers and libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* macros */
#define PROMPT "$ "

/* function prototypes */
char **tokenizer(char *str);
void free_tokens(char **tokens);
int execute(char **args, char **environ);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_getenv(char *name, char **environ);
char *find_path(char *command, char **environ);

/* custom data types */
typedef struct list_s {
    char *str;
    struct list_s *next;
} list_t;

#endif /* SHELL_H */


#ifndef PARSER_H
#define PARSER_H

#define TRUE 1
#define FALSE 0

#define STDIN 0
#define STDOUT 1
#define STDERR 2

#define NON_INTERACTIVE 0
#define INTERACTIVE 1

#define PERMISSIONS 1
#define NON_PERMISSIONS -1

#define FILE 10
#define NON_FILE -10

#define ENOENT "No such file or directory"
#define EACCES "Permission denied"
#define CMD_NOT_EXISTS "not found"
#define ILLEGAL_NUMBER "Illegal number"

#define CODE_ENOENT 3
#define CODE_EACCES 13
#define CODE_CMD_NOT_EXISTS 132
#define CODE_ILLEGAL_NUMBER 133

/**
 * struct general_s - struct containing general information
 * @argc: the number of arguments received
 * @argv: arguments received
 * @mode: INTERACTIVE or NON_INTERACTIVE
 * @error_code: error code for error message
 * @command: command to execute
 * @n_commands: number of commands executed
 * @value_path: path of a command
 * @is_current_path: check if is current path or not
 * @status_code: last exit code
 * @buffer: line read with the getline
 * @arguments: line split into words
 * @environment: last environment variable get it
 * @pid: process id
 */
typedef struct general_s
{
	int argc;
	char **argv;
	int mode;
	int error_code;
	char *command;
	int n_commands;
	char *value_path;
	int is_current_path;
	int status_code;
	char *buffer;
	char **arguments;
	char *environment;
	int pid;
} general_t;

/**
 * struct error_s - struct containing error information
 * @message: error message
 * @code: error code for identifying the error message
 */
typedef struct error_s
{
	char *message;
	int code;
} error_t;

/**
 * struct builtin_s - struct containing builtin function information
 * @command: arguments[0] = cmd
 * @func: function pointer
 */
typedef struct builtin_s
{
	char *command;
	void (*func)(general_t *info, char **arguments);
} builtin_t;

#endif /* PARSER_H */


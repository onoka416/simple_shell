#include "built-ins.h"

/**
 * built-ins - Checks and then executes the built-in commands
 *
 * @info:shows the Shell information
 * @arguments: Thearguments of the command
 *
 * Return the  _TRUE if the command is a built-in,therwise _FALSE.
 **/
int builtins(general_t *info, char **arguments)
{
    int status;

    status = check_builtin(info, arguments);
    if (status == _FALSE)
        return (_FALSE);

    return (_TRUE);
}

/**
 * check_builtin - Check if the command is a built-in
 *
 * @info: Shell information
 * @arguments: Command arguments
 *
 * Return: _TRUE if the command is a built-in, _FALSE otherwise
 **/
int check_builtin(general_t *info, char **arguments)
{
    int i, size;
    builtin_t builtins[] = {
        {"exit", bin_exit},
        {"env", bin_env}
    };

    size = sizeof(builtins) / sizeof(builtins[0]);
    for (i = 0; i < size; i++)
    {
        if (_strcmp(info->command, builtins[i].command) == 0)
        {
            builtins[i].func(info, arguments);
            return (_TRUE);
        }
    }

    return (_FALSE);
}


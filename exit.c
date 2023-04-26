#include "built-ins.h"
#include "parser.h"

/**
 * bin_exit - Implementation of the exit builtin
 *
 * Description: Frees all the memory used and exits with the last status_code
 *
 * @info: Information about the shell
 * @arguments: Arguments received
 **/
void bin_exit(general_t *info, char **arguments)
{
        int status_code, status;

        status = TRUE;
        if (arguments[1] != NULL)
                status = number_controller(info, arguments[1]);

        if (status == FALSE)
                return;

        status_code = info->status_code;

        free_memory_pp((void **) arguments);
        free_memory_p((void *) info->buffer);
        free_memory_p((void *) info->environment);
        free_memory_p((void *) info);

        exit(status_code);
}

/**
 * number_controller - Control the argument of exit
 *
 * Description: Controls the argument of exit
 *
 * @info: General information about the shell
 * @number: Argument of the builtin
 *
 * Return: If the actual argument is valid, return _TRUE
 * if not, return _FALSE
 **/
int number_controller(general_t *info, char *number)
{
        int _number;

        _number = _atoi(number);

        if (_number < 0 || contains_letter(number))
        {
                info->status_code = 2;
                info->error_code = CODE_ILLEGAL_NUMBER;
                error_extra(info, number);
                return (FALSE);
        }

        if (_number > 255)
                info->status_code = _number % 256;
        else
                info->status_code = _number;

        return (TRUE);
}


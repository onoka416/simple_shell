#include "shell.h"

/**
 * interactive - Returns true if the shell is in interactive mode.
 * @info: A pointer to the struct containing information about the shell.
 *
 * Return: 1 if the shell is in interactive mode, 0 otherwise.
 */
int interactive(info_t *info)
{
    return (isatty(STDIN_FILENO) && info->readfd <= STDERR_FILENO);
}

/**
 * is_delim - Checks if a character is a delimiter.
 * @c: The character to check.
 * @delim: A string of delimiters.
 *
 * Return: 1 if c is a delimiter, 0 otherwise.
 */
int is_delim(char c, char *delim)
{
    while (*delim)
    {
        if (*delim++ == c)
            return (1);
    }
    return (0);
}

/**
 * _isalpha - Checks if a character is alphabetic.
 * @c: The character to check.
 *
 * Return: 1 if c is alphabetic, 0 otherwise.
 */
int _isalpha(int c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * _atoi - Converts a string to an integer.
 * @s: The string to convert.
 *
 * Return: The integer value of the string, or 0 if no numbers are found.
 */
int _atoi(char *s)
{
    int i, sign = 1, flag = 0, output;
    unsigned int result = 0;

    for (i = 0; s[i] != '\0' && flag != 2; i++)
    {
        if (s[i] == '-')
            sign *= -1;

        if (_isdigit(s[i]))
        {
            flag = 1;
            result *= 10;
            result += (s[i] - '0');
        }
        else if (flag == 1)
            flag = 2;
    }

    if (sign == -1)
        output = -result;
    else
        output = result;

    return (output);
}

/**
 * _isdigit - Checks if a character is a digit.
 * @c: The character to check.
 *
 * Return: 1 if c is a digit, 0 otherwise.
 */
int _isdigit(int c)
{
    return (c >= '0' && c <= '9');
}


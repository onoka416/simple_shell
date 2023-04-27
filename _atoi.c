#include "shell.h"

/**
 * _myenv - Prints the current environment.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *
 * Return: Always 0.
 */
int _myenv(info_t *info)
{
    /* Print the linked list of environment variables. */
    print_list_str(info->env);
    return (0);
}

/**
 * _getenv - Gets the value of an environment variable.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @name: Environment variable name.
 *
 * Return: The value of the environment variable.
 */
char *_getenv(info_t *info, const char *name)
{
    list_t *node = info->env;
    char *p;

    /* Traverse the linked list until the environment variable is found. */
    while (node)
    {
        /* Check if the environment variable matches the given name. */
        p = starts_with(node->str, name);
        if (p && *p)
            return (p);
        node = node->next;
    }
    /* Return NULL if the environment variable is not found. */
    return (NULL);
}

/**
 * _mysetenv - Initializes a new environment variable or modifies an existing one.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *
 * Return: Always 0.
 */
int _mysetenv(info_t *info)
{
    /* Check if the correct number of arguments is passed in. */
    if (info->argc != 3)
    {
        _eputs("Incorrect number of arguments.\n");
        return (1);
    }
    /* Set the environment variable using the _setenv function. */
    if (_setenv(info, info->argv[1], info->argv[2]))
        return (0);
    return (1);
}

/**
 * _myunsetenv - Removes an environment variable.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *
 * Return: Always 0.
 */
int _myunsetenv(info_t *info)
{
    int i;

    /* Check if there are enough arguments passed in. */
    if (info->argc == 1)
    {
        _eputs("Too few arguments.\n");
        return (1);
    }
    /* Unset the environment variables using the _unsetenv function. */
    for (i = 1; i <= info->argc; i++)
        _unsetenv(info, info->argv[i]);

    return (0);
}

/**
 * populate_env_list - Populates the environment linked list.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *
 * Return: Always 0.
 */
int populate_env_list(info_t *info)
{
    list_t *node = NULL;
    size_t i;

    /* Traverse the array of environment variables and add each one to the linked list. */
    for (i = 0; environ[i]; i++)
        add_node_end(&node, environ[i], 0);
    info->env = node;
    return (0);
}

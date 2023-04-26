#include "shell.h"

/**
 * add_node - add a node to the beginning of a list
 * @head: pointer to pointer to first node in list
 * @str: string to be stored in new node
 *
 * Return: pointer to new node
 */
list_t *add_node(list_t **head, char *str)
{
    list_t *new_node;

    new_node = malloc(sizeof(list_t));
    if (new_node == NULL)
        return (NULL);

    new_node->str = _strdup(str);
    new_node->next = *head;
    *head = new_node;

    return (new_node);
}

/**
 * add_node_end - add a node to the end of a list
 * @head: pointer to pointer to first node in list
 * @str: string to be stored in new node
 *
 * Return: pointer to new node
 */
list_t *add_node_end(list_t **head, char *str)
{
    list_t *new_node;
    list_t *last_node = *head;

    new_node = malloc(sizeof(list_t));
    if (new_node == NULL)
        return (NULL);

    new_node->str = _strdup(str);
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return (new_node);
    }

    while (last_node->next != NULL)
        last_node = last_node->next;

    last_node->next = new_node;
    return (new_node);
}

/**
 * free_list - free a list
 * @head: pointer to first node in list
 */
void free_list(list_t **head)
{
    list_t *node;

    while (*head != NULL) {
        node = *head;
        *head = (*head)->next;
        free(node->str);
        free(node);
    }
}


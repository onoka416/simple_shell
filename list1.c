#include "shell.h"

/**
 * list_len - Counts the number of nodes in a linked list.
 *
 * @h: Head node of the linked list.
 *
 * Return: Number of nodes in the list.
 */
size_t list_len(const list_t *n)
{
	size_t count = 0;

	while (n != NULL)
	{
		count++;
		n = n->next;
	}

	return (count);
}
/**
 * list_len - Counts the number of nodes in a linked list.
 *
 * @g: Head node of the linked list.
 *
 * Return: Number of nodes in the list.
 */
size_t list_len(const list_t *g)
{
	size_t count = 0;

	while (g != NULL)
	{
		count++;
		g = g->next;
	}

	return (count);
}
/**
 * print_list - Prints all the elements of a list_t list.
 *
 * @head: Pointer to the head node of the list.
 *
 * Return: Number of nodes in the list.
 */
size_t print_list(const list_t *head)
{
	size_t count = 0;

	while (head != NULL)
	{
		printf("[%d] %s\n", head->num, head->str ? head->str : "(nil)");
		head = head->next;
		count++;
	}

	return (count);
}
/**
 * node_starts_with - finds the first node in the linked list whose string starts with
 * the given prefix and optionally matches the specified character
 * @node: pointer to the head node of the linked list
 * @prefix: prefix to search for in the strings
 * @s: character to match (use -1 to skip matching)
 *
 * Return: pointer to the first node whose string starts with prefix and matches the character s,
 *         or NULL if no such node is found
 */
list_t *node_starts_with(list_t *node, char *prefix, char s)
{
	char *p;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && (s == -1 || *p == s))
			return (node);
		node = node->next;
	}
	return (NULL);
}
/**
 * get_node_index - Get the index of a node in a linked list
 *
 * @head: A pointer to the head node of the linked list
 * @node: A pointer to the node to find the index of
 *
 * Return: The index of the node if found, or -1 if not found
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t y = 0;

	while (head)
	{
		if (head == node)
			return (y);
		head = head->next;
		y++;
	}
	return (-1);
}


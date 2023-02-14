#include "list.h"

/**
 * _strlen - counts characters on a string
 *
 * @str: the string to count its number characters
 *
 * Return: number of characters on the string
 */
unsigned int _strlen(char *str)
{
	unsigned int count = 0;

	if (!str)
		return (NULL);

	while (str[count++])
	;
	return (count);
}

/**
 * _strdup - produces a copy of a string
 *
 * @str: the string to make a copy of
 *
 * Return: Address of the new string
 */
char *_strdup(char *str)
{
	size_t size = sizeof(char) * (_strlen(str) + 1);
	unsigned int i = 0;
	char *copy = NULL;

	if (!str)
		return (NULL);

	copy = malloc(size);
	if (!copy)
	{
		free(copy);
		return (NULL);
	}
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}


/**
 * add_node_end - Add a new node to the end of a double circular linked list
 *
 * @list: A pointer to the head of the linkd list
 * @str: the string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new = malloc(sizeof(List));

	if (!new)
		return (NULL);


	new->str = _strdup(str);
	if (!new->str)
		return (NULL);
	if (!*list)
	{
		new->prev = new;
		new->next = new;
		return (*list = new);
	}


	new->prev = (*list)->prev;
	(*list)->prev->next = new;
	(*list)->prev = new;
	new->next = *list;


	return (new);
}


/**
 * add_node_begin - Add a new node to the end of a double circular linked list
 *
 * @list: A pointer to the head of the linkd list
 * @str: the string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new = malloc(sizeof(List));

	if (!new)
		return (NULL);

	new->str = _strdup(str);
	if (!new->str)
		return (NULL);

	if (!*list)
	{
		new->prev  = new;
		new->next  = new;
		return (*list = new);
	}

	new->prev = (*list)->prev;
	(*list)->prev->next = new;
	(*list)->prev = new;
	new->next = *list;


	return (*list = new);
}

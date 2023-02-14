#include "list.h"
#include <stdlib.h>
#include <stdio.h>

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

	new->str = str;

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

	new->str = str;

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

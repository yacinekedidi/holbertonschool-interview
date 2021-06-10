#include "lists.h"



/**
 * check_cycle - checks if a singly linked list has a cycle in it.
 * @list: pointer to head of the list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
listint_t *turtle, *hare;



turtle = hare = list;
while (turtle && hare && hare->next)
{
	turtle = turtle->next;
	hare = hare->next->next;
	if (turtle == hare)
		return (1);
}

return (0);
}

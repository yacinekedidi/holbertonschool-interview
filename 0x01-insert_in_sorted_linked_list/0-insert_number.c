#include "lists.h"


/**
 * insert_node - Insert in sorted linked list
 * @head: head node
 * @number: value
 * Return: nnewly inserted node
 */

listint_t *insert_node(listint_t **head, int number)
{
listint_t *new, *p = *head, *tmp;

new = malloc(sizeof(listint_t));
if (!new)
return (NULL);
new->n = number;

if (!*head || (*head)->n > number)
{
	new->next = *head;
	*head = new;
	return (new);
}



while (p->next)
{
if (p->next->n >= number)
break;
p = p->next;
}
tmp = p->next;
p->next = new;
new->next = tmp;

return (new);
}

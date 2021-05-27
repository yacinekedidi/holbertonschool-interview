#include "lists.h"


/**
 * recursive - compares each time the head and tail nodes
 * to make sure we have a palindrome
 * @head: node from start to end
 * @tail: node from end to start
 * (once we reach the last node -> once the recursive starts returning)
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int recursive(listint_t **head, listint_t *tail)
{
	int isPalin;

	if (!tail)
		return (1);

	isPalin = recursive(head, tail->next) && ((*head)->n == tail->n);
	if (!isPalin)
		return (0);

	*head = (*head)->next;


	return (isPalin);
}


/**
 * is_palindrome -  checks if a singly linked list is a palindrome.
 * @head: pointer to pointer of first node of listint_t list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	return (recursive(head, *head));
}

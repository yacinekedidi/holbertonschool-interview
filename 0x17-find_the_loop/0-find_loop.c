#include "lists.h"



/**
 * find_listint_loop -  finds the loop in a linked list.
 * @head: the head of the list
 * Return: Always.
 */
listint_t *find_listint_loop(listint_t *head) {
    listint_t *hare, *turtle;
    if (!head)
        return (NULL);

    turtle = head;
    hare = head;

    while(turtle && hare && hare->next)
    {
        turtle = turtle->next;
        hare = hare->next->next;

        if(turtle == hare)
        {
            turtle = head;
            while(turtle && hare)
            {
                if (turtle == hare)
                    return (turtle);
                turtle = turtle->next;
                hare = hare->next;
            }
        }
    }

return (NULL);
}
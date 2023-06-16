#include "lists.h"

/**
 * find_listint_loop - find the loop in a linked list.
 * @head: head of the linked list
 * Return: The address of the node where the loop starts,
 * or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *rabbit = head;
	listint_t *turtle = head;

	if (head == NULL)
		return (NULL);

	while (rabbit && rabbit->next && rabbit->next->next)
	{
		turtle = turtle->next;
		rabbit = rabbit->next->next;
		if (turtle == rabbit)
		{
			turtle = head;
			while (turtle != rabbit)
			{
				turtle = turtle->next;
				rabbit = rabbit->next;
			}
			return (rabbit);
		}
	}
	return (NULL);
}

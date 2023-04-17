#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - function to validate  the value
 * @list: head of singly linked list
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{

	listint_t *tortuga, *poto;

	if (!list)
		return (0);

	tortuga = list;
	poto = list;

	while (tortuga && poto && poto->next)
	{
		tortuga = tortuga->next;
		poto = poto->next->next;

		if (poto == tortuga)
			return (1);
	}

	return (0);
}

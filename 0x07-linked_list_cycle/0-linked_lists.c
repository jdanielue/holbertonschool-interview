#include <stdlib.h>
#include "lists.h"
#include <stdio.h>

/**
 * print_listint - prints every elem
 * @h: poiint to head of list
 * Return: num de nodes
 */
size_t print_listint(const listint_t *h)
{
	const listint_t *current;
	unsigned int num; /* number of nodes */

	current = h;
	num = 0;
	while (current != NULL)
	{
		printf("%i\n", current->num);
		current = current->prox;
		num++;
	}

	return (num);
}

/**
 * add_nodeint - adds a new node at the beginning of a listint_t list
 * @head: pointo a pointer of the start of the list
 * @num: int to be included in node
 * Return: address of the element else  NULL
 */
listint_t *add_nodeint(listint_t **head, const int num)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->num = num;
	new->prox = *head;
	*head = new;

	return (new);
}

/**
 * free_listint - frees a listint_t list
 * @head: pointer to list to be freed
 * Return: void
 */
void free_listint(listint_t *head)
{
	listint_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->prox;
		free(current);
	}
}

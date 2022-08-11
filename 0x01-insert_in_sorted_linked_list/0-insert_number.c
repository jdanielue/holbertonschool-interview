#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - insert node in sorted way
 * @head: -> to the list's first node
 * @number: int to be stored in the new node
 * Return: ->nde
 */
listint_t *insert_node(listint_t **head, int number) {
    listint_t *new_node = NULL;
    listint_t *temp = NULL;

    if (head == NULL) {
        return (NULL);
    }

    if (*head == NULL) {
        new_node = c_node(number);
        *head = new_node;
        return (new_node);
    }
    temp = *head;

    if (number <= temp->n) {
        new_node = c_node(number);
        new_node->next = temp;
        *head = new_node;
        return (new_node);
    }


    while(temp->next) {
        if (number <= temp->next->n) {
            break;
        }
        temp = temp->next;
    }


    if (!temp->next) {
        new_node = c_node(number);
        temp->next = new_node;
        return (new_node);
    } 

    new_node = c_node(number);
    new_node->next = temp->next;
    temp->next = new_node;

    return (new_node);

}

/**
 * c_node - new listint_t node 
 * @number: int to be stored in the new node
 * Return: -> to new node
 */
listint_t *c_node(int number) {
    listint_t *new_node = NULL;

    new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
    
    new_node->n = number;
    new_node->next=NULL;

    return (new_node);
}
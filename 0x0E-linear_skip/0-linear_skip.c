#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers.
 * @list:  pointer to the head of the skip list to search in
 * A node of the express lane is placed every index
 * which is a multiple of the square root of the size of the list
 * @value: the value to search for
 *
 * Return: pointer on the first node where value is located
 * If value is not present in list or if head is NULL, return NULL
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *fast_node, *previous = list;

	if (!list)
		return (NULL);

	fast_node = list->express;

	while (fast_node)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       fast_node->index, fast_node->n);
		if (!fast_node->express || fast_node->n >= value)
		{
			if (!fast_node->express && fast_node->n < value)
			{
				previous = fast_node;
				while (fast_node->next)
					fast_node = fast_node->next;
			}
			printf("Value found between indexes [%lu] and [%lu]\n",
			       previous->index, fast_node->index);
			while (previous)
			{
				printf("Value checked at index [%lu] = [%d]\n",
				       previous->index, previous->n);
				if (previous->n > value)
					return (NULL);
				if (previous->n == value)
					return (previous);
				previous = previous->next;
			}
			break;
		}
		previous = fast_node;
		fast_node = fast_node->express;
	}
	return (NULL);
}

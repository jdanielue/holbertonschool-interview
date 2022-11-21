#ifndef SEARCH_H
#define SEARCH_H

#include <stdlib.h>
#include <stdio.h>
/**
 * struct skiplist_s - Singly linked list with an express lane
 *
 * @n: Lorem ipsum dolor sit amet
 * @index: Lorem ipsum dolor sit amet
 * @next: Lorem ipsum dolor sit amet
 * @express: "Lorem ipsum dolor sit amet
 *
 * Description: Lorem ipsum dolor sit amet
 * Lorem ipsum dolor sit amet
 */
typedef struct skiplist_s
{
	int n;
	size_t index;
	struct skiplist_s *next;
	struct skiplist_s *express;
} skiplist_t;

skiplist_t *linear_skip(skiplist_t *list, int value);

#endif /* _SEARCH_H_ */

#include <stdlib.h>   //For NULL and free(...)
#include "node.h"

/** 
 * If the list is empty, there is nothing to delete!
 * In this case, the message
 * "Illegal attempt to delete from an empty list"
 * is printed to stderr and the program terminates with
 * exit(-1);
 * Otherwise, the list has at least one item. The head
 * of the list's value is returned after freeing the
 * memory it occupied.
 * The head of the list is modified.
 */
int delete(nodePtr_t *h) {
    nodePtr_t oldHead = *h;

if (oldHead==NULL)
{
printf ("Error");
}

int x= oldHead -> value;

*h = oldHead -> next;
free (oldHead);

	return x;
}
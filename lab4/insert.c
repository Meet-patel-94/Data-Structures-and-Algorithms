#include <stdlib.h>  //for malloc
#include "node.h"
/** Create a new node and insert it at the
 * beginning fo the list pointed to by *h.  The
 * list head will be modified.
 */
void insert(int v, nodePtr_t *h) {
    /* Allocate space for a node. */
    nodePtr_t nodeP = malloc(sizeof (node_t));
    /*Make it's next field point to the rest of list */
    nodeP->next = *h;
    nodeP->value = v;
    /*Make the new node the head of the list */
    *h = nodeP;
}


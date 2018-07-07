#include "node.h"
#include <stdio.h>

/**
 * Print the size of the list. Then print the
 * message(msg) followed by the values of each item
 * in the list pointed to by h.
 */
void print(char * msg, nodePtr_t h) {
    printf("%s, list size now: %d\n", msg, list_size(h));
    while (h != NULL) {
        printf("%d\n", h->value);
        h = h->next;
    }
}

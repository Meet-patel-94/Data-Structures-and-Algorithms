#include "node.h"
#include <stdlib.h>  //for NULL

/** Returns the number of items in the list. */
unsigned int list_size(nodePtr_t head) {
int count = 0;
while (head!=NULL)
{
head = head -> next;
count++;
}
return count;
}

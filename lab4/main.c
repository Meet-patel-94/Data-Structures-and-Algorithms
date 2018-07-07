#include <stdio.h>   //for printf
#include "node.h"

int main(int argc, char** argv) {
    //initialize "head" to NULL, i.e. an empty list
    nodePtr_t head = NULL;
    print("Printing empty list", head);
    insert(5, &head);
    print("Printing list after '5' inserted", head);
    insert(6, &head);
    printf("List size: %d\n", list_size(head));
    insert(7, &head);
    print("Printing list after 6 and 7 inserted", head);
    printf("Deleting %d\n", delete(&head));
    print("Printing list after deletion", head);

    return (0); //returning from main makes exit status = 0
}
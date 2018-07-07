#ifndef NODE_H
#define	NODE_H
//Typedefs
typedef struct node {
    int value;
    struct node * next;
} node_t, * nodePtr_t;

//Function signatures
void insert(int v, nodePtr_t *h);
void print(char * msg, nodePtr_t h);
int delete(nodePtr_t *h);
unsigned int list_size(nodePtr_t head);

#endif	/* NODE_H */
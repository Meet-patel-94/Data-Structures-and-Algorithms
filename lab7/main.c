#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int heapDelete();
extern int heapSize();
extern void addHeap(int);
extern void printHeap(int);
extern int pop();
extern void push(int);
extern int isEmpty();


int main(int argc, char * argv[])
{
int size,i,value,temp;


while (scanf("%d\n", &value) != EOF){	
fprintf(stderr, "READING INPUT: %d\n", value);
addHeap(value); 
}



printHeap(0);
printf("\n");
while(heapSize()!=-1){
temp=heapDelete();
printf("\n%d",temp);
push(temp);

}
printf("\n\n");

while((temp=pop())!=-1){
printf("%d\n",temp);
}
}

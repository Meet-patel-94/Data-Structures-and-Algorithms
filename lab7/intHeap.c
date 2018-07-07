#include <stdio.h>

static int h[100];

static int key = -1;


int heapDelete()
{	
int max,temp,i;
max=h[0];
for(i=0;i<=key;i++){
if(max<h[i]){
max=h[i];}}
for(i=0;i<=key;i++){
if(max==h[i]){
break;}}
temp =h[i];
h[i]=h[key];
h[key]=temp;
key--;
return max;

}

int heapSize()
{
  return key;  //A dummy return statement
}


void addHeap(int thing2add)
{
	int p,temp;
	key++;
	p=key;
	h[key]=thing2add;
	while(p>0 && h[((p-1)/2)]<h[p]){
		temp=h[p];
		h[p]=h[((p-1)/2)];
		h[((p-1)/2)]=temp;
		p=((p-1)/2);
	}
}


void printHeap(int i){
char j = '"';
	int temp;
	printf("\n");
	if(i<=key){
		for(temp=(1+i)/2;temp>0;temp--){
			printf("\t");
			}
		printf("<node id=%c%d%c>",34,h[i],34);
		if((i*2)+1<=key){
		
			printHeap((i*2)+1);
			
		}
		if((i*2)+2<=key){
		
			printHeap((i*2)+2);
			
		}
	for(temp=(1+i)/2;temp>0;temp--){
			if((i*2)+1<=key||(i*2)+2<=key){
			printf("\t");
			}}
	printf("</node>");
	}
	printf("\n");
}		

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern int isEmpty();
int main(int argc, char * argv[])
{
  int ch,x=-5;
  int a[100][2];
  int k=0,y=0,i=0,j=0;

  
  

  while ((ch = getchar()) != EOF) {
    if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/')){
           if(x!=-5){
               printf("VALID\n\n");
	       for(i=0;i<y;i++){
                 printf("%c  %d\n\n",a[i][0],a[i][1]);
  	       }
 	   }
     }
      else{ 
	 printf("NOT VALID!\n");
	 exit(0);
	 }
       }
  if(ch=='<'){
  ch=getchar();
  if(ch =='/'){
  ch=getchar();
  if (!(isalpha(ch))){exit(0);}
  x=pop(ch);
  }else{
  if (!(isalpha(ch))){exit(0);}
  push(ch);
  
  
  ///////////////////////////////////////////////////////////////////////////////
  for(i=0;i<100;i++){
  if(a[i][0]==ch)
  {a[i][1]++;
  k=10;}
  }
  if(k==0){
  a[y][0]=ch;
  a[y][1]=1;
  k=0;
  y++;
  }
  ///////////////////////////////////////////////////////////////////////////////
  }
  }
  if(x==-1){
  printf("NOT VALID\n");
  exit(0);
  }
}




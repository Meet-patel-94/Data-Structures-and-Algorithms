 #include <stdio.h>
 #include <stdlib.h>
 #include <ctype.h>


   static int top=0 ;
   static int stack[100];



int pop()
{
  
  if (top==0)
  {
return (-1);
  }
  else
  {
  top--;
  return stack[top+1];
  }  
}
void push(int thing2push)
{
if(top<99)
{
top = top+1;
stack[top]=thing2push;
return;
}
else
{
printf("STACK IS FULL\n");
return;
}
}

int isEmpty()
{
  return top;  
}

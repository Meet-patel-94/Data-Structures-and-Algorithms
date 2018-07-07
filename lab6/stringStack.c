#include<string.h>
#include<stdlib.h>
#include<stdio.h>

/**
 *  The functions in this module implement a Stack data structure
 *  of char pointers (aka "strings").
 *  
 *  NOTE: the stack is implemented as a fixed size array (size = 100).
 *  Consequently, no more than 100 strings can be pushed onto
 *  the Stack at any given time.
 */

// Implementation hints:
//   The 3 functions--push, pop and isEmpty--share information
//   about the array used to implement the stack and the index
//   of the "top" of the stack.
//
//   You may want to make these variables global...
//   ...but that would
//   be a mistake (because anyone using the module would have
//   to ensure that they did not use global variables with the
//   same names).
//
//   An alternative in C is a "static global".
//   If a global variable is qualified as "static", it is global only
//   within the source code file where it is declared.
//   In parituclar, it cannot conflict with any other global variable.
//
//  RECOMMENDATION:
//   Uncomment the following 2 lines and use these static globals!
static int top = 0;
static char * stack[100];

/**
 * pop() removes the top string on the stack and returns it.
 *
 * If pop() is attempted on an empty stack, an error message
 * is printed to stderr and the value NULL ((char *) 0) is returned.
 */

char *  pop()
{
	if(top == 0)
	{
		printf("Stack is empty: Underflow error!\n");
		return (char *)-1;
	}
	else
	{
		char *p;
		p = stack[top];
		top--;
		return p; //Return a pointer to a character, AKA a string
	}
}

/**
 *  push(thing2push) adds the "thing2push" to the top of the stack.
 *
 *  If there is no more space available on the Stack, an error
 *  message is printed to stderr.
 */
void push(char * thing2push)
{
	if (top == 100)
	{
		printf ("Stack if full:error\n");
	}
	else
	{
		top++;
		stack[top] = thing2push;
		
	}

}

/**
 * isEmpty() returns a non-zero integer (not necessarily 1) if the
 * stack is empty; otherwise, it returns 0 (zero).
 *
 */
int isEmpty()  // 1 for true, 0 for false
{
	if (top == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}


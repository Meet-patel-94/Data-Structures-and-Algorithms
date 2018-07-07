#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern int isEmpty();

 
int main(int argc, char * argv[])    {
     
    int ch, popped;

    printf("Important! 'q' is reserve for stating your series of tag has ended.\n");
    printf("EOF was not used because computer does not recognize when my direct\n");
    printf("typing input has ended, and I am not sure your input is file or direct typing.\n");
    printf("Example input: <a><b></b></a>q\n\n");



    //loop to read in character
    while ((ch = getchar()) != 'q') //while getchar continues to yield !='q'
    {
            	if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
        	//if it is not an alphabet or on of characters: <,>, or /
                  	continue; //so continue (to scan) is a key word!
 
           	//Identify beginning of tag
           	 else if (ch == '<') {
                    	ch = getchar(); //get the next character
                	if (ch == '/') {
                 		popped = pop();
                         
                         
                     		if (popped == -1)    {  
                       			exit(1);
              			 //exit if underflow error
              			}

                		// If you get ' / ' , then is the letter after / the same as the letter that was popped?
                           	if (getchar() != popped) {
                               	printf("Not valid.\n");
                               
                              	exit(1);
                        	}
                   	}
             	        else if (isalpha(ch)) {
                        	push(ch); //If next character is an alphabet, push it into stack
                        }

 	 
          	}
	
    }
        
    //After all data has been read, check to see if stack is empty
        if (isEmpty() == 1)     {//Confirming nothing left in stack
            printf("Valid\n");
            exit (0);
   	}
  
        else {
               printf("Not valid.\n");
               fprintf(stderr, "NOT valid.  Every start tags must have end tags.\n");
               exit (1);
        }
     
   

} 

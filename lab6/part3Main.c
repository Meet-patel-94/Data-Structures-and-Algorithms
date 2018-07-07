#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

extern char * pop();
extern void push(char *);
extern int isEmpty();
extern void init();
extern void add();
extern void printResult();



int main(int argc, char * argv[])
	{
		int ch;
       		char temp[100], temp2[100];
		
		init();
		

		printf ("Press ctrl-D after you put in all your tags\n");
		//Loop to read in characters
		while ((ch = getchar()) != EOF)
         	{
   			if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/')){
   				continue;
 			}
		//Forgot to indent else if and the rest
   		else if(ch == '<')
                {
 			ch = getchar(); // ch = read the next character
 			int i = 0; //initializing i in preparation as a counter
  			if(isalpha(ch))
                     	{
				//temp will now read in the rest of the characters in the string until ' > ' is reached
				while(ch != '>')
                         	{
 			 		temp[i] = ch;
    			 		i++;
           		 		ch = getchar(); // get the next character
  			 	}
    				temp[i] = '\0';  // putting the last character of string as the null character
    				char * str; // Create a pointer to a character, this is in essence creating a string
    				
				str = malloc((i+1)*sizeof(char));//Allocating memory for the string that 
							     //you wish to push into stack
				//str = malloc(i*sizeof(char));
    				strcpy(str,temp);//Copying temp array into that string (or character pointer)
    				
				//The C library function void *memset(void *str, int c, size_t n) copies 
				//the character c (an unsigned char) to the first n //characters of the string 
				//pointed to by the argument str.
				//memset(&temp[0],0,sizeof(temp)); //Resetting temporary array to 0
				//Might not be necessary since the '\0' ending marks the end of small words (bits of big words after are inaccessible because of '\0'      
			
				push(str); //push the string into the stack
    				add(str,i); //add the string/word/tag into the hash table

			}
			//If this is an end tag
			else if(ch == '/')
                        {
				ch = getchar(); //get the next character, which is the start of the word/string
				int i = 0;

				//temp will now read in the rest of the characters in the string until ' > ' is reached
				while(isalpha(ch))
                                {
					temp[i] = ch;
					i++;
					ch = getchar(); //get the next character in order to determine if it is alphabet
     				}
				
				temp[i] = '\0'; //assign last space as ' \0 ' to signal termination of word/string
				
				
				if(isEmpty()==1)
                                {
   					pop(); // do pop() do print out underflow error
   					exit(1); // main exits
  				}
                                else
                                {
					char * p;
					p = pop();
					strcpy(temp2,p); // copy the string output of pop() to temp2
					if(strcmp(temp,temp2) != 0)
                                        {
						fprintf(stderr,"NOT Valid\n");
						exit(1);
					}
   				}
  				//memset(&temp[0],0,sizeof(temp));
  				//memset(&temp2[0],0,sizeof(temp2));
			}
		}
	} //End of the long while loop

//After all data has been read, check to see if stack is empty

if(isEmpty() == 0)
{
	fprintf(stderr,"NOT Valid\n");	
	exit(1);
}
else
{
	printf("Valid\n");
	printResult();
}

exit(0);


}

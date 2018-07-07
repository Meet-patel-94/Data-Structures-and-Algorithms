#include <stdlib.h>
#include "towers.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    int n = 3;
    int from = 1;
    int dest = 2;
    
    if (argc == 2) {
      n = atoi(argv[1]);
    }
      if (argc == 4){
        n = atoi(argv[1]);
	from= atoi(argv[2]);
        dest= atoi(argv[3]);
    }
   
    /*There has to be atleast 1 disk for this program to compile because a disk cannot be negative.*/
    if (n<1){
      
    
    fprintf(stderr, "When compling n<1 the program will not compile because in-order for the program to compile n has to be equal 2");
    exit(1);
    }
    
   /*You cannot move the disk from towers 1 2 or 3 not another given values and both from and dest should not be equal to each other*/
   if ((dest>3)||(dest<1)||(dest==from)||(from>3)||(from<1)){
     fprintf(stderr, "The tower cannot be negative to change, therefore incorrect inovcation of code");
    exit(-1);
    }
    
   towers(n, from, dest);
    exit(0);
}
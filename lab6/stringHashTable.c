#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define HASH_TABLE_SIZE 1057

typedef struct Entry Entry, *EntryPtr;

struct Entry {
	char * string;
	int count;
};

Entry hash_table[HASH_TABLE_SIZE];




//initialize all count values to 0
void init() {
	int i;
	for ( i=0; i<HASH_TABLE_SIZE; i++)
	hash_table[i].count = 0;
}



void add(char * tag, int num)	{
	//num is the size of the tag string
	int i, sum = 0, key;

	//Sum together the ASCII values of the characters in the string:
	for (i = 0; i < num; i++) {
		sum += tag[i];
	}

	//Set key using division method
	
	key = (sum%HASH_TABLE_SIZE);

	//If the space in the table as pointed by key is occupied,
	//you either move to the next space or if the word in the space is the same as 
	//the word you are trying to find a space for, increment count (linear probing)

	if (hash_table[key].string != NULL) {
	//if the space is occupied by the same tag, increment its count, the number of times the word appear
		if (strcmp(hash_table[key].string, tag) == 0) {
			hash_table[key].count++;
		}
		else {
		//if the space is occupied by a different word/tag, go to the next 
		//space and see if it is empty, occupied, or occupied by same word.  Continue to do so until you
		//get into an empty space or you find a space occupied by same word.
			while (hash_table[key].string != NULL) {
				key=key+1;
				if (hash_table[key].string != NULL) {
					if(strcmp(hash_table[key].string, tag) == 0) {
						hash_table[key].count++;
						break;
					}
				}
			}
		}
	}
	
	//The code comes here when you find an empty space and all 
	//prior space you looked at were occupied by different words
	if (hash_table[key].string == NULL) {
	//Increment the number of times that this key is reached
		hash_table[key].count++; //Since it is the first word of its kind, count increase from 0 to 1

		//place the tag into the space
		hash_table[key].string = tag;
	}
}





void printResult() {
	int i;
	//print out names of tags used and their frequencies
	for (i = 0; i < HASH_TABLE_SIZE; i++) {
		if (hash_table[i].count != 0) {
			printf("%s %d\n", hash_table[i].string, hash_table[i].count);
		}
	}
}


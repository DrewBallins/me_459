// ME 459 HW06 task1
// Author: Andrew Wild
// This c program counts the numbers of characters in a string input
// less than 257 characters long, and prints this number

#include <stdio.h>
#include <stdlib.h>
#include "output.h"

int str_count(const char *string) {
	int count = 0;		// Initialize the counter for characters in string

	// loop through whole string from start to null character
	for(int i=0; string[i] != '\0'; i++) {
		count++;		// add to character count
	}

	return count;		// return amount of characters in input string
}

int main(int argc, char **argv) {
	// check input for validity and set it to a const char pointer
	if( argc == 2 ) {
    	const char *string_in = argv[1];
    	int char_count = str_count(string_in);
    	outputT1(char_count);
    }
    else {
    	printf("Improper input, please enter one string less than 257 characters long.\n");
    	exit(0);
    }

	return 0;
}
// ME 459 HW04 task2b
// Author: Andrew Wild
// This c program prints "Hello, world\n" to stdout

#include <stdio.h>
#include "output.h"

int main() {
	// begin by initializing n as an integer
	int n;

	// First we prompt for command line input
	printf("Please input a positive integer: ");
	
	// Next I scan in the user input integer n
	scanf("%d", &n);

	// we will use a for loop to iterate through all values from 0 to n and
	// begin by intializing counter i as an integer
	int i;
	for (i=0; i<=n; i++){
		// call outputT2 function
		outputT2(i);
	}

	return 0;
}
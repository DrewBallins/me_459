// ME 459 HW04 task2b
// Author: Andrew Wild
// This c program prints "Hello, world\n" to stdout

#include <stdio.h>
#include <stdlib.h>
#include "output.h"

int main(int argc, char **argv) {
	// begin by converting n from argv into an integer
	int n = atoi(argv[1]);

	// check that n is >= 0, if not re-prompt for input
	if (n <= 0) {
		printf("Your number is < 0 or = 0, please input positive integer next time.\n");
		exit(0);
	}

	// we will use a for loop to iterate through all values from 0 to n and
	// begin by intializing counter i as an integer
	int i;
	for (i=0; i<=n; i++){
		// call outputT2 function to print i
		outputT2(i);
	}
	printf("\n");

	return 0;
}
// ME 459 HW04 task2b
// Author: Andrew Wild
// This c program prints "Hello, world\n" to stdout

#include <stdio.h>
#include <stdlib.h>
#include "output.h"


// Function that compares two values for qsort
int int_comp(const void *first_arg, const void *second_arg){
	// cast pointers to right type
	int first = *(int *)first_arg;
	int second = *(int *)second_arg;
	// carry out comparison
	return ( first - second );
}

int main(int argc, char **argv) {
	// begin by converting n from argv into an integer
	int n = atoi(argv[1]);

	// check that n is >= 0, if not, print error message and exit program
	if (n < 0) {
		printf("Your number is < 0, please input integer from 0 to 100 next time.\n");
		exit(0);
	}
	// check that n is <= 100, if not, print error message and exit program
	else if (n > 100) {
		printf("Your number is > 100, please input integer from 0 to 100 next time.\n");
		exit(0);
	}

	// Allocate memory for array of ints to store values from 0 to n
	unsigned int num_vals = n+1;
	int *intarr = (int*) malloc(num_vals * sizeof(int));

	// Use for loop to populate intarr from big to small
	for (unsigned int i=0; i<=n; i++){
		intarr[i] = n - i;
	}

	// sort intarr from smallest to largest int using qsort
	qsort(intarr, num_vals, sizeof(int), int_comp);

	// call outputT5 to print out the array
	outputT5(intarr, num_vals);
	printf("\n");

	// free up memory
	free(intarr);

	return 0;
}
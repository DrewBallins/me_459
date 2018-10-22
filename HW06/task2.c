// ME 459 HW06 task2
// Author: Andrew Wild
// This c program 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "output.h"

int main(int argc, char **argv) {
	clock_t start, end;		// initialize start and end values returned by clock function
	double cpu_time_used;	// initialize double for CPU time used

	start = clock();		// clock function used to find start time
	/* Do the work. */
	// Allocate memory for array of doubles to make matrix A
	unsigned int size_A = 1000000;
	double *A = (double*) malloc(size_A * sizeof(double));

	// Pass dynamically-allocated array to randomT2 function to fill it with random numbers
	randomT2(A);

	double b[1000];			// initialize array of 1000 doubles b
	b[0] = 0.5;				// initialize first value of b
	
	// populate the rest of array b with values alternating from 0.5 to -0.5
	for(int j=1; j<1000; j++) {
		if(b[j-1] == 0.5) {
			b[j] = -0.5;
		}
		else {
			b[j] = 0.5;
		}
	}

	double c[1000];			// create array c to store solution of A*b

	// multiplying A*b and placing values in c vector
	for(int k=0; k<1000; k++) {
		for(int l=0; l<1000; l++) {
			c[k] = c[k] + A[k*1000 + l]*b[l];
		}
	}

	free(A);				// free up dynamically allocated memory for matrix A

	// calculating the norm-two of vector c
	double sum_c2 = 0;		// intializing sum of vector c^2 as a double
	
	for(int m=0; m<1000; m++) {
		sum_c2 = sum_c2 + pow(c[m], 2);
	}

	double norm_c = sqrt(sum_c2);	// calculate the norm-two of vector c

	end = clock();			// clock function used to find end time
	
	// calculate the CPU time used during the program execution
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

	// Finally, pass the norm-two of vector c and the CPU time used to outputT2 function
	outputT2(norm_c, cpu_time_used);

	return 0;
}
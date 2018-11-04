// ME 459 HW07 task2
// Author: Andrew Wild
// This c program calls function randomT2 to make a random nxn matrix A and multiplies
// it by a length n vector b to create a vector c. It then finds the norm-two of this
// vector c and also clocks the calculation time required to run the program.

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
	// check input for validity and set it to a const char pointer
	if( argc == 2 ) {
    	// n is the 'size' of matrix A
    	unsigned int n = atoi(argv[1]);
    	
    	// size_A is the size of array A, which is an n x n matrix
    	unsigned int size_A = n*n;

    	// Allocate memory for array of doubles to make matrix A
		double *A = malloc(size_A * sizeof(double));
		
		// Pass dynamically-allocated array to randomT2 function to fill it with random numbers
		randomT2(A, n);

		double b[n];			// initialize array of size_A doubles b
		b[0] = 0.5;				// initialize first value of b
	
		// populate the rest of array b with values alternating from 0.5 to -0.5
		for(int j=1; j<n; j++) {
			if(b[j-1] == 0.5) {
				b[j] = -0.5;
			}
			else {
				b[j] = 0.5;
			}
		}

		double c[n];			// create array c to store solution of A*b

		// multiplying A*b row-wise and placing values in c vector
		for(int k=0; k<n; k++) {
			for(int l=0; l<n; l++) {
				c[k] = c[k] + A[k*n + l]*b[l];
			}
		}

		free(A);				// free up dynamically allocated memory for matrix A

		// calculating the norm-two of vector c
		double sum_c2 = 0;		// intializing sum of vector c^2 as a double
	
		for(int m=0; m<n; m++) {
			sum_c2 = sum_c2 + pow(c[m], 2);
		}

		double norm_c = sqrt(sum_c2);	// calculate the norm-two of vector c

		end = clock();			// clock function used to find end time

		// calculate the CPU time used during the program execution
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

		// Finally, pass the norm-two of vector c and the CPU time used to outputT2 function
		outputT2(norm_c, cpu_time_used);
    }
    else {
    	printf("Improper input, please enter a positive integer n for square matrix size.\n");
    	exit(0);
    }

	return 0;
}
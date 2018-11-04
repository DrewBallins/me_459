/* Author: Nic Olsen */
// Edited by Andrew Wild for HW07 Task 2

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "output.h"

int main(int argc, char* argv[]) {

    // check input for validity and set it to an unsigned int DIM
    if( argc == 2 ) {
        clock_t start, end;     // initialize start and end values returned by clock function
        double cpu_time_used;   // initialize double for CPU time used

        start = clock();        // clock function used to find start time
        /* Do the work. */

        // n is the 'size' of matrix A
        unsigned int DIM = atoi(argv[1]);

        // Allocate dynamic memory
        double* A = malloc(sizeof(double) * DIM * DIM);
        double* b = malloc(sizeof(double) * DIM);
        double* c = calloc(DIM, sizeof(double));

        // Check for successful allocation
        if (!(A && b && c)) {
            printf("Error allocating memory\n");
            return 1;
        }

        // Initialize A
        randomT2(A, DIM);

        // Initialize b
        for (size_t i = 0; i < DIM; i++) {
            if (i % 2 == 0) {
                b[i] = 0.5;
            } else {
                b[i] = -0.5;
            }
        }

        // Multiply: c = Ab
        for (size_t i = 0; i < DIM; i++) {
            for (size_t j = 0; j < DIM; j++) {
                c[i] += A[i * DIM + j] * b[j];
            }
        }

        // Get norm2 of c
        double normc = 0;
        for (size_t i = 0; i < DIM; i++) {
            normc += c[i] * c[i];
        }
        normc = sqrt(normc);

        end = clock();          // clock function used to find end time
    
        // calculate the CPU time used during the program execution
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

        // Output norm and time
        outputT2(normc, cpu_time_used);

        // Free dynamic memory
        free(A);
        free(b);
        free(c);
    }
    else {
        printf("Improper input, please enter a positive integer n for square matrix size.\n");
        exit(0);
    }

    return 0;
}
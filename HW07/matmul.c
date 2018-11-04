/* Author: Nic Olsen */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "output.h"

#define DIM 1000

int main(int argc, char* argv[]) {
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
    randomT2(A);

    // Initialize b
    for (size_t i = 0; i < DIM; i++) {
        if (i % 2 == 0) {
            b[i] = 0.5;
        } else {
            b[i] = -0.5;
        }
    }

    // Start timer
    clock_t start = clock();

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

    // Stop timer
    clock_t end = clock();
    clock_t total_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Output norm and time
    outputT2(normc, total_time);

    // Free dynamic memory
    free(A);
    free(b);
    free(c);

    return 0;
}
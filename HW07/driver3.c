// Author: Nic Olsen

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("usage: ./driver3 <num_elements>\n");
        return 1;
    }

    int count = atoi(argv[1]);
    if (count <= 0) {
        printf("num_elements must be positive\n");
        return 1;
    }

    int* arr = (int*)malloc(count * sizeof(int));

    for (int i = 0; i < count; i++) {
        arr[i] = rand() % 100000 + 1;
        // printf("%d\n", arr[i]);
    }

    clock_t start, end;     // initialize start and end values returned by clock function
    double cpu_time_used;   // initialize double for CPU time used
    start = clock();        // clock function used to find start time

    Sort(arr, count);

    end = clock();          // clock function used to find end time
    // calculate the CPU time used during the program execution
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Output the elapsed time of the sorting algorithm
    printf("elapsed time: %f ms\n", cpu_time_used);    

    if (VerifySorted(arr, count)) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }

    free(arr);
    return 0;
}
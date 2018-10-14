// ME 459 HW05 sort
// Author: Andrew Wild
// This c program implements bubble sort to sort the elemnts of an array in ascending order

#include <stdio.h>
#include "sort.h"

void Sort(int* arr, int count) {
	// cast for loop counters i, j
	int i, j;
	// for loop for iteration through all ints in arr
	for (i=0; i<count-1; i++) {
		// loop through every int in arr from starting int j to end of arr 
		// to verify that j is smaller than every following int
		for (j=0; j<count-i-1; j++) {
			// check to see whether sorting of adjacent elements is required
			if (arr[j] > arr[j+1]) {
				// swap adjacent elements when needed
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}




/* Author: Andrew Wild
   ME 459: HW09 task2
   Due by: 11/29/2018 */

#include <stdlib.h>
#include <math.h>

#include "math_utils.h"

// Returns the sum of all entries in arr
// NOTE: Uses a normal for loop, adding one value at each iteration to an accumulator
float Sum(float* arr, size_t count) {
	double acc = 0;				// Initialize and declare the accumulator

	// Iterate through every value in the array 'arr'
	for(unsigned int i=0;i<count;i++) {
		acc += arr[i];			// sum the array
	}

	return acc;					// Return the value of the accumulator
}


// Return the sum of the sine of each entry in arr
// NOTE: Uses a normal for loop, adding one sine value at each iteration to an accumulator
float SumSines(float* arr, size_t count) {
	double sin_acc = 0;			// Initialize and declare the sine accumulator

	// Iterate through every value in the array 'arr'
	for(unsigned int i=0;i<count;i++) {
		sin_acc += sin(arr[i]);	// sum the sines of the array
	}

	return sin_acc;				// Return the value of the accumulator
}

// Returns the sum of entries in arr in r_sum and the sum of the sines of the
// entries in arr in r_sum_sines
// NOTE: There should only be a single for loop in this function, which calculates
// both quantities
float Fusion(float* arr, size_t count, float* r_sum, float* r_sum_sines) {
	*r_sum = 0;			// initialize the r_sum value
	*r_sum_sines = 0;	// initialize the r_sum_sines value

	// Iterate through every value in the array 'arr'
	for(unsigned int i=0;i<count;i++) {
		*r_sum += arr[i];			// add to the r_sum value
		*r_sum_sines += sin(arr[i]);	// add to the r_sum_sines value
	}
}

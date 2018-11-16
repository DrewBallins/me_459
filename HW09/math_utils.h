/*Author: Nic Olsen*/
#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include <stdlib.h>

// Returns the sum of all entries in arr
// NOTE: Uses a normal for loop, adding one value at each iteration to an accumulator
float Sum(float* arr, size_t count);


// Return the sum of the sine of each entry in arr
// NOTE: Uses a normal for loop, adding one sine value at each iteration to an accumulator
float SumSines(float* arr, size_t count);

// Returns the sum of entries in arr in r_sum and the sum of the sines of the
// entries in arr in r_sum_sines
// NOTE: There should only be a single for loop in this function, which calculates
// both quantities
float Fusion(float* arr, size_t count, float* r_sum, float* r_sum_sines);

#endif
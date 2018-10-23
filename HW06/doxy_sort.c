 
// ME 459 HW05 sort.c
/*! \author Andrew Wild
*/
//, This c file implements a bubble sort function to 
//, sort the elements of an array in ascending order


#include <stdio.h>
#include "sort.h"

/*! \brief This function is an implementation of the common bubble sort method, which sorts a given array in ascending order.
 * 
 * This bubble sort function takes a pointer to an integer array 'arr' and a 'count'
 * of the length of said array for use in iteration through the whole array.
 * It loops through every integer in the array in multiple passes and swaps
 * two adjacent ints if the j+1 int is higher than the j int. This continues
 * until no swaps are needed, at which point the list is sorted in ascending order.
 * 
 * \param arr    A pointer to an integer array
 * \param count    The length of the given array 'arr'
 */
void Sort(int* arr, int count) {
	//, cast for loop counters i, j
	int i, j;
	//, for loop for iteration through all ints in arr
	for (i=0; i<count-1; i++) {
		//, loop through every int in arr from starting int j to end of arr 
		//, to verify that j is smaller than every following int
		for (j=0; j<count-i-1; j++) {
			//, check to see whether sorting of adjacent elements is required
			if (arr[j] > arr[j+1]) {
				//, swap adjacent elements when needed
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}




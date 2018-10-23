/*! \author Nic Olsen
 *
 * \headerfile This header file simply defines the Sort and VerifySorted functions
 * with include guards to prevent double inclusion
 *
 */

#ifndef SORT_H
#define SORT_H

/*! Runs either bubble sort, merge sort, or insertion sort to sort
 * elements of arr into ascending order
 */
void Sort(int* arr, int count);

/*! Returns 1 if the given array is sorted, 0 else
 */
int VerifySorted(int* arr, int count);

#endif
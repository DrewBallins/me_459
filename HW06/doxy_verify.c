/*! \author Nic Olsen
*/

#include "sort.h"

/*! \brief This function verifies whether or not the Sort function worked properly
 *
 * VerifySorted takes a pointer to an array of integers and an int 'count'
 * which is the length of the array. It iterates through every int in the
 * array and if any element i is greater than its adjacent element i+1, it
 * returns 0, which means the Sort function failed to sort in ascending order.
 * If the array is sorted properly, this function will return 1
 */
int VerifySorted(int* arr, int count) {
    for (int i = 0; i < count - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    }
    return 1;
}
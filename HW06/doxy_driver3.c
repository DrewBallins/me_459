/*! \author Nic Olsen
*/

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/*! The main program which calls sort.c and verifies proper sorting operation.
 *
 * This program starts by taking a command line argument 'n', which is
 * the size of the array to be sorted. It then dynamically allocates memory
 * for this array, then populates it with integers from 0 to n in random
 * order. Finally, it calls the Sort function from sort.c, and then verifies
 * whether or not it worked properly, printing 'PASS' if it did and 'FAIL' if not.
 */
int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("usage: ./driver2 <num_elements>\n");
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
        //, printf("%d\n", arr[i]);
    }

    Sort(arr, count);

    if (VerifySorted(arr, count)) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }

    free(arr);
    return 0;
}
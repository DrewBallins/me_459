// Author: Nic Olsen

#include "sort.h"

int VerifySorted(int* arr, int count) {
    for (int i = 0; i < count - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    }
    return 1;
}
// Author: Nic Olsen

#include <stdio.h>
#include <stdlib.h>
#include "dll_alloc.h"
#include "structs.h"
#include "traversal.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("usage: ./driver1 <num_elements>\n");
        return 1;
    }

    int count = atoi(argv[1]);
    if (count <= 0) {
        printf("num_elements must be positive\n");
        return 1;
    }

    ListNode* head;
    CreateDLL(&head, count);

    printf("FORWARD\n");
    PrintDLLForward(head);

    printf("\n\nREVERSE\n");
    PrintDLLReverse(head);

    FreeDLL(head, count);
    return 0;
}
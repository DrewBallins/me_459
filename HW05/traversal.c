// ME 459 HW05 traversal
// Author: Andrew Wild
// This c file defines two functions PrintDLLForward and PrintDLLReverse
// which traverse forward and backward respectively through a DLL and
// print each data item contained in the DLL.

#include <stdio.h>
#include "structs.h"
#include "traversal.h"
#include "dll_alloc.h"

void PrintDLLForward(ListNode* head) {
	// first we define our current position starting at the head node
	ListNode *curr = head;
	// next create a temporary pointer for tracking the next node
	ListNode *next;

	// while loop to iterate through entirety of DLL starting at the head node
	while (next != head) {
		// save the next node for while loop reference
		next = curr->next;

		// print current data point in DLL
		printf("%d\n", curr->data);

		// move curr FORWARD to next position in DLL
		curr = curr->next;
	}
}

void PrintDLLReverse(ListNode* head) {
	// first we define our current position starting at the head node
	ListNode *curr = head;
	// next create a temporary pointer for tracking the previous node
	ListNode *prev;

	// while loop to iterate through entirety of DLL starting at the head node
	while (prev != head) {
		// save the previous node for while loop reference
		prev = curr->prev;

		// print current data point in DLL
		printf("%d\n", curr->data);

		// move curr REVERSE to previous position in DLL
		curr = curr->prev;
	}
}
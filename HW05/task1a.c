// ME 459 HW05 task1a
// Author: Andrew Wild
// This c program prints out the size of structures A and B

#include <stdio.h>
#include "structs.h"

int main() {
	// print out size of struct A using sizeof()
	printf("Struct A is of size: %d\n", sizeof(struct A));
	// print out size of struct A using sizeof()
	printf("Struct B is of size: %d\n", sizeof(struct B));

	return 0;
}
/* Author: Andrew Wild
   ME 459: HW 10 task 1b
   Due: 12/09/2018 */
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main() {
	int sz = INT_MIN;	// minimum value int that can be stored
	int sz2 = sz - 1;	// 1 value smaller than min value int

	// display these two values
	printf("Minimum value int = %d\n", sz);
	printf("Minimum value int - 1 = %d\n", sz2);

	return 0;
}
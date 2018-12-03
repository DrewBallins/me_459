/* Author: Andrew Wild
   ME 459: HW 10 task 1a
   Due: 12/09/2018 */
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main() {
	int sz = INT_MAX;	// maximum value int that can be stored
	int sz2 = sz + 1;	// 1 value greater than max value int

	// display these two values
	printf("Maximum value int = %d\n", sz);
	printf("Maximum value int + 1 = %d\n", sz2);

	return 0;
}
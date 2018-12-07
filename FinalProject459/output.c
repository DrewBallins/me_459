/*Author: Andrew Wild*/
#include <stdio.h>
#include <stdlib.h>

#include "output.h"
#include "collide.h"

// Outputs sphere-triangle collision pairs
void data_out(pair *p, size_t n, FILE *f) {
	fprintf(f, "s,t\n");				// print first line of file

	// print sphere and triangle ID's of all collided pairs
	for (size_t k = 0; k < n; k++) {
		fprintf(f, "%d,%d\n", p[k].s, p[k].t);
	}
}
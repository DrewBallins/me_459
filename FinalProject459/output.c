/*! \author Andrew Wild 
*/

#include <stdio.h>
#include <stdlib.h>

#include "output.h"
#include "collide.h"

/*! Outputs sphere-triangle collision pairs 
 *
 * This function takes the created collision_detection.out file as f, the
 * number of collisions n and the collided pairs list p and prints the
 * first line of the file s,t followed by every subsequent line which 
 * contain the sphere and triangle ID's of each collided pair.
*/
void data_out(pair *p, size_t n, FILE *f) {
	fprintf(f, "s,t\n");				// print first line of file

	// print sphere and triangle ID's of all collided pairs
	for (size_t k = 0; k < n; k++) {
		fprintf(f, "%zu,%zu\n", p[k].s, p[k].t);
	}
}
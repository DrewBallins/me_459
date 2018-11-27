/*Author: Andrew Wild*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mesh.h"

int main() {

	unsigned int num_t;					// initialize int for number of triangles
	double coord;						// initialize temporary double used for coordinates

	FILE *f_mesh;				// cast file
	f_mesh = fopen("mesh.input","r");	// open mesh.input file for reading
	fscanf(f_mesh, "%d", &num_t);		// Read in number of triangles
	triangle *mesh = malloc(sizeof(triangle) * num_t)

    return 0;
}
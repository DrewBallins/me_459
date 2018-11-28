/*Author: Andrew Wild*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mesh.h"

int main() {

	unsigned int num_t;					// initialize int for number of triangles

	FILE *f_mesh;						// cast file
	f_mesh = fopen("mesh.input","r");	// open mesh.input file for reading
	fscanf(f_mesh, "%d", &num_t);		// Read in number of triangles
	triangle *mesh = malloc(sizeof(triangle) * num_t);	// dynamically allocate memory for mesh

	read_mesh(mesh, f_mesh);			// call function to read mesh.input and populate mesh array of triangles

	fclose(f_mesh);
	free(mesh);
    return 0;
}
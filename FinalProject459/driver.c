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

	printf("Triangle 1 x1 = %f\n", mesh[0].x1);
	printf("Triangle 1 y1 = %f\n", mesh[0].y1);
	printf("Triangle 1 z1 = %f\n", mesh[0].z1);
	printf("Triangle 1 x2 = %f\n", mesh[0].x2);
	printf("Triangle 1 y2 = %f\n", mesh[0].y2);
	printf("Triangle 1 z2 = %f\n", mesh[0].z2);
	printf("Triangle 1 x3 = %f\n", mesh[0].x3);
	printf("Triangle 1 y3 = %f\n", mesh[0].y3);
	printf("Triangle 1 z3 = %f\n", mesh[0].z3);
	printf("Triangle 1 x1 = %f\n", mesh[1].x1);
	printf("Triangle 1 y1 = %f\n", mesh[1].y1);
	printf("Triangle 1 z1 = %f\n", mesh[1].z1);
	printf("Triangle 1 x2 = %f\n", mesh[1].x2);
	printf("Triangle 1 y2 = %f\n", mesh[1].y2);
	printf("Triangle 1 z2 = %f\n", mesh[1].z2);
	printf("Triangle 1 x3 = %f\n", mesh[1].x3);
	printf("Triangle 1 y3 = %f\n", mesh[1].y3);
	printf("Triangle 1 z3 = %f\n", mesh[1].z3);

	free(mesh);
    return 0;
}
/*Author: Andrew Wild*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mesh.h"
#include "spheres.h"

int main() {

	unsigned int num_t;					// initialize int for number of triangles
	unsigned long int num_s;			// pointer to number of spheres
	double r;							// radius of sphere


	FILE *f_mesh;						// cast file mesh.input
	FILE *f_spheres;						// cast file spheres.input
	f_mesh = fopen("mesh.input","r");	// open mesh.input file for reading
	fscanf(f_mesh, "%d", &num_t);		// Read in number of triangles
	triangle *mesh = malloc(sizeof(triangle) * num_t);	// dynamically allocate memory for mesh

	read_mesh(mesh, f_mesh);			// call function to read mesh.input and populate mesh array of triangles

	fclose(f_mesh);

	f_spheres = fopen("spheres.input.csv","r");	// open spheres.input file for reading

	read_sphere_data(f_spheres, &r, &num_s);

	printf("num_s = %d\n", num_s);
	printf("radius = %f\n", r);

	sphere *spheres = malloc(sizeof(sphere) * num_s);	// dynamically allocate memory for spheres

	read_spheres(spheres, f_spheres);

	printf("Sphere %d coord x = %f\n", 0, spheres[0].x);
	printf("Sphere %d coord x = %f\n", 1, spheres[1].x);

	free(mesh);
	free(spheres);
    return 0;
}
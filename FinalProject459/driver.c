/*Author: Andrew Wild*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mesh.h"
#include "spheres.h"
#include "collide.h"

int main() {

	size_t num_t;						// initialize int for number of triangles
	unsigned long int num_s;			// pointer to number of spheres
	double r;							// radius of sphere
	size_t n_collisions;					// number of collisions
	FILE *f_mesh;						// cast file mesh.input
	FILE *f_spheres;					// cast file spheres.input

	f_mesh = fopen("mesh.input","r");	// open mesh.input file for reading
	fscanf(f_mesh, "%d", &num_t);		// Read in number of triangles
	triangle *mesh = malloc(sizeof(triangle) * num_t);	// dynamically allocate memory for mesh

	// call function to read mesh.input and populate mesh array of triangle coordinates
	read_mesh(mesh, f_mesh);			

	fclose(f_mesh);						// close mesh.input file

	// open spheres.input.csv file for reading
	f_spheres = fopen("spheres.input.csv","r");

	read_sphere_data(f_spheres, &r, &num_s);	// call function to find r & num_s from file
	sphere *spheres = malloc(sizeof(sphere) * num_s);	// dynamically allocate memory for spheres

	// call function to read spheres.input.csv and populate spheres array of sphere coordinates
	read_spheres(spheres, f_spheres);

	fclose(f_spheres);					// close spheres.input.csv file

	pair *pairs = malloc(sizeof(pair) * num_s);	// Initialize pairs array, will realloc inside collide_all function

	/*
	Call collision function and then output function
	*/

	n_collisions = collide_all(r, spheres, mesh, pairs, num_s, num_t);
	printf("Number of collisions = %d\n", n_collisions);
	printf("Collision pair 0 = %d, %d\n", pairs[0].s, pairs[0].t);
	printf("Collision pair 1 = %d, %d\n", pairs[1].s, pairs[1].t);
	printf("Collision pair 2 = %d, %d\n", pairs[2].s, pairs[2].t);


	free(mesh);							// free mesh dynamic memory
	free(spheres);						// free sphere dynamic memory
	free(pairs);						// free collision pairs memory

    return 0;
}
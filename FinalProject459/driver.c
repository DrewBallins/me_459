/*! \author Andrew Wild 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mesh.h"
#include "spheres.h"
#include "collide.h"

/*! Main program calls the necessary functions along with other operations
 *
 * This program first initializes the necessary variables, then reads in the
 * mesh using read_mesh(), followed by the spheres using first read_sphere_data()
 * followed by read_spheres(). The collide_all() function is called and timed
 * for collision detection, followed by finally calling the data_out() function.
 */
int main() {
	size_t num_t;						// initialize int for number of triangles
	unsigned long int num_s;			// pointer to number of spheres
	double r;							// radius of sphere
	size_t n_collisions;				// number of collisions
	FILE *f_mesh;						// cast file mesh.input
	FILE *f_spheres;					// cast file spheres.input
	FILE *f_out;						// cast file collision_detection.out

	// open mesh file for reading, allocate memory for mesh array then read in mesh using read_mesh file
	f_mesh = fopen("mesh.input","r");
	fscanf(f_mesh, "%zu", &num_t);
	triangle *mesh = malloc(sizeof(triangle) * num_t);
	read_mesh(mesh, f_mesh);			
	fclose(f_mesh);

	// open spheres.input file for reading
	f_spheres = fopen("spheres.input","r");
	read_sphere_data(f_spheres, &r, &num_s);			// call function to find r & num_s from file
	sphere *spheres = malloc(sizeof(sphere) * num_s);	// dynamically allocate memory for spheres

	// call function to read spheres.input and populate spheres array of sphere coordinates
	read_spheres(spheres, f_spheres);
	fclose(f_spheres);

	// Create collision_detection.out file and print first line
	f_out = fopen("collision_detection.out","w");
	fprintf(f_out, "s,t\n");

	// call collide function and time collision detection
	clock_t start = clock();
	n_collisions = collide_all(r, spheres, mesh, num_s, num_t, f_out);
	clock_t end = clock();
	const double s2ms = 1000.0;
	double total_time = ((double)(end - start)) / CLOCKS_PER_SEC * s2ms;

	// close output file
	fclose(f_out);

	// print results
	printf("Total time [ms]: %0.8f\n", total_time);
	printf("Number of collisions = %zu\n", n_collisions);

	// free all dynamically allocated memory
	free(mesh);
	free(spheres);

    return 0;
}
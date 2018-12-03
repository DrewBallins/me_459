/* Author: Andrew Wild */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "collide.h"
#include "mesh.h"
#include "spheres.h"

// Returns the number of distinct pairs of collisions between distinct spheres 
// (all of radius r) and distinct triangles in the mesh
// ie Returns |{ {i,j}: i != j && sphere_i has non-negative overlap with triangle_i}|
size_t collide_all(double r, sphere* spheres, triangle* mesh, unsigned long int num_s, size_t num_t) {
	size_t n_collisions = 0;				// Declare and intialize number of collisions
	double radius_sum = 2*r; 				// Sum of the radii of each sphere




	return n_collisions;
}
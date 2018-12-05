/*Author: Andrew Wild*/
#ifndef COLLIDE_H
#define COLLIDE_H

#include "spheres.h"
#include "mesh.h"

typedef struct vector {
    double x;
    double y;
    double z;
} vector;

typedef struct pair {
	size_t s;
	size_t t;
} pair;

// Returns the number of distinct pairs of collisions between distinct spheres 
// (all of radius r) and distinct triangles in the mesh
// ie Returns |{ {i,j}: i != j && sphere_i has non-negative overlap with triangle_i}|
size_t collide_all(double r, sphere* spheres, triangle* mesh, pair* pairs, unsigned long int num_s, size_t num_t);

#endif
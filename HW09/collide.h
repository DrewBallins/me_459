/*Author: Nic Olsen*/
#ifndef COLLIDE_H
#define COLLIDE_H

#include "generator.h"

// Returns the number of distinct pairs of distinct spheres (all of radius r)
// which have non-negative overlap
// ie Returns |{ {i,j}: i != j && sphere_i has non-negative overlap with sphere_j}|
unsigned int collide_all_spheres(double r, point* pts, unsigned int n_points);

#endif
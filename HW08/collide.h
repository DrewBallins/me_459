/*Author: Nic Olsen*/
#ifndef COLLIDE_H
#define COLLIDE_H

#include "generator.h"

// Returns the number of spheres with position pts[i] of radius r which have non-negative
// overlap with the sphere of radius r centered at a.
unsigned int collide_single_sphere(point a, double r, point *pts, unsigned int n_points);

#endif
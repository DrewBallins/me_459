/* Author: Andrew Wild
   ME 459: HW08 task2
   Due by: 11/15/2018 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "collide.h"
#include "generator.h"

// Returns the number of spheres with position pts[i] of radius r which have non-negative
// overlap with the sphere of radius r centered at a.
unsigned int collide_single_sphere(point a, double r, point *pts, unsigned int n_points) {
	unsigned int n_collisions = 0;				// Declare and intialize number of collisions
	double radius_sum = 2*r; 					// Sum of the radii of each sphere
	
	// Iterate through all points to look for collisions
	for(unsigned int i=0; i<n_points; i++) {
		// Find distance in x, y and z between center points
		double diff_x = a.x - pts[i].x;
		double diff_y = a.y - pts[i].y;
		double diff_z = a.z - pts[i].z;

		// Now calculate the total distance between center points of two spheres
		double dist = sqrt(diff_x*diff_x + diff_y*diff_y + diff_z*diff_z);

		// Finally, check whether spheres intersect, which occurs if dist <= radius_sum
		if(dist <= radius_sum) {
			n_collisions += 1;					// if int detected, count collision
		}
	}

	return n_collisions;						// return the number of collisions
}

/* Author: Andrew Wild
   ME 459: HW09 task1
   Due by: 11/29/2018 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "collide.h"
#include "generator.h"

// Returns the number of distinct pairs of distinct spheres (all of radius r)
// which have non-negative overlap
// ie Returns |{ {i,j}: i != j && sphere_i has non-negative overlap with sphere_j}|
unsigned int collide_all_spheres(double r, point* pts, unsigned int n_points) {
	unsigned int n_collisions = 0;				// Declare and intialize number of collisions
	double radius_sum = 2*r; 					// Sum of the radii of each sphere
	unsigned int k = 0;							// Create counter k to eliminate double counts

	// Iterate through all spheres to look for collisions
	for(unsigned int i=0; i<n_points; i++) {
		// For each individual sphere, check for collision with every other sphere in space
		for(unsigned int j=0+k; j<n_points; j++) {
			if(i != j){
				// Find distance in x, y and z between center points
				double diff_x = pts[i].x - pts[j].x;
				double diff_y = pts[i].y - pts[j].y;
				double diff_z = pts[i].z - pts[j].z;
				
				// Now calculate the total distance between center points of two spheres
				double dist = sqrt(diff_x*diff_x + diff_y*diff_y + diff_z*diff_z);

				// Finally, check whether spheres intersect, which occurs if dist <= radius_sum
				if(dist <= radius_sum) {
					n_collisions += 1;					// if intersect detected, count collision
				}
			}
		}
		k += 1;		// start second loop 1 sphere later to avoid double counting distinct pairs
	}

	return n_collisions;						// return the number of collisions
}
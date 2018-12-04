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
	size_t n_collisions = 0;	// Declare and intialize number of collisions
	vector E1;					// initialize triangle edge 1
	vector E2;					// initialize triangle edge 2
	vector k_diff;				// initialize distance from sphere center to known point on triangle plane
	vector norm;				// initialize normal vector from triangle plane
	double dist; 				// initialize dist dot product
	double ndot;				// initialize normal vector dot product


	/* 
	we need to first check whether the distance from the sphere center to the closest point in the
	plane which contains a specific triangle is less than the radius of the sphere. If it is, then 
	a collision is possible, and we then need to check whether this closest point is contained in 
	the triangle, if it is then there IS an intersection. Finally we must test to see if any edge 
	of the triangle intersects the sphere.
	*/


	for(size_t i=0; i < num_s; i++) {
		for(size_t j=0; j < num_t; j++) {
			// define edges E1 & E2 of triangle to define triangle plane
			E1.x = (mesh[j].x2 - mesh[j].x1);
			E1.y = (mesh[j].y2 - mesh[j].y1);
			E1.z = (mesh[j].z2 - mesh[j].z1);
			E2.x = (mesh[j].x3 - mesh[j].x1);
			E2.y = (mesh[j].y3 - mesh[j].y1);
			E2.z = (mesh[j].z3 - mesh[j].z1);

			// define distance from sphere center to given triangle plane point (arbitrarily chose triangle vertex 1)
			k_diff.x = (mesh[j].x1 - spheres[i].x);
			k_diff.y = (mesh[j].y1 - spheres[i].y);
			k_diff.z = (mesh[j].z1 - spheres[i].z);
			
			// normal vector from plane norm = E1 x E2 (cross product)
			norm.x = E1.y*E2.z - E2.y*E1.z;
			norm.y = E2.x*E1.z - E1.x*E2.z;
			norm.z = E1.x*E2.y - E2.x*E1.y;

			// dist = norm * k_diff (dot product)
			dist = norm.x*k_diff.x + norm.y*k_diff.y + norm.z*k_diff.z;

			// ndot = norm * norm (dot product)
			ndot = norm.x*norm.x + norm.y*norm.y + norm.z*norm.z;

			// test if collision is possible by checking point to plane distance
			// NOTE: avoided division (dist*dist/ndot) to make code faster
			if ((dist*dist) < (r*r*ndot)) {
				// run further tests to determine whether closest point is actually contained
				// in triangle, or within edge of triangle. For now, I just add 1 to n_collisions
				n_collisions += 1;
			}
		}
	}

	return n_collisions;
}
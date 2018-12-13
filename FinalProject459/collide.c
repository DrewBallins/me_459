/*! \author Andrew Wild 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "collide.h"
#include "mesh.h"
#include "spheres.h"

/*! Returns the number of sphere-triangle collisions, and prints out the ID's of every collided pair in the order they were read in to file
 *
 * This code works by first checking whether the distance from the sphere center to the closest point in the
 * plane which contains a specific triangle is less than the radius of the sphere. If it is, then 
 * a collision is possible, and we then need to check whether this closest point is contained in 
 * the triangle, if it is then there IS an intersection. Finally we must test to see if any edge 
 * of the triangle intersects the sphere. When an intersection is detected, the ID's of the sphere
 * and triangle are printed out to the collision_detection.out file.
*/
size_t collide_all(double r, sphere* spheres, triangle* mesh, unsigned long int num_s, size_t num_t, FILE *f) {
	size_t n_collisions = 0;	// Declare and intialize number of collisions
	vector E1;					// initialize triangle edge 1
	vector E1s;					// initialize triangle edge 1 cross product
	vector E2;					// initialize triangle edge 2
	vector E2s;					// initialize triangle edge 2 cross product
	vector E3;					// initialize triangle edge 3
	vector E3s;					// initialize triangle edge 3 cross product
	vector s_dist;				// initialize distance from sphere center to triangle vertex 1
	vector s_dist2;				// initialize distance from sphere center to triangle vertex 2
	vector norm;				// initialize normal vector from triangle plane
	double gamma;				// initialize barycentric coordinate gamma
	double beta;				// initialize barycentric coordinate beta
	double alpha;				// initialize barycentric coordinate alpha
	double dist; 				// initialize dist dot product
	double ndot;				// initialize normal vector dot product
	double E1dot; 				// initialize E1*E1
	double E2dot; 				// initialize E2*E2
	double E3dot; 				// initialize E3*E3
	double E1sdot; 				// initialize E1s*E1s
	double E2sdot; 				// initialize E2s*E2s
	double E3sdot; 				// initialize E3s*E3s
	double t_star[3];			// initialize array of barycentric multipliers t*
	vector Etstar[3];
	vector Et_dist[3];
	double Etd_dot[3];

	// iterate through all spheres and triangles
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
			s_dist.x = (spheres[i].x - mesh[j].x1);
			s_dist.y = (spheres[i].y - mesh[j].y1);
			s_dist.z = (spheres[i].z - mesh[j].z1);
			
			// normal vector from plane norm = E1 x E2 (cross product)
			norm.x = E1.y*E2.z - E2.y*E1.z;
			norm.y = E2.x*E1.z - E1.x*E2.z;
			norm.z = E1.x*E2.y - E2.x*E1.y;

			// dist = norm * s_dist (dot product)
			dist = norm.x*s_dist.x + norm.y*s_dist.y + norm.z*s_dist.z;

			// ndot = norm * norm (dot product)
			ndot = norm.x*norm.x + norm.y*norm.y + norm.z*norm.z;

			// test if collision is possible by checking point to plane distance
			// NOTE: avoided division (dist*dist/ndot) to make code faster
			if ((dist*dist) < (r*r*ndot)) {
				/* run further tests to determine whether closest point is actually contained
				in triangle, or within edge of triangle. */
				// define edge 3 of the triangle
				E3.x = (mesh[j].x3 - mesh[j].x2);
				E3.y = (mesh[j].y3 - mesh[j].y2);
				E3.z = (mesh[j].z3 - mesh[j].z2);

				// define distance from sphere center to vertex 2 of the triangle
				s_dist2.x = (spheres[i].x - mesh[j].x2);
				s_dist2.y = (spheres[i].y - mesh[j].y2);
				s_dist2.z = (spheres[i].z - mesh[j].z2);

				// cross product of edge 1 and sphere to vertex one distance
				E1s.x = E1.y*s_dist.z - s_dist.y*E1.z;
				E1s.y = s_dist.x*E1.z - E1.x*s_dist.z;
				E1s.z = E1.x*s_dist.y - s_dist.x*E1.y;

				// cross product of sphere to vertex one distance and edge 2
				E2s.x = s_dist.y*E2.z - E2.y*s_dist.z;
				E2s.y = E2.x*s_dist.z - s_dist.x*E2.z;
				E2s.z = s_dist.x*E2.y - E2.x*s_dist.y;

				// cross product of edge 3 and sphere to vertex two distance
				E3s.x = E3.y*s_dist2.z - s_dist2.y*E3.z;
				E3s.y = s_dist2.x*E3.z - E3.x*s_dist2.z;
				E3s.z = E3.x*s_dist2.y - s_dist2.x*E3.y;

				// define all dot products
				E1dot = E1.x*E1.x + E1.y*E1.y + E1.z*E1.z;
				E2dot = E2.x*E2.x + E2.y*E2.y + E2.z*E2.z;
				E3dot = E3.x*E3.x + E3.y*E3.y + E3.z*E3.z;
				E1sdot = E1s.x*E1s.x + E1s.y*E1s.y + E1s.z*E1s.z;
				E2sdot = E2s.x*E2s.x + E2s.y*E2s.y + E2s.z*E2s.z;
				E3sdot = E3s.x*E3s.x + E3s.y*E3s.y + E3s.z*E3s.z;

				// calculate barycentric coordinates of triangle 
				gamma = (((E1s.x)*norm.x) + ((E1s.y)*norm.y) + ((E1s.z)*norm.z))/ndot;
				beta = (((E2s.x)*norm.x) + ((E2s.y)*norm.y) + ((E2s.z)*norm.z))/ndot;
				alpha = 1 - gamma - beta;

				// Calculated barycentric multipliers t_star for all three triangle edges
				t_star[0] = (E1sdot/E1dot > 0 ? E1sdot/E1dot : 0) < 1 ? (E1sdot/E1dot > 0 ? E1sdot/E1dot : 0) : 1;
				t_star[1] = (E2sdot/E2dot > 0 ? E2sdot/E2dot : 0) < 1 ? (E2sdot/E2dot > 0 ? E2sdot/E2dot : 0) : 1;
				t_star[2] = (E3sdot/E3dot > 0 ? E3sdot/E3dot : 0) < 1 ? (E3sdot/E3dot > 0 ? E3sdot/E3dot : 0) : 1;

				// Calculate distance squared between each triangle edge and sphere center
				for (size_t m = 0; m < 3; m++) {
					Etstar[m].x = mesh[j].x1 + t_star[m]*E1.x;
					Etstar[m].y = mesh[j].y1 + t_star[m]*E1.y;
					Etstar[m].z = mesh[j].z1 + t_star[m]*E1.z;
					Et_dist[m].x = Etstar[m].x - spheres[i].x;
					Et_dist[m].y = Etstar[m].y - spheres[i].y;
					Et_dist[m].z = Etstar[m].z - spheres[i].z;
					Etd_dot[m] = Et_dist[m].x*Et_dist[m].x + Et_dist[m].y*Et_dist[m].y + Et_dist[m].z*Et_dist[m].z;
				}
				
				// check for edge collisions
				if (Etd_dot[0] < (r*r) || Etd_dot[1] < (r*r) || Etd_dot[2] < (r*r)) {
					n_collisions += 1;
					fprintf(f, "%zu,%zu\n", i, j);
				}

				// check for surface collsions
				else if (0 <= alpha && alpha <= 1 && 0 <= beta && beta <= 1 && 0 <= gamma && gamma <= 1) {
					n_collisions += 1;
					fprintf(f, "%zu,%zu\n", i, j);
				}
			}
		}
	}
	return n_collisions;
}
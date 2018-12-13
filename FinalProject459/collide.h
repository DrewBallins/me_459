/*! \author Andrew Wild 
*/

#ifndef COLLIDE_H
#define COLLIDE_H

#include "spheres.h"
#include "mesh.h"

//! Vector data structure contains x y and z values for a 3D vector
/*!
 * Contains doubles x, y & z which are the coordinates of a vector 
 * or in some cases a point in 3D space
 */
typedef struct vector {
    double x;
    double y;
    double z;
} vector;

/*! Returns the number of sphere-triangle collisions, and prints out the ID's of every collided pair in the order they were read in to file
 *
 * This code works by first checking whether the distance from the sphere center to the closest point in the
 * plane which contains a specific triangle is less than the radius of the sphere. If it is, then 
 * a collision is possible, and we then need to check whether this closest point is contained in 
 * the triangle, if it is then there IS an intersection. Finally we must test to see if any edge 
 * of the triangle intersects the sphere. When an intersection is detected, the ID's of the sphere
 * and triangle are printed out to the collision_detection.out file.
*/
size_t collide_all(double r, sphere* spheres, triangle* mesh, unsigned long int num_s, size_t num_t, FILE *f);

#endif
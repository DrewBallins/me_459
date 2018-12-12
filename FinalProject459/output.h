/*! \author Andrew Wild 
*/

#ifndef OUTPUT_H
#define OUTPUT_H

#include "collide.h"

/*! Outputs sphere-triangle collision pairs 
 *
 * This function takes the created collision_detection.out file as f, the
 * number of collisions n and the collided pairs list p and prints the
 * first line of the file s,t followed by every subsequent line which 
 * contain the sphere and triangle ID's of each collided pair.
*/
void data_out(pair *p, size_t n, FILE *f);

#endif
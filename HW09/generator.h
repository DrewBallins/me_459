/*Author: Nic Olsen*/
#ifndef GENERATOR_H
#define GENERATOR_H

typedef struct point {
    double x;
    double y;
    double z;
} point;

// Generates n points and stores them in the pts array
void generate_points(point* pts, unsigned int n);

#endif
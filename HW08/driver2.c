/*Author: Nic Olsen*/
#include <stdio.h>
#include <stdlib.h>

#include "collide.h"
#include "generator.h"

#define N 1000000
#define R 10.0

int main(int argc, char* argv[]) {
    // Generate the single special point
    point a;
    generate_points(&a, 1);

    // Generate array of points to check against point a
    point* pts = malloc(sizeof(point) * N);
    generate_points(pts, N);

    // Count collisions with point a
    unsigned int n_collisions = collide_single_sphere(a, R, pts, N);
    printf("Number of collisions: %u\n", n_collisions);

    return 0;
}
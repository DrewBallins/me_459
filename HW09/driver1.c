/*Author: Nic Olsen*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "collide.h"
#include "generator.h"

#define R 10.0

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <n_spheres>\n", argv[0]);
        return 1;
    }

    unsigned int n_spheres = atoi(argv[1]);

    point* pts = malloc(sizeof(point) * n_spheres);
    generate_points(pts, n_spheres);

    // Count collisions amongst the spheres
    clock_t start = clock();
    unsigned int n_collisions = collide_all_spheres(R, pts, n_spheres);
    clock_t end = clock();
    const double ms2s = 1000.0;
    double total_time = ((double)(end - start)) / CLOCKS_PER_SEC * ms2s;

    // Output results
    printf("Number of spheres: %u\n", n_spheres);
    printf("Number of collisions: %u\n", n_collisions);
    printf("Total time: %0.8f\n", total_time);

    free(pts);
    return 0;
}
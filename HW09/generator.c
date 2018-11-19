/*Author: Nic Olsen*/
#include <stdlib.h>
#include <time.h>

#include "generator.h"

void generate_points(point* pts, unsigned int n) {
    srand(time(NULL));
    for (unsigned int i = 0; i < n; i++) {
        pts[i].x = -100.0 + (double)rand() / ((double)RAND_MAX / 200.0 + 1.0);
        pts[i].y = -100.0 + (double)rand() / ((double)RAND_MAX / 200.0 + 1.0);
        pts[i].z = -100.0 + (double)rand() / ((double)RAND_MAX / 200.0 + 1.0);
    }
}
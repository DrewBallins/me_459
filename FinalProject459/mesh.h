/*Author: Andrew Wild*/
#ifndef MESH_H
#define MESH_H

typedef struct triangle {
    double x1;
    double y1;
    double z1;
    double x2;
    double y2;
    double z2;
    double x3;
    double y3;
    double z3;
} triangle;

// Reads mesh.input file and saves all triangles in mesh array
void read_mesh(triangle *mesh, FILE *f_mesh);

#endif
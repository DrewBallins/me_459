/*! \author Andrew Wild 
*/

#ifndef MESH_H
#define MESH_H

//! Triangle data struct which contains coordinates of all three vertices of a triangle
/*!
 * Contains doubles x1, x2, x3, y1, y2, y3, z1, z2 & z3, which are the x, y, z coordinates
 * of three vertices of a triangle in the mesh
 */
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

/*! Reads mesh.input file and saves all triangles in mesh array
 *
 * This function takes the opened mesh.input file and the array of
 * triangles called 'mesh' as inputs. It scans every line of the 
 * mesh.input file and populates the 'mesh' array with the coordinates
 * of each triangle vertex for every triangle in the mesh.
*/
void read_mesh(triangle *mesh, FILE *f_mesh);

#endif
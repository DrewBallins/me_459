/*! \author Andrew Wild 
*/

#ifndef SPHERES_H
#define SPHERES_H

//! Sphere data struct which contains coordinates of center point of a sphere
/*!
 * Contains doubles x, y & z which are the coordinates of the center of a 
 * given sphere in 3D space
 */
typedef struct sphere {
    double x;
    double y;
    double z;
} sphere;

/*! Reads spheres.input file for radius and num spheres
 *
 * This function takes the already opened spheres.input CSV file, 
 * a pointer to radius value r and a pointer to the number of spheres
 * num_s. It reads the first 3 lines of the spheres.input file and
 * saves the radius value to r and the number of spheres value to num_s
*/
void read_sphere_data(FILE *f_spheres, double *r, unsigned long int *num_s);

/*! Reads rest of spheres file and saves all sphere coordinates in array
 *
 * This function takes the dynamically allocated array of sphere center points
 * 'spheres' and the opened spheres.input file as input and scans the rest of
 * the file for all sphere center points coordinates. These coordinates are
 * saved in the 'spheres' array in the order they were read in.
*/
void read_spheres(sphere *spheres, FILE *f_spheres);

#endif
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

/*! Reads spheres.input.csv file for radius and num spheres*/
void read_sphere_data(FILE *f_spheres, double *r, unsigned long int *num_s);

/*! Reads rest of spheres.input.csv file and saves all spheres in array*/
void read_spheres(sphere *spheres, FILE *f_spheres);

#endif
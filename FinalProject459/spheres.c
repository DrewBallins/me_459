/*Author: Andrew Wild*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "spheres.h"

// Reads spheres.input.csv file for radius and num spheres
void read_sphere_data(FILE *f_spheres, double *r, unsigned long int *num_s) {
	char *line = NULL;	// intialize line pointer for getline()
	char *ptr;			// initialize endchar: ptr for strtod & strtoul
   	size_t len = 0;		// initialize len pointer for getline()
   	ssize_t nread;		// initialize nread for getline() loop
   	size_t i = 0;		// initialize counter j for sphere data loop

   	// Sphere data loop
	while ((nread = getline(&line, &len, f_spheres)) != -1) {
		if(i==0) {
			i += 1;		// ignore first line of spheres.input file		
		}
		else if(i==1) {
		   	*r = strtod(line, &ptr);	// assign sphere radius to r
	   		i += 1;
		}
		else if(i==2) {
			*num_s = strtoul(line, &ptr, 0);	// assign num spheres
	   		i += 1;
	   		break;		// break loop, read rest of file in next loop
		}
	}

	free(line);			// free allocated line pointer
}

// Reads rest of spheres file and saves all sphere coordinates in array
void read_spheres(sphere *spheres, FILE *f_spheres) {
   	char *line = NULL;	// intialize line pointer for getline()
	char *ptr;			// initialize endchar: ptr for strtod & strtoul
   	size_t len = 0;		// initialize len pointer for getline()
   	ssize_t nread;		// initialize nread for getline() loops
   	size_t j = 0;		// initialize counter j for sphere array loop
   	double coords[3];	// make empty array for sphere coordinates

   	// Sphere coordinate loop
	while ((nread = getline(&line, &len, f_spheres)) != -1) {
		unsigned int k = 0;		// counter for coordinate reading
		char *coord = strtok(line,",");	// separate out first coordinate
   		
   		// loop through each coordinate on given line
   		while(coord != NULL) {
   			coords[k] = strtod(coord, &ptr);	// convert to double & save to coords array
   			coord = strtok(NULL,",");	// separate next coordinate
   			k += 1;
   		}
   		spheres[j].x = coords[0];	// save x coordinate of sphere j
   		spheres[j].y = coords[1];	// save y coordinate of sphere j
   		spheres[j].z = coords[2];	// save z coordinate of sphere j
		j += 1;
	}
	free(line);			// free allocated line pointer
}
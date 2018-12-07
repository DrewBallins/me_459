/*Author: Andrew Wild*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mesh.h"

// Reads mesh.input file and saves all triangles in mesh array
void read_mesh(triangle *mesh, FILE *f_mesh) {
	char *line = NULL;	// intialize line pointer for getline()
	char *ptr;			// initialize endchar: ptr for strtod & strtoul
   	size_t len = 0;		// initialize len pointer for getline()
   	ssize_t nread;		// initialize nread for getline() loops
   	size_t i = 0;	// file line counter
   	size_t j = 0;	// triangle ID counter
   	double coords[3];	// temporary triangle coordinates array

   	// sphere coordinate reading loop
	while ((nread = getline(&line, &len, f_mesh)) != -1) {	
		// find coordinates of triangle j node 1
		if(i==1) {
		   	unsigned int k = 0;				// coordinate counter
		   	char *coord = strtok(line,",");	// separate first coordinate
	   		
		   	// loop through every coordinate in given file line
	   		while(coord != NULL) {
	   			coords[k] = strtod(coord, &ptr);	// convert to double & save to coords array
	   			coord = strtok(NULL,",");	// separate next coordinate
	   			k += 1;
	   		}
	   		mesh[j].x1 = coords[0];	// x coordinate of triangle j node 1
	   		mesh[j].y1 = coords[1];	// y coordinate of triangle j node 1
	   		mesh[j].z1 = coords[2];	// z coordinate of triangle j node 1
	   		i += 1;
		}
		// find coordinates of triangle j node 2
		else if(i==2) {
			unsigned int k = 0;				// coordinate counter
			char *coord = strtok(line,",");	// separate first coordinate
	   		
			// loop through every coordinate in given file line
	   		while(coord != NULL) {
	   			coords[k] = strtod(coord, &ptr);	// convert to double & save to coords array
	   			coord = strtok(NULL,",");	// separate next coordinate
	   			k += 1;
	   		}
	   		mesh[j].x2 = coords[0];	// x coordinate of triangle j node 2
	   		mesh[j].y2 = coords[1];	// y coordinate of triangle j node 2
	   		mesh[j].z2 = coords[2];	// z coordinate of triangle j node 2
	   		i += 1;
		}
		// find coordinates of triangle j node 3
		else if(i==3) {
			unsigned int k = 0;	// coordinate counter
			char *coord = strtok(line,",");
	   		
			// loop through every coordinate in given file line
	   		while(coord != NULL) {
	   			coords[k] = strtod(coord, &ptr);	// convert to double & save to coords array
	   			coord = strtok(NULL,",");	// separate next coordinate
	   			k += 1;
	   		}
	   		mesh[j].x3 = coords[0];	// x coordinate of triangle j node 3
	   		mesh[j].y3 = coords[1];	// y coordinate of triangle j node 3
	   		mesh[j].z3 = coords[2];	// z coordinate of triangle j node 3
	   		i = 1;
	   		j += 1;
		}
		else {
			i += 1;
		}
	}
	free(line);
}
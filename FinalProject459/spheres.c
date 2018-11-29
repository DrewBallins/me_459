/*Author: Andrew Wild*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "spheres.h"

void read_sphere_data(FILE *f_spheres, double *r, unsigned long int *num_s) {
	char *line = NULL;
	char *ptr;
   	size_t len = 0;
   	ssize_t nread;

   	unsigned int i = 0;

	while ((nread = getline(&line, &len, f_spheres)) != -1) {
		if(i==0) {
			i += 1;
		}
		else if(i==1) {
		   	*r = strtod(line, &ptr);
	   		i += 1;
		}
		else if(i==2) {
			*num_s = strtoul(line, &ptr, 0);
	   		i += 1;
	   		break;
		}
	}

	free(line);
}

void read_spheres(sphere *spheres, FILE *f_spheres) {
   	char *line = NULL;
	char *ptr;
   	size_t len = 0;
   	ssize_t nread;

   	unsigned int j = 0;
   	double coords[3];

	while ((nread = getline(&line, &len, f_spheres)) != -1) {
		unsigned int k = 0;
		char *coord = strtok(line,",");
   		while(coord != NULL) {
   			printf("Sphere %d str coord %d = %s\n", j, k, coord);
   			coords[k] = strtod(coord, &ptr);
   			printf("Sphere %d double coord %d = %f\n", j, k, coords[k]);
   			coord = strtok(NULL,",");
   			k += 1;
   		}
   		spheres[j].x = coords[0];
   		spheres[j].y = coords[1];
   		spheres[j].z = coords[2];
		j += 1;
	}

	free(line);
}
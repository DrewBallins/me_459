/*Author: Andrew Wild*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mesh.h"

void read_mesh(triangle *mesh, FILE *f_mesh) {
	char *line = NULL;
	char *ptr;
   	size_t len = 0;
   	ssize_t nread;

   	unsigned int i = 0;
   	unsigned int j = 0;
   	double coords[3];
	while ((nread = getline(&line, &len, f_mesh)) != -1) {
		if(i==1) {
		   	unsigned int k = 0;
		   	char *coord = strtok(line,",");
	   		while(coord != NULL) {
	   			coords[k] = strtod(coord, &ptr);
	   			printf("Triangle %d Node %d Coord %d = %f\n", j, i, k+1, coords[k]);
	   			coord = strtok(NULL,",");
	   			k += 1;
	   		}
	   		//mesh[j].x1 = coords[0];
	   		//mesh[j].y1 = coords[1];
	   		//mesh[j].z1 = coords[2];
	   		i += 1;
		}
		else if(i==2) {
			unsigned int k = 0;
			char *coord = strtok(line,",");
	   		while(coord != NULL) {
	   			coords[k] = strtod(coord, &ptr);
	   			printf("Triangle %d Node %d Coord %d = %f\n", j, i, k+1, coords[k]);
	   			coord = strtok(NULL,",");
	   			k += 1;
	   		}
	   		//mesh[j].x2 = coords[0];
	   		//mesh[j].y2 = coords[1];
	   		//mesh[j].z2 = coords[2];
	   		i += 1;
		}
		else if(i==3) {
			unsigned int k = 0;
			char *coord = strtok(line,",");
	   		while(coord != NULL) {
	   			coords[k] = strtod(coord, &ptr);
	   			printf("Triangle %d Node %d Coord %d = %f\n", j, i, k+1, coords[k]);
	   			coord = strtok(NULL,",");
	   			k += 1;
	   		}
	   		//mesh[j].x2 = coords[0];
	   		//mesh[j].y2 = coords[1];
	   		//mesh[j].z2 = coords[2];
	   		i = 1;
	   		j += 1;
		}
		else {
			i += 1;
		}
	}

	free(line);
}
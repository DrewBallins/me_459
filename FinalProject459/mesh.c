/*Author: Andrew Wild*/
#include <stdio.h>
#include <stdlib.h>

#include "mesh.h"

void read_mesh(triangle *mesh, FILE *f_mesh, unsigned int num_t) {
	char *line = NULL;
   	size_t len = 0;
   	ssize_t nread;

   	unsigned int i = 0;
	while ((nread = getline(&line, &len, f_mesh)) != -1) {
		if(i>0) {
			if()
		}
		i += 1;
		printf("Retrieved line of length %zu:\n", nread);
		fwrite(line, nread, 1, stdout);
	}

	free(line);
}
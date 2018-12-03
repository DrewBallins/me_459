/* Author: Andrew Wild
   ME 459: HW 10 task 3
   Due: 12/09/2018 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int main() {
	double t;				// distance between parallel lines
	double l; 				// length of needles
	size_t n;				// number of needles dropped
	size_t h = 0;			// number of needles found to be crossing line
	double c,theta;			// center c and angle theta of needle dropped
	double x,x1,x2;			// distance between c and closest line

	// get user input for t, l & n
	printf("Enter distance between wood panels: ");
	scanf("%lf", &t);
	printf("Enter length of needles: ");
	scanf("%lf", &l);
	printf("Enter number of needles dropped: ");
	scanf("%zu", &n);
	
	// initialize rng to create pseudo-random values of c and theta
	srand(time(NULL));

	// run simulation
	for(size_t i = 0; i < n; i++) {
		c = (double)rand()/(RAND_MAX/t);
		theta = (double)rand()/(RAND_MAX/(M_PI/2));
		x1 = c - 0;
		x2 = t - c;
		if(x1 <= x2) {
			x = x1;
		}
		else {
			x = x2;
		}
		if(x <= l/2*cos(theta)) {
			h += 1;
		}		
	}

	double pi_est = 2*l*n/(t*h);			// calculate estimate of PI
	printf("Estimate of PI = %lf\n", pi_est);	// display estimate of PI

	return 0;
}
#ifndef OUTPUT_H
#define OUTPUT_H

// Populate a dim by dim matrix with random values
void randomT2(double* matrix, unsigned int dim);

// Output the given norm two with the time (in ms) it took to calculate
void outputT2(double norm2, double timing);

#endif
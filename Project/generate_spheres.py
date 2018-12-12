#!/usr/bin/env python3

# Author: Andrew Wild
# (c) 2018
# Generates a set of 3D sphere center point coordinates which are
# random floats from -100 to 100. Radius of spheres specified by
# 'radius' and number of spheres specified by n_spheres.

import random

output_file = "spheres.input"
radius = 3.2
n_spheres = 100000
coords = [0]*(3*n_spheres)

# Generate random sphere center point coordinates in 3D space
for i in range(3*n_spheres):
	coords[i] = random.uniform(-100.0,100.0)

# Write coordinates and data out to spheres.input file
with open(output_file, 'w') as file: 
	file.write("x,y,z\n")
	file.write("{}\n".format(radius))
	file.write("{}\n".format(n_spheres))
	for j in range(n_spheres):
		file.write("{0},{1},{2}\n".format(coords[j*3], coords[j*3+1], coords[j*3+2]))
#!/usr/bin/env bash

# Author: Andrew Wild
# ME 459 Final Project - final.sh
# This Slurm batch file compiles and runs my final project program

# Job scheduling code
#SBATCH --job-name=final
#SBATCH --partition=slurm_shortgpu
#SBATCH --ntasks=1 --cpus-per-task=1
#SBATCH --time=0-00:02:00
#SBATCH --output="final_output-%j.txt"

cd $SLURM_SUBMIT_DIR

# Load latest GCC module then compile using cmake
module load gcc/latest
cmake .
make

# Run the final code once with 30,000 triangles and 100,000 spheres
./final

# Unload gcc/latest when finished compiling and running program
module unload gcc/latest
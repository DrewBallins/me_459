#!/usr/bin/env bash

# Author: Andrew Wild
# ME 459 HW09 - task2.sh
# This Slurm batch file compiles and runs task2 from HW09

# Job scheduling code
#SBATCH --job-name=HW09_task2
#SBATCH --partition=slurm_shortgpu
#SBATCH --ntasks=1 --cpus-per-task=1
#SBATCH --time=0-00:10:00
#SBATCH --output="task2_output-%j.txt"

cd $SLURM_SUBMIT_DIR

# Load latest GCC module then compile using cmake
module load gcc/latest
cmake .
make

# Run the task2 code 5 times
for i in 1 2 3 4 5
do
	./task2
done

# Unload gcc/latest when finished compiling and running program
module unload gcc/latest
#!/usr/bin/env bash

# Author: Andrew Wild
# ME 459 HW06 - task1.sh
# This Slurm batch file compiles and runs task1 from HW06

# Job scheduling code
#SBATCH --job-name=HW06_task1
#SBATCH --partition=slurm_shortgpu
#SBATCH --ntasks=1 --cpus-per-task=1
#SBATCH --time=0-00:00:02
#SBATCH --output="task1_output-%j.txt"

# Load latest GCC module then compile and execute program
module load gcc/latest
gcc task1.c output.c -o task1
./task1 hello 								# Should be 5 characters
./task1 "hello how are you"					# Should be 17 characters				
./task1 "Hello, how are you doing today?"	# Should be 31 characters

# Unload gcc/latest when finished compiling and running program
module unload gcc/latest
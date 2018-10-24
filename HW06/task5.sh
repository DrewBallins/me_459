#!/usr/bin/env bash

# Author: Andrew Wild
# ME 459 HW06 - task5.sh
# This Slurm batch file compiles and runs task5 from HW06

# Job scheduling code
#SBATCH --job-name=HW06_task5
#SBATCH --partition=slurm_shortgpu
#SBATCH --ntasks=1 --cpus-per-task=1
#SBATCH --time=0-00:00:02
#SBATCH --output="task5_output-%j.txt"

# Load latest GCC module then compile and execute program
module load gcc/latest
gcc task5.c output.c -o task5 -lm
./task5

# Unload gcc/latest when finished compiling and running program
module unload gcc/latest
#!/usr/bin/env bash

# Author: Andrew Wild
# ME 459 HW05 - task1a.sh
# This Slurm batch file compiles and runs task1a from HW05

# Job scheduling code
#SBATCH --job-name=HW05_task1a
#SBATCH --partition=slurm_shortgpu
#SBATCH --ntasks=1 --cpus-per-task=1
#SBATCH --time=0-00:00:02
#SBATCH --output="task1a_output-%j.txt"

# Load latest GCC module then compile and execute program
module load gcc/latest
gcc task1a.c -o task1a
./task1a

# Unload gcc/latest when finished compiling and running program
module unload gcc/latest
#!/usr/bin/env bash

# Author: Andrew Wild
# ME 459 HW05 - task5.sh
# This Slurm batch file compiles and runs 
# traversal.c and related files from HW05 task3

# Job scheduling code
#SBATCH --job-name=HW05_task3
#SBATCH --partition=slurm_shortgpu
#SBATCH --ntasks=1 --cpus-per-task=1
#SBATCH --time=0-00:00:10
#SBATCH --output="task5_output-%j.txt"

# Load latest GCC module then compile and execute program
module load gcc/latest
gcc driver5.c dll_alloc.c traversal.c -o driver5
./driver5 8
./driver5 42

# Unload gcc/latest when finished compiling and running program
module unload gcc/latest

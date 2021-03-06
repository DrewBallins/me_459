#!/usr/bin/env bash

# Author: Andrew Wild
# ME 459 HW05 - task3.sh
# This Slurm batch file compiles and runs sort.c from HW05 task3

# Job scheduling code
#SBATCH --job-name=HW05_task3
#SBATCH --partition=slurm_shortgpu
#SBATCH --ntasks=1 --cpus-per-task=1
#SBATCH --time=0-00:00:10
#SBATCH --output="task3_output-%j.txt"

# Load latest GCC module then compile and execute program
module load gcc/latest
gcc driver3.c sort.c verify.c -o driver3
./driver3 8
./driver3 42
./driver3 400
./driver3 1500

# Unload gcc/latest when finished compiling and running program
module unload gcc/latest
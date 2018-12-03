#!/usr/bin/env bash

# Author: Andrew Wild
# ME 459 HW10 - task1.sh
# This Slurm batch file compiles and runs task1a & task1b from HW10

# Job scheduling code
#SBATCH --job-name=HW10_task1
#SBATCH --partition=slurm_shortgpu
#SBATCH --ntasks=1 --cpus-per-task=1
#SBATCH --time=0-00:00:10
#SBATCH --output="task1_output-%j.txt"

cd $SLURM_SUBMIT_DIR

# Load latest GCC module then compile using cmake
module load gcc/latest
cmake .
make

# Run the task1a & task2b code once each
./task1a
./task1b

# Unload gcc/latest when finished compiling and running program
module unload gcc/latest
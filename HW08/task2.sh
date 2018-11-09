#!/usr/bin/env bash

# Author: Andrew Wild
# ME 459 HW08 - task2.sh
# This Slurm batch file compiles and runs task2 from HW08

# Job scheduling code
#SBATCH --job-name=HW08_task2
#SBATCH --partition=slurm_shortgpu
#SBATCH --ntasks=1 --cpus-per-task=1
#SBATCH --time=0-00:00:10
#SBATCH --output="task2_output-%j.txt"

cd $SLURM_SUBMIT_DIR

# Load latest GCC module then compile using cmake and execute program
module load gcc/latest
cmake .
make
./task2

# Unload gcc/latest when finished compiling and running program
module unload gcc/latest
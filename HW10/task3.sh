#!/usr/bin/env bash

# Author: Andrew Wild
# ME 459 HW10 - task3.sh
# This Slurm batch file compiles and runs task3 from HW10

# Job scheduling code
#SBATCH --job-name=HW10_task3
#SBATCH --partition=slurm_shortgpu
#SBATCH --ntasks=1 --cpus-per-task=1
#SBATCH --time=0-00:00:10
#SBATCH --output="task3_output-%j.txt"

cd $SLURM_SUBMIT_DIR

# Load latest GCC module then compile using cmake
module load gcc/latest
cmake .
make

# Run the task3 code with t=6 and l=5 but multiple different n values
for i in 10 100 1000 10000 100000 1000000
do
	./task3 <<-EOF
	6
	5
	$i
	EOF
done


# Unload gcc/latest when finished compiling and running program
module unload gcc/latest
#!/usr/bin/env bash

# Author: Andrew Wild
# ME 459 HW09 - task1.sh
# This Slurm batch file compiles and runs task1 from HW09

# Job scheduling code
#SBATCH --job-name=HW09_task1
#SBATCH --partition=slurm_shortgpu
#SBATCH --ntasks=1 --cpus-per-task=1
#SBATCH --time=0-00:30:00
#SBATCH --output="task1_output-%j.txt"

cd $SLURM_SUBMIT_DIR

# Load latest GCC module then compile using cmake
module load gcc/latest
cmake .
make

# Make a new text file called task1_data.txt 
echo 'size;elapsed time [ms]' > task1_data.txt

# iterate through all test points
for i in 10 50 100 500 1000 5000 10000 50000 100000 500000
do
	arr=($(./task1 $i | grep -Eo '[+-]?[0-9]+([.][0-9]+)?'))
	echo ${arr[0]}';'${arr[1]}';'${arr[2]} >> task1_data.txt
done

# Print contents of task 1 data text file
cat task1_data.txt

# Unload gcc/latest when finished compiling and running program
module unload gcc/latest
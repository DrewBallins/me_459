#!/usr/bin/env bash

# Author: Andrew Wild
# ME 459 HW08 - task1.sh
# This Slurm batch file compiles and runs task1 from HW08

# Job scheduling code
#SBATCH --job-name=HW08_task1
#SBATCH --partition=slurm_shortgpu
#SBATCH --ntasks=1 --cpus-per-task=1
#SBATCH --time=0-00:00:10
#SBATCH --output="task1_output-%j.txt"

cd $SLURM_SUBMIT_DIR

# Load latest GCC module then compile using cmake
module load gcc/latest
cmake .
make

# Make a new text file called task1_data.txt 
echo 'size;elapsed time [ms]' > task1_data.txt

# iterate through all test points
for i in 8 16 32 64 128 256 512 1024 2048 4096 8192 16384 32768
do
	arr=($(./task1 $i | grep -Eo '[+-]?[0-9]+([.][0-9]+)?'))
	echo $i';'${arr[0]} >> task1_data.txt
done

# Print contents of task 1 data text file
cat task1_data.txt

# Unload gcc/latest when finished compiling and running program
module unload gcc/latest
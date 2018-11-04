#!/usr/bin/env bash

# Author: Andrew Wild
# ME 459 HW07 - task2.sh
# This Slurm batch file compiles and runs task2 from HW07

# Job scheduling code
#SBATCH --job-name=HW07_task2
#SBATCH --partition=slurm_shortgpu
#SBATCH --ntasks=1 --cpus-per-task=1
#SBATCH --time=0-00:00:10
#SBATCH --output="task2_output-%j.txt"

# Load latest GCC module then compile and execute program
module load gcc/latest
gcc task2.c output.c -o task2 -lm

# Make a new text file called task2_data.txt 
echo 'size;norm two;elapsed time [ms]' > task2_data.txt

# iterate through all test points
for i in 8 16 32 64 128 256 512 1024 2048 4096 8192
do
	arr=($(./task2 $i | grep -Eo '[+-]?[0-9]+([.][0-9]+)?'))
	echo $i';'${arr[0]}';'${arr[1]} >> task2_data.txt
done

# Print contents of task 2 data text file
cat task2_data.txt

# Unload gcc/latest when finished compiling and running program
module unload gcc/latest
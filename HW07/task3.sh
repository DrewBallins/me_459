#!/usr/bin/env bash

# Author: Andrew Wild
# ME 459 HW07 - task3.sh
# This Slurm batch file compiles and runs task3 from HW07

# Job scheduling code
#SBATCH --job-name=HW07_task3
#SBATCH --partition=slurm_shortgpu
#SBATCH --ntasks=1 --cpus-per-task=1
#SBATCH --time=0-00:00:10
#SBATCH --output="task3_output-%j.txt"

cd $SLURM_SUBMIT_DIR

# Load latest GCC module then compile and execute program
module load gcc/latest
gcc driver3.c sort.c verify.c -o driver3

# Make a new text file called task2_data.txt 
echo 'size;elapsed time [ms]' > task3_data.txt

# iterate through all test points
for i in 8 16 32 64 128 256 512 1024 2048 4096 8192 16384 32768
do
	arr=($(./driver3 $i | grep -Eo '[+-]?[0-9]+([.][0-9]+)?'))
	echo $i';'${arr[0]} >> task3_data.txt
done

# Print contents of task 2 data text file
cat task3_data.txt

# Unload gcc/latest when finished compiling and running program
module unload gcc/latest
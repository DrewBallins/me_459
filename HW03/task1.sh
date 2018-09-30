#!/usr/bin/env bash

# Author: Andrew Wild
# ME 459 HW03 - task1.sh
# This Slurm batch file simply prints the host name of the node the file is running on

# Job scheduling code
#SBATCH --job-name=hostname_printer
#SBATCH --ntasks=1 --cpus-per-task=1
#SBATCH --output="hostname_output-%j.txt"
#SBATCH --time=0-00:00:02

# Print host name
hostname

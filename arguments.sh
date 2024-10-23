#!/bin/bash
#
#SBATCH --job-name=Arguments
#SBATCH --output=./arguments.txt
#
#SBATCH --ntasks=1
#SBATCH --ntasks-per-node=1
#SBATCH --nodes=1
#SBATCH --partition=COMP1680-dev

gcc arguments.c -o arguments.out
gcc arg2.c -o arg2.out
./arguments.out 100
./arg2.out 100

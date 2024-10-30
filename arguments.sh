#!/bin/bash
#
#SBATCH --job-name=Arguments
#SBATCH --output=./timing.csv
#
#SBATCH --ntasks=1
#SBATCH --ntasks-per-node=1
#SBATCH --nodes=1
#SBATCH --cpus-per-task
#SBATCH --partition=COMP1680-dev

gcc -fopenmp arg2.c -o arg2.out
for i in {10..1000}; do
  ./arg2.out 10*$i
done

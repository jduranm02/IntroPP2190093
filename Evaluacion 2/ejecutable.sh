#!/bin/bash
#SBATCH --job-name=heat_mpi_job
#SBATCH --ntasks=4
#SBATCH --nodes=2
#SBATCH --cpus-per-task=1
#SBATCH --output=heat_mpi_output.txt

module load devtools/mpi/openmpi/3.1.4

EXECUTABLE=./heat_mpi
INPUT_FILE=botella.dat
NUM_STEPS=1000

mpirun -np 8 $EXECUTABLE $INPUT_FILE $NUM_STEPS
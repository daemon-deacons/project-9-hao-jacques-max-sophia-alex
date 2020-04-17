#!/bin/bash
#SBATCH --job-name="ring_c_part_1"
#SBATCH --partition=medium
#SBATCH --nodes=2
#SBATCH --tasks-per-node=2
#SBATCH --time=00:10:00
#SBATCH --mem=1GB
#SBATCH --account=classes
#SBATCH --mail-user=rossaj16@wfu.edu
#SBATCH --mail-type=BEGIN,END,FAIL
#SBATCH --output=ring_c-%j.o
#SBATCH --error=ring_c-%j.e
#ESTABLISH ENVIRONMENT SETTINGS AND MODULES
module load rhel7/openmpi/4.0.2-intel-2018

# Change into the working directory.
WORKDIR=/deac/classes/csc391/rossaj16/Project_9
cd $WORKDIR

# Compile ring_c.c
mpicc ring_c.c -o ring_c

# Run the program.
mpirun -np 4 ring_c

/bin/echo "Execution complete!"
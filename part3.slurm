#!/bin/bash
#SBATCH --job-name="ring_c_part_3"
#SBATCH --partition=medium
#SBATCH --nodes=2
#SBATCH --tasks-per-node=2
#SBATCH --time=03:00:00
#SBATCH --mem=32GB
#SBATCH --account=classes
#SBATCH --mail-user=rossaj16@wfu.edu
#SBATCH --mail-type=BEGIN,END,FAIL
#SBATCH --output=ring3_c-%j.o
#SBATCH --error=ring3_c-%j.e
#ESTABLISH ENVIRONMENT SETTINGS AND MODULES
module load rhel7/openmpi/4.0.2-intel-2018

# Change into the working directory.
WORKDIR=/deac/classes/csc391/rossaj16/Project_9
cd $WORKDIR

# Compile ring2_c.c
mpicc ring3_c.c -o ring3_c

# Run the program 5 times using the first set of arguments.
for i in {1..5}
do
        starttime=$(date +%s)
        mpirun --mca pml ob1 --mca btl tcp,self ring3_c
        /bin/echo "Run 1,$i ran in $(($(date +%s) - ${starttime}))"
done

# Run the program 5 times using the second set of arguments.
for i in {1..5}
do
        starttime=$(date +%s)
        mpirun --mca pml ob1 --mca btl tcp,vader,self ring3_c
        /bin/echo "Run 2,$i ran in $(($(date +%s) - ${starttime}))"
done

# Run the program 5 times using the third set of arguments.
for i in {1..5}
do
        starttime=$(date +%s)
        mpirun --mca pml ob1 --mca btl usnic,vader,self ring3_c
        /bin/echo "Run 3,$i ran in $(($(date +%s) - ${starttime}))"
done

/bin/echo "Execution complete!"

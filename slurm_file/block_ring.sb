#!/bin/bash

#SBATCH --nodes=2
#SBATCH --ntasks-per-node=128
#SBATCH --job-name block_ring
#SBATCH --time=00:30:00
#SBATCH --output=%x_%j.out
#SBATCH --error=%x_%j.err

module purge
#module load GCC/12.3.0 OpenMPI/5.0.0
module load GCC/6.4.0 OpenMPI/2.1.2

# AMD20 cluster has 207 nodes, the capacity of cores for each node is 128 = 2^7
# we will run n = 2^1, 2^2, ..., 2^7, 2^8
for i in $(seq 1 8); do 
    let ntasks=2**$i
    mpiexec -n $ntasks block_ring > block_ring_${ntasks}processors.csv
    echo "processes=$i is finished"
done
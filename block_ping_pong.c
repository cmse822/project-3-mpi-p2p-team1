// mpicc -o blocking_ping_pong blocking_ping_pong.c
// mpiexec -n 2 ./blocking_ping_pong > blocking_ping_pong.csv

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define ITER 100
#define MSG_SIZE 4096

int main(int argc, char* argv[]) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    if (size < 2) {
        printf("SIZE ERROR \n");
        MPI_Finalize();
        return 1;
    }

    if (rank == 0) {
        printf("Message Size (bytes),Time (us),Bandwidth (Megabytes/s),Latency (us)\n");
    }

    for (int msgSize = 2; msgSize <= MSG_SIZE; msgSize *= 2) {

        char* msg = (char*)malloc(msgSize);

        if (!msg) {
            fprintf(stderr, "Memory allocation failed for message size %d bytes.\n", msgSize);
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        
        double totalTime = 0.0;
        double totalBandwidth = 0.0;

        for (int i = 0; i < ITER; ++i) {

            MPI_Barrier(MPI_COMM_WORLD);

            if (rank == 0) {

                double startTime = MPI_Wtime();
                
                MPI_Send(msg, msgSize, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
                MPI_Recv(msg, msgSize, MPI_CHAR, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

                double endTime = MPI_Wtime();

                totalTime += endTime - startTime; // sec

            } else if (rank == 1) {

                MPI_Recv(msg, msgSize, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                MPI_Send(msg, msgSize, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
            }

        }

        if (rank == 0) {

            double avgTime = totalTime / ITER * 1e6; // us
            double bandwidth = (msgSize * 2 * ITER) / totalTime / 1e6; // Megabytes/s
            double latency = avgTime / 2.0; // us
            fprintf(stderr, "Message size %d bytes done\n", msgSize);
            printf("%d,%.3f,%.3f,%.3f\n", msgSize, avgTime, bandwidth, latency);
        }

        free(msg);
    }

    MPI_Finalize();
    return 0;
}
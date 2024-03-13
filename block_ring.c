#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define MAX_MSG_SIZE 4096 
#define ITER 10000

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);
    int rank, tasks;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &tasks);

    if (rank == 0) {
        printf("Message Size(bytes), Bandwidth(Megabytes/s), Latency(us)\n");
    }

    for (int msg_size = 2; msg_size <= MAX_MSG_SIZE; msg_size *= 2) {
        char *message = (char *)malloc(msg_size);
        if (!message) {
            fprintf(stderr, "Failed to allocate memory for message size %d bytes.\n", msg_size);
            MPI_Abort(MPI_COMM_WORLD, 1);
        }

        for (int i = 0; i < msg_size; ++i) {
            message[i] = rank;
        }

        double start_time = MPI_Wtime();

        for (int i = 0; i < ITER; ++i) {
            int next = (rank + 1) % tasks;
            int prev = (rank - 1 + tasks) % tasks;

            MPI_Sendrecv_replace(message, msg_size, MPI_CHAR, next, 0, prev, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }

        double end_time = MPI_Wtime();
        double total_time = end_time - start_time;

        double total_bytes = (double)msg_size * ITER * 2; // Total bytes sent and received
        double bandwidth = total_bytes / total_time / 1e6; // MB/s
        double latency = (total_time / ITER) / 2 * 1e6; // microseconds
        
		// print the column header	
        if (rank == 0) {
            printf("%d, %f, %f\n", msg_size, bandwidth, latency);
        }

        free(message);
    }

    MPI_Finalize();
    return 0;
}

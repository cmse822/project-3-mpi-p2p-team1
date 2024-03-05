#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define ITER 100 
#define MAX_MSG_SIZE 4096

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);
    int rank, tasks;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &tasks);

    int right_neighbor_rank = (rank + 1) % tasks;
    int left_neighbor_rank = rank - 1;
    if (left_neighbor_rank < 0) left_neighbor_rank = tasks - 1;

    for (int msg_size = 2; msg_size <= MAX_MSG_SIZE; msg_size *= 2) {
        char *send_message = (char *)malloc(msg_size);
        char *recv_message = (char *)malloc(msg_size);

        if (!send_message || !recv_message) {
            fprintf(stderr, "Memory allocation failed for message size %d bytes.\n", msg_size);
            MPI_Abort(MPI_COMM_WORLD, 1);
        }

        double start_time = MPI_Wtime();

        for (int i = 0; i < ITER; i++) {
            MPI_Sendrecv(send_message, msg_size, MPI_CHAR, right_neighbor_rank, 0,
                         recv_message, msg_size, MPI_CHAR, left_neighbor_rank, 0,
                         MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }

        double end_time = MPI_Wtime();

        if (rank == 0) {
            double elapsed_time = end_time - start_time;
            printf("Message size: %d bytes, Total time for %d iterations: %.3f seconds\n", msg_size, ITER, elapsed_time);
        }

        free(send_message);
        free(recv_message);
    }

    MPI_Finalize();
    return 0;
}

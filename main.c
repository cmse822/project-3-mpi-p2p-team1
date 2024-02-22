#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define MSG_SIZE 1024
#define ITER 100

int main(int argc, char *argv[]) {

    MPI_Init(&argc, &argv);
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int tasks;
    MPI_Comm_size(MPI_COMM_WORLD, &tasks);

    char *msg = malloc(MSG_SIZE);

    int partner_rank;
    if (rank % 2 == 0) {
        partner_rank = (rank + 1) % tasks;
    } else {
        partner_rank = (rank - 1) % tasks;
    }

    for (int i = 0; i < ITER; i++) {
        if ((rank % 2 == 0 && i % 2 == 0) || (rank % 2 != 0 && i % 2 != 0)) {
            /* Send the message. */
        } else {
            /* Receive a message. */
        }
    }

    free(msg);

    MPI_Finalize();

    return 0;
}
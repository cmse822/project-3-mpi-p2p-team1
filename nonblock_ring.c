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

    MPI_Request requestSend, requestRecv;
    MPI_Status statusSend, statusRecv;
    
    if (rank == 0) {
        printf("Message Size(bytes), Bandwidth(Megabytes/s), Latency(us)\n");
    }
    
    for (int msg_size = 2; msg_size <= MAX_MSG_SIZE; msg_size *= 2) {
        char *send_message = (char *)malloc(msg_size);
        char *recv_message = (char *)malloc(msg_size);
        if (!send_message || !recv_message) {
            fprintf(stderr, "Failed to allocate memory for message size %d bytes.\n", msg_size);
            MPI_Abort(MPI_COMM_WORLD, 1);
        }

        for (int i = 0; i < msg_size; ++i) {
            send_message[i] = rank;
            recv_message[i] = 0; 
        }

        double start_time = MPI_Wtime();

        for (int i = 0; i < ITER; ++i) {
            int next = (rank + 1) % tasks;
            int prev = (rank - 1 + tasks) % tasks;

            MPI_Irecv(recv_message, msg_size, MPI_CHAR, prev, 0, MPI_COMM_WORLD, &requestRecv);
            MPI_Isend(send_message, msg_size, MPI_CHAR, next, 0, MPI_COMM_WORLD, &requestSend);
            
            MPI_Wait(&requestSend, &statusSend);
            MPI_Wait(&requestRecv, &statusRecv);

            char *temp = send_message;
            send_message = recv_message;
            recv_message = temp;
        }

        double end_time = MPI_Wtime();
        double total_time = end_time - start_time;

        double total_bytes = (double)msg_size * ITER * 2; 
        double bandwidth = total_bytes / total_time / 1e6;
        double latency = (total_time / ITER) / 2 * 1e6; 

        if (rank == 0) {
            printf("%d, %f, %f\n", msg_size, bandwidth, latency);
        }

        free(send_message);
        free(recv_message);
    }

    MPI_Finalize();
    return 0;
}

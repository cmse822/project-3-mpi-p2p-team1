#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
	
	MPI_Init(&argc, &argv);
	int rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int tasks;
	MPI_Comm_size(MPI_COMM_WORLD, &tasks);
	
	int left_neighbor_rank = (rank + 1) % tasks;
	int right_neighbor_rank = (rank - 1) % tasks;

	int msg_size;
	char *message;
	MPI_Status status;
	msg_size = 1 << 1;
	message = (char *)malloc(msg_size);
	printf("Message size %d\n", msg_size);
	for (j = 1; j < 10; j++) {
		if (j % 2 == 0) {
			MPI_Send(message, msg_size, MPI_CHAR, right_neighbor_rank, 0, MPI_COMM_WORLD);	
			printf("%d sends to %d and receives from %d\n", rank, right_neighbor_rank, left_neighbor_rank);
		} else {
			MPI_Recv(message, msg_size, MPI_CHAR, right_neighbor_rank, 0, MPI_COMM_WORLD, &status);
			printf("%d sends to %d and receives from %d\n", rank, left_neighbor_rank, right_neighbor_rank);
		}
	}
	free(message);
	
	MPI_Finalize();

}

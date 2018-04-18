#include "stdafx.h"
#include "mpi.h"
#pragma comment(lib, "mpich.lib")

int main(int argc, char * argv[])
{
	int rank, resultlen;
	char name[MPI_MAX_PROCESSOR_NAME];
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Get_processor_name(name, &resultlen);
	int number;
	do {
		if (rank == 0) {
			printf("Enter number (0 or less exit): ");
			fflush(stdout);
			scanf("%d", &number);
		}
		MPI_Bcast(&number, 1, MPI_INT, 0, MPI_COMM_WORLD);
		printf("%s (%d) got %d\n", name, rank, number);
		fflush(stdout);
	} while (number > 0);
	MPI_Finalize();
	return 0;
}


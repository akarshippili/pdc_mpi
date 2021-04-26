#include<stdio.h>
#include<mpi.h>

int main( int argc, char *argv[]){
    MPI_Init( NULL, NULL );
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    int number;
    if(rank==0){
        number=-1;
        MPI_Send(&number,1,MPI_INT,1,0,MPI_COMM_WORLD);
    }
    else if(rank==1){
        MPI_Recv(&number,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        printf("%d recived\n",number);
    }
    MPI_Finalize();
    return 0;
}
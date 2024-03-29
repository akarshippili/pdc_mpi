#include<stdio.h>
#include<mpi.h>

int main( int argc, char *argv[] )
{
    int rank,size;
    MPI_Init( NULL, NULL );
    MPI_Comm_rank( MPI_COMM_WORLD, &rank );
    MPI_Comm_size( MPI_COMM_WORLD, &size );
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name,&name_len);
    printf( "I am %s rank %d out of %d\n", processor_name ,rank, size );
    MPI_Finalize();
    return 0;
}
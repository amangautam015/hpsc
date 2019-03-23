#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<mpi.h>

int main(int argc, char** argv){
	MPI_Init(&argc,&argv);
	double integral=0,delta_area=0,area=0,pi=3.14159265;
	
    
	int process_id,i,total_processes,INTERVAL=20000,tag=10;
	MPI_Status status;
	MPI_Comm_rank(MPI_COMM_WORLD, &process_id);
	MPI_Comm_size(MPI_COMM_WORLD,&total_processes);

	if(process_id==0){
	int k;
	for (k=1;k<total_processes;k++) {
		MPI_Recv( &delta_area, 1, MPI_DOUBLE, k, tag, MPI_COMM_WORLD, &status);
		integral=integral+delta_area;
	}		
	printf("Area under curve : %f\n",integral);

	}

	else{
		for(i=(process_id-1)*INTERVAL/(total_processes-1);i<=((process_id)*INTERVAL/(total_processes-1)-1);i++){
			area=area+0.5*pi/INTERVAL*(sin((double)i/(double)INTERVAL*pi)+sin((double)(i+1)/(double)INTERVAL*pi));
		}
		MPI_Send(&area,1,MPI_DOUBLE,0,tag,MPI_COMM_WORLD);
	}
	
	

	MPI_Finalize();
	return 0;
}

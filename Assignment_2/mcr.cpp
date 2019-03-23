#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
#include<math.h>

int main(int argc, char** argv){
	MPI_Init(&argc,&argv);
	double pi=3.14159265,area=0,X,Y;
	int tag =10;
	
	int process_id,i,total_processes,size=20000,count=0,count_total=0,cr=0;
	srand ( time(NULL) );
	MPI_Status status;
	MPI_Comm_rank(MPI_COMM_WORLD, &process_id);
	MPI_Comm_size(MPI_COMM_WORLD,&total_processes);
	if(process_id==0){
	int k;
	for (k=1;k<total_processes;k++) {
		MPI_Recv( &cr, 1, MPI_INT, k, tag, MPI_COMM_WORLD, &status);
		count_total=count_total+cr;
	}		
	area=(double)count_total/(double)size*pi;
	printf("Area under curve : %f\n",area);
	}
	else{
		for(i=0;i<=size/(total_processes-1)-1;i++){
		X= ((double)rand()/(double)(RAND_MAX)) * pi;
		Y= ((double)rand()/(double)(RAND_MAX)) * 1;
		if(Y<=sin(X)){
			count++;
		}
	}
		MPI_Send(&count,1,MPI_INT,0,tag,MPI_COMM_WORLD);
	}
	

   
	MPI_Finalize();
	
}

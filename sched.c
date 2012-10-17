#include<stdio.h>
#include<stdlib.h>

struct task{
	
	int rank, exectime, starttime, firstproc;
	
};

int nprocs, ntasks;
struct task *tasks;

void load_taskset(const char *filename){
	
	FILE *fin;
	int i;
	fin = fopen(filename, "r");
	fscanf(fin, "%d", &ntasks);
	
	tasks = malloc(sizeof(*tasks)*ntasks);
	for(i = 0; i < ntasks; i++){
		
		fscanf(fin, "%d", tasks[i].exectime);
		fscanf(fin, "%d", tasks[i].rank);

	}
}
 
int main(int argc, char **argv){

	if(argc < 4){		
		fprintf(stderr, "Usage: sched <n> <taskset> <alg> \n");
		exit(1);	
	}
	
	nprocs = atoi(argv[1]);
	load_taskset(argv[2]);
	return 0;

}

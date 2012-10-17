#include"iostream"
#include"cstdio"
#include"cstdlib"
#include"fstream"
#include"cstring"

using namespace std;

typedef struct{
	
	int rank;
	int exectime;
	
}task;

int nprocs, ntasks;
task *tasks;
string buff;

void load_taskset(const char *filename){
	
	int i;
	ifstream inFile;
	inFile.open(filename);
	getline(inFile, buff);
	ntasks = atoi(buff.c_str());
	tasks = (task*)malloc(sizeof(*tasks)*ntasks);
	for(i = 0; i < ntasks; i++){
		
		inFile >> tasks[i].exectime >> tasks[i].rank;

	}

	inFile.close();

}
 
int main(int argc, char **argv){

	if(argc < 2){		
		fprintf(stderr, "Usage: sched <taskset> \n");
		exit(1);	
	}
	load_taskset(argv[1]);
	for(int i = 0; i < ntasks; i++)
		cout << tasks[i].exectime << " " << tasks[i].rank << endl;
	return 0;

}

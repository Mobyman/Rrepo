#include"iostream"
#include"fstream"
#include"cstdlib"
#include"ctime"

using namespace std;

int main(int argc, char **argv){
	srand(time(NULL));
	int n, m, i, t, r;
	ofstream outFile;
	outFile.open("taskset.txt");	

	if(argc < 3){		
		fprintf(stderr, "Usage: taskgen <n> <m> \n");
		exit(1);	
	}

	n = atoi(argv[1]);
	m = atoi(argv[2]);

	outFile << m << endl;

	for(i = 0; i < m; i++){
	
		t = rand()%100 + 1;
		r = rand()%n + 1;
		outFile << t << " " << r << endl; 
					
	}

	outFile.close();
	return 0;
}

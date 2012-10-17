#include<stdio.h>
#include<stdlib.h>



int main(int argc, char **argv){
	int n, m, i, t, r;
	FILE *f;
	f = fopen("taskset.txt","wb");	

	if(argc < 3){		
		fprintf(stderr, "Usage: taskgen <n> <m> \n");
		exit(1);	
	}

	n = atoi(argv[1]);
	m = atoi(argv[2]);

	
		for(i = 0; i < m; i++){
	
			t = rand()%100 + 1;
			r = rand()%n + 1;
			fprintf(f,"%d %d\n", t, r);
					
		}
	fclose(f);
	return 0;
}

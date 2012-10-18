#include"iostream"
#include"vector"
#include"cstdlib"
#include"ctime"

using namespace std;
const int MAX_SIZE = 20
typedef struct{
	
	int rank;
	int exectime;
	
}task;

//Counting sort for an array of structures
void CountingSort(task* tosort, int size){
	vector<int> count[101]; //for every exectime possible we have a vector of ranks
	vector<int>::iterator it;
	int i, counter = 0;
	
	//filling an array of exectime with ranks
	for(i = 0; i < size; i++)
		count[tosort[i].exectime].push_back(tosort[i].rank);
	
	//rewriting the array with sorted values	
	for(i = 1; i < 101; i++)
		if(!count[i].empty())
			for(it = count[i].begin(); it != count[i].end(); ++it){ 
				tosort[counter] = {*it, i};
				counter++;
			}
	
}

int main(){
	srand(time(NULL));
	task test[MAX_SIZE];
	int t, r, i, n = 20;
	
	for(i = 0; i < MAX_SIZE; i++){
		t = rand()%100 + 1;
		r = rand()%n + 1;
		test[i] = {r, t};
		cout << test[i].exectime << " " << test[i].rank << endl;						
	}
	
	cout << "_______________________" << endl;
	CountingSort(test, MAX_SIZE);
	
	for(i = 0; i < MAX_SIZE; i++)
		cout << test[i].exectime << " " << test[i].rank << endl;	
					
	return 0;
}

#include<iostream>
#include<vector>

using namespace std;


struct My_data {int a, b; double sum;};

void harm(My_data& arg){
	int a=arg.a,b=arg.b; // you better work
	double sum=0;        // with thread-local variables
	for(int i=a;i<b;i++)sum+=1.0/i;
	arg.sum=sum; // only write once into memory
	}


int main() {
cerr << "Give a number of threads to be created" << endl;    

int N_threads; 
cin >> N_threads;

cerr << "Number of terms in the harmonic sum to be computed" << endl;
int N_terms;
cin >> N_terms;


My_data arg = {3, 4, 0.0};


std::vector<My_data> params(N_threads);
for(int i=0; i< N_threads ;i++) {
   params[i].a = 1 + N_terms/N_threads*i;
   params[i].b = 1 + N_terms/N_threads*(i+1);
   }
params[params.size()-1].b=N_terms+1;


return 0;
}
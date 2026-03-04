#include<iostream>
#include<vector>
#include<thread>

using namespace std;


struct My_data {int a, b; double sum;};

void harm(My_data& arg){
	int a=arg.a,b=arg.b; // you better work
	double sum=0;        // with thread-local variables
	for(int i=a;i<b;i++)sum+=1.0/i;
	arg.sum=sum; // only write once into memory
}	


int main(int argc, char* argv[]) {


	long N_threads;
	long N_terms = 1e9;
	for(int i=0; i < argc; ++i){
		std::string arg=argv[i];    // Converting to string
		if(arg=="-N_threads" && i+1 < argc) N_threads = stoi(argv[i+1]);}
		// if(arg=="-N_terms" && i+1 <argc) N_terms = stod(argv[i+1]);	



vector<My_data> params(N_threads);
for(int i=0; i< N_threads ;i++) {
   params[i].a = 1 + N_terms/N_threads*i;
   params[i].b = 1 + N_terms/N_threads*(i+1);
   }
params[params.size()-1].b=N_terms+1;


vector<thread> threads;
threads.reserve(N_threads); // reserve empty slots for our threads

for(int i=0; i < N_threads ;i++) {
   threads.emplace_back(harm, std::ref(params[i]));
}

for(auto &thread : threads) thread.join();


double total=0; 
for(auto &p : params) {total+=p.sum;}

cout << "Total sum =" << total << endl;


return 0;
}
#include<iostream>
#include<vector>
#include<thread>
#include <chrono>  // for time  measure

using namespace std;
using namespace std::chrono;



struct My_data {int a, b; double sum;};

void harm(My_data& arg){
	int a=arg.a,b=arg.b; // you better work
	double sum=0;        // with thread-local variables
	for(int i=a;i<b;i++)sum+=1.0/i;
	arg.sum=sum; // only write once into memory
}	


int main(int argc, char* argv[]) {
// auto start = high_resolution_clock::now();  
// auto start = system_clock::now();

// cerr << "Give a number of threads to be created" << endl;    

// int N_threads; 
// cin >> N_threads;

// cerr << "Number of terms in the harmonic sum to be computed" << endl;
// int N_terms;
// cin >> N_terms;


	// std::vector<double> numbers;     // Storing all numbers
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

// auto stop = high_resolution_clock::now();
// auto stop = system_clock::now();
// auto duration = duration_cast<seconds>(stop - start);
// cerr << "Time for computation in seconds:" << duration.count() << endl;
return 0;
}
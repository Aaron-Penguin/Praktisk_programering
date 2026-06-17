#include<iostream>
#include<assert.h>
#include<vector>
#include<ctime>


int binsearch(const std::vector<double>& x, double z);
double linterp(std::vector<double> x, std::vector<double> y, double z);




int main() {

int N = 10;   // number of data points

std::vector<double> X_data(10);
std::vector<double> Y_data(10);

for (int i=0; i < N; ++i){
    X_data[i] = i;
    double k = (rand() % 101);

    std::cout << X_data[i] << " " << k/2 << "\n";
}


// for (int i=0; i < N; ++i){
//     std::cout << X_data[i] << " ";
// }


}


int binsearch(const std::vector<double>& x, double z)
	{/* locates the interval for z by bisection */ 
	assert( z>=x[0] && z<=x[x.size()-1] );
	int i=0, j=x.size()-1;
	while(j-i>1){
		int mid=(i+j)/2;
		if(z>x[mid]) i=mid; else j=mid;
		}
	return i;
}


double linterp(std::vector<double> x, std::vector<double> y, double z){
	int i=binsearch(x,z);
  	double dx=x[i+1]-x[i];
  	assert(dx>0);
  	double dy=y[i+1]-y[i];
  	return y[i]+dy/dx*(z-x[i]);
}
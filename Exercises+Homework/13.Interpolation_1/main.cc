#include<iostream>
#include<assert.h>
#include<vector>
#include<ctime>
#include<cmath>


int binsearch(const std::vector<double>& x, double z);
double linterp(std::vector<double> x, std::vector<double> y, double z);
double linterpInteg(std::vector<double> x, std::vector<double>, double z);



int main(int argc, char* argv[]) {

std::string input_type;

for(int i=0; i < argc; ++i){
    std::string arg=argv[i];    // Converting to string

    if(arg=="-printtype" && i+1 < argc){
        input_type = argv[i+1];
    }
}       



// -------------- Constrcting data -------------

std::vector<double> X_data;
std::vector<double> Y_data;

for (double x = 0.0; x <=9; x = x + 0.1){
	X_data.push_back(x);
	double y = std::cos(x);
	Y_data.push_back(y);
}

// std::vector<double> Y_data = {2, 5, 8, 4, 6, -5, -3, -2, 0, 1, 5};
// std::vector<double> X_interp = {-4.3, -3.2, -2.4,  - 1.1, 1.8, 2.1, 2.3}; 

int N =  X_data.size();
// int M = X_interp.size();

if (input_type == "Construct_data"){
	for (int i =0; i < N; i++){
		std::cout << X_data[i] << "    " << Y_data[i] <<  std::endl;
	}
}


// -------------- Inpertolation ------------------


if (input_type == "Spline_data"){

	std::vector<double> X_interp;
	std::vector<double> Y_interp;  // Initilized empty vector
	std::vector<double> Integrated;
	
	for (double z = 0.0; z < X_data[N-1]; z = z + 0.05){
		// std::cerr << z << std::endl;
		X_interp.push_back(z);
	}

	int M = X_interp.size();
	double F_tot = 0.0;
	
	for (int m =0; m < M; m++){
		double z_m = X_interp[m];
		double y_inerp = linterp(X_data, Y_data, z_m);
		Y_interp.push_back(y_inerp);

		double F = linterpInteg(X_data, Y_data, z_m);
		F_tot += F; 
		Integrated.push_back(F_tot);
	}

	for (int i =0; i < M; i++){
		std::cout << X_interp[i] << "    " << Y_interp[i] << "    " << Integrated[i] <<  std::endl;
	}
}

return 0;
}


int binsearch(const std::vector<double>& x, double z){           /* locates the interval for z by bisection */ 
	assert( z>=x[0] && z<=x[x.size()-1] );
	int i=0, j=x.size()-1;
	while(j-i>1){
		int mid=(i+j)/2;
		if(z>x[mid]) i=mid; else j=mid;
		}
	return i;
}


double linterp(std::vector<double> x, std::vector<double> y, double z){        // Initial data (x,y), New data points.
	int i=binsearch(x,z);
  	double dx=x[i+1]-x[i];
  	assert(dx>0);
  	double dy=y[i+1]-y[i];
  	return y[i]+dy/dx*(z-x[i]);
}

double linterpInteg(std::vector<double> x, std::vector<double> y, double z){     // We just use the interpolated data
	int i = binsearch(x,z);
	double dx = x[i+1] - x[i];
    assert(dx > 0);
    double dy = y[i+1] - y[i];
	double dz= z -x[i];
	return y[i]* dz + 1/2 *dy/dx * dz * dz;
}


#include<iostream>
#include<cmath>

#include "binsearch.h"
#include "Linear_spline.h"
#include "qspline.h"


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



int N =  X_data.size();


if (input_type == "Construct_data"){
	for (int i =0; i < N; i++){
		std::cout << X_data[i] << "    " << Y_data[i] <<  std::endl;
	}
}


// -------------- Linear Inpertolation ------------------


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




if (input_type == "Qspline_data"){

	std::vector<double> X_interp;
	std::vector<double> Y_interp;  // Initilized empty vector
	// std::vector<double> Integrated;

	Qspline QS(X_data, Y_data);
	
	for (double z = 0.0; z < X_data[N-1]; z = z + 0.05){
		X_interp.push_back(z);
	}

	int M = X_interp.size();
	// double F_tot = 0.0;
	
	for (int m =0; m < M; m++){
		double z_m = X_interp[m];
		double y_fit = QS.eval(z_m);
		Y_interp.push_back(y_fit);

		// double F = linterpInteg(X_data, Y_data, z_m);
		// F_tot += F; 
		// Integrated.push_back(F_tot);
	}

	for (int i =0; i < M; i++){
		std::cout << X_interp[i] << "    " << Y_interp[i] <<  std::endl;
	}
}





return 0;
}



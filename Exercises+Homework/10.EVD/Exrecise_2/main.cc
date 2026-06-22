#include <iostream>
// #include<algorithm>



#include "Matrix.h"
#include "EVD.h"

// #include "Vector.h"
// #include "Quicksort.h"


double R_0(double r_val){
        return 2.0* std::exp(- r_val);
}

double R_1(double r_val){
    return - 2* std::pow(2, -1.5) * (1 -r_val/2) *std::exp(- r_val/2);
}



int main(int argc, char* argv[]){

std::string input_type;
double dr;
double rmax;

for(int i=0; i < argc; ++i){
    std::string arg=argv[i];    // Converting to string
    if(arg=="-dr" && i+1 < argc){
        dr = std::stod(argv[i+1]);     // convert to double!
    }
    if(arg=="-rmax" && i+1 < argc){
        rmax = std::stod(argv[i+1]);
    }
    if(arg=="-printtype" && i+1 < argc){
        input_type = argv[i+1];
    }
}                                           


int N = (int) (rmax/dr) -1;


// Kinetic energy Matrix
Matrix ddx(N, N, 0.0);
Matrix V(N, N, 0.0);

// This part uses finite diffrence, and includes the boundary condition.
for (int i=0; i < N; ++i){
    ddx.array[i][i] = - 2.0;    // Second spacial derivative

    double r_i = (i+1)*dr;
    V.array[i][i] = -1/r_i;
    if (i+1 < N){
        ddx.array[i+1][i] = 1.0;
        ddx.array[i][i+1] = 1.0;
    }
};

Matrix K = - (1/(2*dr*dr)) *ddx;
// K.print();
// V.print();

Matrix H = K + V;
// H.print();

EVD evd(H);  // Diagonalizing the Hamiltonian


if (input_type == "rmax_input"){
    std::cerr << "printed valoues of dr =" << rmax << "\n";
    std::cout << rmax << "   " << evd.w.array[0][0] << "\n";
}

if (input_type == "dr_input"){
    std::cerr << "printed valoues of dr =" << dr << "\n";
    std::cout << dr << "   " << evd.w.array[0][0] << "\n";
}


if (input_type == "wave_function"){
    for (int i=0; i < evd.V.get_rows(); ++i){
        double r_i = (i+1)*dr;
        std::cout << evd.w.array[i][0] << "   " << r_i << "   " << R_0(r_i) << "   " << R_1(r_i) << "   ";
        for (int j=0; j < evd.V.get_cols(); ++j){
            double Normalized_psi = std::pow(dr, -0.5) * evd.V.array[i][j] *(1/r_i); 
            std::cout << Normalized_psi << "   ";
        }
        std::cout << "" << "\n"; 
    }
}






}
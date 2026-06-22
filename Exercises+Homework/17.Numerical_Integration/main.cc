#include<iostream>
#include<cmath>
#include <numbers>
#include<vector>

int ncalls = 0;

#include "Integrate.h"
#include "Functions.h"


int main(int argc, char* argv[]) {
std::string input_type;

for(int i=0; i < argc; ++i){
    std::string arg=argv[i];    // Converting to string

    if(arg=="-printtype" && i+1 < argc){
        input_type = argv[i+1];
    }
} 


if(input_type == "Test_integrator"){   

    double q = Integrate(g,0,1);                                          // Integrating g(x) on the interval [0,1]
    std::cout << "int_{0}^{1} sqrt(x) dx = " << q << ",    " << "ncalls = " << ncalls << std::endl; 
    ncalls = 0;

    // -------------- Integral 2
    double q2 = Integrate(g2,0,1);   // Singularity at x = 0!
    std::cout << "int_{0}^{1} 1/(sqrt(x)) dx = " << q2 << ",    " << "ncalls = " << ncalls << std::endl; 
    ncalls = 0;
    // ------------- Integral 3
    double q3 = Integrate(g3,0,1); 
    std::cout << "int_{0}^{1} sqrt(1 - x^2) dx = " << q3 << ",    " << "ncalls = " << ncalls << std::endl; 
    ncalls = 0;

    // ------------- Integral 4
    double q4 = Integrate(g4,0,1); 
    std::cout << "int_{0}^{1} ln(x)/sqrt(x) dx = " << q4 << ",    " << "ncalls = " << ncalls << std::endl; 
    ncalls = 0;


    std::cout << "For all integrals, the first 3 digites behind the comma maches with the expected result, satisfying the accuracy of 0.001." << std::endl;
}



// Eror function

if(input_type == "Err_func"){   
    std::vector<double> X_list;
    std::vector<double> ERR_func;

    for (double i= -5.0; i < 5.0; i = i + 0.05){
        X_list.push_back(i);
        double ERR = erf(i, 0.001, 0.001);
        ERR_func.push_back(ERR);
        // std::cout << i << std::endl;
        std::cout << i << "    " << ERR << std::endl;
    }

}


if (input_type == "Test_acc"){
    for (int i = 1; i < 10; i++){
        double accuracy = std::pow(10, -i);
        double ERF = erf(1, accuracy ,0);
        std::cout << accuracy << "    " << ERF << std::endl;
    }
}


return 0;
}
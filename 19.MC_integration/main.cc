#include<iostream>
#include<cmath>
#include<numbers>

#include "MC.h"


double y(std::vector<double> x){
    return std::sqrt(1 - x[0]*x[0]);
};


double ellipsoid(std::vector<double> x){
    double a =1; double b = 2; double c = 3;

    double inside = 1.0 - (x[0]*x[0])/(a*a) - (x[1]*x[1])/(b*b) - (x[2]*x[2])/(c*c);
    if (inside < 0.0) {return 0.0;}                                                  
    else return 1.0;
}



int main(int argc, char* argv[]) {
std::string input_type;

for(int i=0; i < argc; ++i){
    std::string arg=argv[i];    // Converting to string

    if(arg=="-printtype" && i+1 < argc){
        input_type = argv[i+1];
    }
} 



if (input_type == "Area_of_hafe_circle"){
    std::vector<double> x_start = {-1.0, 0.0}; 
    std::vector<double> x_final = {1.0, 1.0}; 

    for (int i=2; i < 8; i++){
        int N_points = std::pow(10, i);
        auto [solution, estimated_error] = MC(y, x_start, x_final, N_points, 1001);
        double Actual_error = std::abs(std::numbers::pi/2 - solution);
        std::cout << N_points << "    " << solution << "    " << estimated_error << "    " << Actual_error << std::endl;
    }
};


if (input_type == "Volume"){
    std::vector<double> x_start = {-1.0, -2.0, -3.0}; 
    std::vector<double> x_final = {1.0, 2.0, 3.0}; 

    auto [solution, estimated_error] = MC(ellipsoid , x_start, x_final, 1000000, 1000001);
    std::cout << "Solution" << "    " << solution << "    " << "Estimated err =" << "    " << estimated_error << std::endl;
    std::cout << "The volume shood be:  V =" << "    " <<  (4*6* std::numbers::pi)/3  << std::endl;
}



return 0;
}
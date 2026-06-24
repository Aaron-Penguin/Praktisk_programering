#include<iostream>
#include<tuple>

#include "Matrix.h"
#include "QR.h"
#include "Gradient.h"
#include "Hessian.h"
#include "Newton.h"


std::tuple<double> Rosenbrock(std::vector<double> x){
    return (1 - x[0])*(1 - x[0]) + 100*std::pow(x[1] - x[0]*x[0] ,2) ;
}

std::tuple<double> Himmelblau(std::vector<double> x){
    return std::pow(x[0]*x[0] + x[1] -11 ,2) + std::pow(x[0] + x[1]*x[1] - 7,2);
}


int main(){

std::vector<double> x_init = {2,4};
auto [solution, steps] = Newton(Rosenbrock, x_init);
std::cout << "Rosenbrock: 1 lokal min:  (x,y) =" << "    (" << solution[0] << ", " << solution[1] << ")" << "    Steps =" << steps << std::endl;

std::vector<double> x_in2 = {3,4};
auto [solver2, steps2] = Newton(Himmelblau, x_in2);
std::cout << "Himmelblau: 1 lokal min:  (x,y) =" << "    (" << solver2[0] << ", " << solver2[1] << ")" << "    Steps =" << steps2 << std::endl;

return 0;
}
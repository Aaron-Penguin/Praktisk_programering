#include<iostream>

#include "Matrix.h"
#include "QR.h"
#include "Newton.h"
#include "Jacobian.h"


// Rosenbrock valley function's derivative

std::vector<double> d_Rosenbrock(std::vector<double> x){
    int dim = x.size();
    std::vector<double> df(dim);
    df[0] =  -2*(1-x[0]) -400*x[0] *(x[1] - x[0]*x[0]);
    df[1] = 200*(x[1] - x[0]);
    return df;
}



std::vector<double> d_Himmelblau(std::vector<double> x){    
    int dim = x.size();
    std::vector<double> df(dim);
    df[0] = 4*x[0] *(x[0]*x[0] + x[1] -11) + 2*(x[0] + x[1]*x[1] -7);        // x[0] = x;   x[1] = y;
    df[1] = 2*(x[0]*x[0] + x[1] -11) + 4*x[1]*(x[0] + x[1]*x[1] -7);
    return df;
}



// std::vector<double> linear(std::vector<double> x){
//     int dim = x.size();
//     std::vector<double> fx(dim);
//     for (int i=0; i < dim; i++){
//         fx[i] = x[i] - 2;
//     }
//     return fx;
// };



int main(){


std::vector<double> x_start1 = {1.3,1.3};
std::vector<double> x_0 = Newton(d_Rosenbrock, x_start1);
std::cout << "Rosenbrock ekstrema: x_0 =  " << x_0[0] << "  " << "y_0 =  " << x_0[1] << std::endl;

std::vector<double> x_start2 = {30.2,-20};
std::vector<double> x_1 = Newton(d_Rosenbrock, x_start2);
std::cout << "Rosenbrock ekstrema: x_1 =  " << x_1[0] << "  " << "y_1 =  " << x_1[1] << std::endl;

std::cout << "------------------------------------------" << std::endl;

// Himmelblau ekstrema
std::vector<double> x_him1 = Newton(d_Himmelblau, x_start1);
std::cout << "Himmelblau first ekstremum: x_0 =  " << x_him1[0] << "  " << "y_0 =  " << x_him1[1] << std::endl;

std::vector<double> x_him2 = Newton(d_Himmelblau, x_start2);
std::cout << "Himmelblau second ekstremum: x_0 =  " << x_him2[0] << "  " << "y_0 =  " << x_him2[1] << std::endl;

// std::vector<double> x_start3 = {-1.0,-1.0};
// std::vector<double> x_him3 = Newton(d_Himmelblau, x_start3);
// std::cout << "Himmelblau third ekstremum: x_0 =  " << x_him3[0] << "  " << "y_0 =  " << x_him3[1] << std::endl;

std::vector<double> x_start4 = {-4.0,-4.0};
std::vector<double> x_him4 = Newton(d_Himmelblau, x_start4);
std::cout << "Himmelblau fourth ekstremum: x_0 =  " << x_him4[0] << "  " << "y_0 =  " << x_him4[1] << std::endl;

std::vector<double> x_start5 = {-6.0,6.0};
std::vector<double> x_him5 = Newton(d_Himmelblau, x_start5);
std::cout << "Himmelblau fifth ekstremum: x_0 =  " << x_him5[0] << "  " << "y_0 =  " << x_him5[1] << std::endl;

return 0;
}
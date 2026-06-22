
#include "Jacobian.h"
#include<cmath>



std::tuple<Matrix> Jacobian(std::function<std::vector<double>(std::vector<double>)> f,
    std::vector<double> x,
    std::vector<double> fx){

        int dim = x.size(); 
        std::vector<double> dx(dim);
        for (int i=0; i < dim; i++){
            dx[i] = std::max(std::abs(x[i]), 1.0) * std::pow(2,-26);           // Ai,  ensuring that dx don't becomes to small leading to devision with 0. 
        }
        Matrix J(dim, dim, 0.0);                         // Empty n*n matrix
        std::vector<double> df(dim);
        std::vector<double> func_val(dim);
        for (int j =0; j < dim; j++){
            x[j] += dx[j];
    
            for (int i =0; i < dim; i++){
                J.array[i][j] =  (f(x)[i] - fx[i] )  /dx[j];
            }
            x[j] -=dx[j];
        }
        return std::make_tuple(J);
};
#include "function.h"
#include<cmath>
#include<numbers>


std::vector<double> f(std::vector<double> x){
    double dim = x.size();
    std::vector<double> v(dim);
    for (int i =0; i < dim; i++){
        v[i] = std::sin(2*std::numbers::pi*x[i])*std::cos(16*std::numbers::pi*x[i])*std::exp(x[i]);
    return v;
};

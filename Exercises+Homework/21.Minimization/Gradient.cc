#include "Gradient.h"
#include<cmath>

std::vector<double> gradient(std::function<std::tuple<double>(std::vector<double>)> φ,std::vector<double> x){
    auto [φx] = φ(x);
    int dim = x.size(); 
    std::vector<double> gφ(dim);
    for (int i=0; i < dim; i++){
        double dxi = (1+ std::abs(x[i]))*std::pow(2, -26);
        x[i] += dxi;
        auto [φx_new] = φ(x); 
        gφ[i] = (φx_new -φx)/dxi;
        x[i]-=dxi;
    }
    return gφ;
}
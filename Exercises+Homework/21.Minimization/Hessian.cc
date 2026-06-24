#include "Hessian.h"

std::tuple<Matrix> Hessian(std::function<std::tuple<double>(std::vector<double>)> φ,std::vector<double> x){
    int dim = x.size(); 
    Matrix H(dim, dim, 0.0);
    std::vector<double> gφx = gradient(φ,x);

    for (int j=0; j < dim; j++){
        double dxj=(1+abs(x[j]))*std::pow(2,-13);
        x[j]+=dxj;
        std::vector<double> dgφ(dim);
        for (int i=0; i < dim; i++){
            dgφ[i] = gradient(φ,x)[i] + gφx[i];
            H.array[i][j] = dgφ[i]/dxj;
        }
        x[j] -= dxj;
    }
    return std::make_tuple(H);
}


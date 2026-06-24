#include<vector>
#include<functional>
#include<cmath>
#include<iostream>

#include "Newton.h"
#include "Gradient.h"
#include "Matrix.h"
#include "Hessian.h"
#include "QR.h"


double norm(std::vector<double> v){
    double l2 = 0.0;
    int dim = v.size(); 
    for (int i =0; i < dim; i++){
        l2 += v[i]*v[i];
    }
    return std::sqrt(l2);
}

// Addition for vectors
static std::vector<double> operator+(const std::vector<double>& a, const std::vector<double>& b){
    int dim = a.size();
    std::vector<double> r(dim);
    for (int i=0; i< dim ;++i){
        r[i] = a[i]+b[i];
    }
    return r;
}

// Multiplication of vector and double
static std::vector<double> operator*(const double alpha, const std::vector<double>& a){
    int dim = a.size();
    std::vector<double> r(dim);
    for (int i=0; i< dim ;++i){
        r[i] = alpha*a[i];
    }
    return r;
}



std::tuple<std::vector<double>,double> Newton(std::function<std::tuple<double>(std::vector<double>)> φ,std::vector<double> x, int Steps,double acc){
    int step = 0;
    for (int i =0; i < Steps; i++){
        // std::cerr << "Steps =  " << i+1 << std::endl;

        std::vector<double> grad = gradient(φ, x);
        // std::cerr << "Found gradient" << std::endl;
        if (norm(grad) < acc){
            break;
        }
        auto [H] = Hessian(φ,x);
        // std::cerr << "Found Hessian" << std::endl;
        for (int j =0; j < H.get_rows(); j++){
            H.array[j][j] += 1e-6;
        }

        int dim = grad.size();
        Matrix b(dim, 1, 0.0);
        Matrix X(dim, 1,0.0);
        for (int j=0; j < dim; j++){
            X.array[j][0] = x[j];
            b.array[j][0] = -grad[j];                // Converting x to Matrix type. This is relevant since my QR class only can handle Matrix objekts.
        }
        QR qr(H);
        Matrix Delta_x = qr.solve(b);               // Direction for minimization of phi
        // std::cerr << "Found dx" << std::endl;

        // std::cerr << "dim=" << dim << std::endl;
        std::vector<double> delta_x(dim);
        for (int k =0; k < dim; k++){
            delta_x[k] = Delta_x.array[k][0];
            // std::cerr << Delta_x.array[k][0]<< std::endl;
        }

        double lamb = 1.0;
        while (lamb >= 1.0/128.0){
            std::cerr << "lamb = " << lamb << std::endl;
            std::vector<double> x_new = x + (lamb*delta_x);
            auto [φ_now] = φ(x_new);
            auto [φ_old] = φ(x);
            if (φ_now < φ_old){
                break;
            }
            lamb /= 2;
        }
        // std::cout << "Finished while loop" << std::endl;
        x = x + lamb*delta_x;
        step = i+1;
    }
    return std::make_tuple(x, step);
}
#include<vector>
#include<tuple>
#include<functional>
#include<cmath>
#include<iostream>

#include "Newton.h"
#include "Jacobian.h"
#include "QR.h"


double norm(std::vector<double> v){
    double l2 = 0.0;
    int dim = v.size(); 
    for (int i =0; i < dim; i++){
        l2 += v[i]*v[i];
    }
    return std::sqrt(l2);
}



std::vector<double> Newton(
    std::function<std::vector<double>(std::vector<double>)> f,
    std::vector<double> x,
    double acc,
    double alpha_min,
    int max_iter){
        std::vector<double> fx = f(x);
        int dim = fx.size();

        Matrix mat_b(dim, 1, 0.0);              // fx agian but now as my Matrix class
        Matrix X(dim, 1, 0.0);


        for (int i=0; i < max_iter; i++){

            for (int j =0; j < dim; j++){
                mat_b.array[j][0] = - fx[j];
                X.array[j][0] = x[j];
            }
            
            if (norm(fx) < acc){
                break;
            }
            auto [J] = Jacobian(f, x, fx);
            QR qr(J); 
            Matrix Delta_x = qr.solve(mat_b);       // (Eq.5) in the note.
            double alpha = 1.0;

            std::vector<double> z(dim);
            std::vector<double> fz(dim);
            while (true){      // Remove the infinite loop!
                Matrix Z = X + alpha*Delta_x;
                
                for (int j=0; j < dim; j++){
                    z[j] = Z.array[j][0];
                }
                fz = f(z);
                if (norm(fz) < (1-alpha/2)*norm(fx)){
                    break;
                }
                if (alpha < alpha_min){
                    break;
                }
                alpha /=2;
            }
            x = z;
            fx = fz;
            std::cout << "Norm of fx =" << norm(fx) << std::endl;
        }
        return x;
};



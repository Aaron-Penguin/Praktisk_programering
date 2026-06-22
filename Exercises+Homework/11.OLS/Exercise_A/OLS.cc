#include "OLS.h"


OLS::OLS(int order ,std::vector<std::function<double(double)>> func,std::vector<double> x_dat, std::vector<double> y_dat, std::vector<double> sigma_y)
    : n(order), Fit_funcs(std::move(func)), x(std::move(x_dat)), y(std::move(y_dat)), y_err(std::move(sigma_y)),
    A(x.size(), order, 0), b(x.size(), 1, 0), c(Fit_funcs.size(), 1, 0), C_cov(order, order, 0){
    
    if (x.size() != y.size() || x.size() != y_err.size()){
        std::cerr << "Shapes of the initial x_data, y_data and y_err, must all be the same. There shapes do not match!" << "\n";
    } else {

        int I = static_cast<int>(x.size());
        // int K = static_cast<int>(Fit_funcs.size());

        for (int i=0; i < I; ++i){
            b.array[i][0] = y[i]/y_err[i];
            for (int k=0; k < n; ++k){
                A.array[i][k] = Fit_funcs[k](x[i])/y_err[i];
            }
        }

        QR qr(A);
        Matrix c_i = qr.solve(b);
        for (int k= 0; k < n; ++k){
            c.array[k][0] = c_i.array[k][0];
        }

        // Finding the covariance_matrix
        Matrix K = A.T()*A; 
        QR qr_new(K);
        // K.print();
        Matrix Inverse = qr_new.Inverse();
        
        for (int i=0; i < n; ++i){
            for (int j=0; j < n; ++j){
                C_cov.array[i][j] = Inverse.array[i][j];
            }

        }
    }
};
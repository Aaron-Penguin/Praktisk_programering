#ifndef OLS_H
#define OLS_H

#include<iostream>
#include<vector>
#include<functional>

#include "Matrix.h"
#include "QR.h"

class OLS{
public:
    int n;   // Order of the fit
    std::vector<std::function<double(double)>> Fit_funcs;   // basis functions for fit

    std::vector<double> x;   // Data
    std::vector<double> y;
    std::vector<double> y_err;

    Matrix A;   // Matrix's used to determine the fit using QR
    Matrix b;

    Matrix c;   // Fittet parameters
    Matrix C_cov;

    // OLS(std::vector<double> x_dat, std::vector<double> y_dat, std::vector<double> sigma_y);
    OLS(int order ,std::vector<std::function<double(double)>> func, std::vector<double> x_dat, std::vector<double> y_dat, std::vector<double> y_err);

};
#endif // OLS_H


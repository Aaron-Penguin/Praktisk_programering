#include "binsearch.h"
#include "qspline.h"


// --- Constructor ---
Qspline::Qspline(std::vector<double> x, std::vector<double> y):x(x), y(y){
    int n_x = x.size();

    std::vector<double> p(n_x - 1);
    std::vector<double> c_up(n_x - 1);
    std::vector<double> c_down(n_x - 1);

    for (int i =0; i < n_x-1; i++){
        p[i] = (y[i+1] - y[i])/(x[i+1] - x[i]);
    }
    for (int i=0; i < n_x-2; i++){
        c_up[i+1] = (p[i+1] - p[i] - c_up[i]*(x[i+1] - x[i]) )/(x[i+2] - x[i+1]);     // Recursion up
    }
    c_down[n_x - 1] = c_up[n_x - 1];
    for (int i = n_x - 2; i >=0; i--){
        c_down[i] = (p[i+1] - p[i] - c_down[i+1]*(x[i+2]-x[i+1]))/(x[i+1] - x[i])  ;  // Recursion down
    }

    for (int i=0; i < n_x - 1; i++){
        double c_i = (c_down[i] + c_up[i])/2; 
        double b_i = p[i] - c_i*(x[i+1] - x[i]);
        b.push_back(b_i);
        c.push_back(c_i);
    }
};

// Function that returns the new interpoleted valoue of y.
double Qspline::eval(double z){
    int i = binsearch(x,z);
    double s_i = y[i] + b[i]*(z - x[i]) + c[i]*(z-x[i])*(z-x[i]);
    return s_i;
};
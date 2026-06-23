#ifndef LINEAR_SPLINE
#define LINEAR_SPLINE

#include<vector>

double linterp(std::vector<double> x, std::vector<double> y, double z);
double linterpInteg(std::vector<double> x, std::vector<double> y, double z);

#endif
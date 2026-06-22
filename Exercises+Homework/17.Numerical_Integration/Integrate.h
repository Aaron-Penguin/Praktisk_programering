#ifndef INTEGRATE_H
#define INTEGRATE_H

#include<functional>
#include<limits>

using NaN = std::numeric_limits<double>;

double Integrate(std::function<double(double)> f,
    double a,
    double b,
    double acc=0.001,
    double eps=0.001,
    double f2 = NaN::quiet_NaN(),
    double f3 = NaN::quiet_NaN());


#endif
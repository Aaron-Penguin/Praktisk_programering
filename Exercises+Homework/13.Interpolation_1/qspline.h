#ifndef QSPLINE_H
#define QSPLINE_H

#include<vector>

struct Qspline{
    std::vector<double> x;
    std::vector<double> y;
    std::vector<double> b;
    std::vector<double> c;

    Qspline(std::vector<double> x, std::vector<double> y);


    double eval(double z);
};


#endif
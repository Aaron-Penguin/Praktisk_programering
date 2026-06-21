#ifndef DRIVER_H
#define DRIVER_H

#include<tuple>
#include<functional>
#include <cstddef>


using vector = std::vector<double>;

std::tuple<std::vector<double>,std::vector<vector>> driver(
    std::function<vector(double, const vector&)> F,
    double a, double b,
    vector yinit,
    double h = 0.125,
    double acc = 0.01,
    double eps = 0.01
);


#endif
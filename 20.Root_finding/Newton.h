#ifndef NEWTON_H
#define NEWTON_H

#include<vector>
#include<tuple>
#include<functional>



std::vector<double> Newton(
    std::function<std::vector<double>(std::vector<double>)> f,
    std::vector<double> x,
    double acc = 1e-3,
    double alpha_min = 1e-3,
    int max_iter = 100);


#endif
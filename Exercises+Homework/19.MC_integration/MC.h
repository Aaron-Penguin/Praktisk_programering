#ifndef MC_H
#define MC_H


#include<tuple>
#include<vector>
#include<functional>

std::tuple<double, double> MC(
    std::function<double(std::vector<double>)> f,
    std::vector<double> a,
    std::vector<double> b,
    int N,
    int resolution = 1001); 

#endif
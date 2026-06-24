#ifndef GRADIENT_H
#define GRADIENT_H

#include<vector>
#include<functional>

std::vector<double> gradient(std::function<std::tuple<double>(std::vector<double>)> φ,std::vector<double> x);
#endif
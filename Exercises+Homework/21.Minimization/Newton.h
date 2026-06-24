#ifndef NEWTON_H
#define NEWTON_H

#include<vector>
#include<functional>

double norm(std::vector<double> v);

std::tuple<std::vector<double>,double> Newton(std::function<std::tuple<double>(std::vector<double>)> φ,std::vector<double> x, int Steps = 100000,double acc=1e-3);


#endif
#ifndef HESSIAN_H
#define HESSIAN_H

#include<functional>
#include<vector>
#include<tuple>
#include<cmath>

#include "Matrix.h"
#include "Gradient.h"

std::tuple<Matrix> Hessian(std::function<std::tuple<double>(std::vector<double>)> φ,std::vector<double> x);

#endif
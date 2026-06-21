#ifndef JACOBIAN_H
#define JACOBIAN_H

#include<functional>
#include "Matrix.h"


std::tuple<Matrix> Jacobian(std::function<std::vector<double>(std::vector<double>)> f,
    std::vector<double> x,
    std::vector<double> fx);



#endif
#ifndef RK12_H
#define RK12_H

#include<tuple>
#include <cstddef>
#include<functional>

using vector = std::vector<double>;


std::tuple<vector, vector> rkstep12(                   // Based on Dmitri's code, with minor modifications
	std::function<vector(double, const vector)> f, /* the f from dy/dx=f(x,y) */
	double x,                    /* the current value of the variable */
	const vector& y,                   /* the current value y(x) of the sought function */
	double h                     /* the step to be taken */
	);


#endif

#ifndef SFUNS_H
#define SFUNS_H
//  ---------
#include <numbers>  // To import constants
#include<complex>
#include<iostream>

using complex = std::complex<double>;

constexpr double PI = std::numbers::pi; // c++20;
constexpr double e = std::numbers::e; // c++20;
constexpr complex I = complex(0,1);

double compute_sqrt(double x);

double Take_eksponent(double x, double n);

complex Complex_exp(double x, complex n);

complex Comp_comp_exp(complex x, complex n);



//     constexpr double PI = std::numbers::pi; // c++20;
//     constexpr double e = std::numbers::e; // c++20;
//     constexpr complex I = complex(0,1);

//     double compute_sqrt(double x);
//     double Take_eksponent(double x, double n);
// }


// -----------
#endif
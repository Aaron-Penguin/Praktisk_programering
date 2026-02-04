
#ifndef SFUNS_H
#define SFUNS_H
//  ---------
#include <numbers>  // To import constants

namespace sfuns {
    double compute_sqrt(double x);
    double Take_eksponent(double x, double n);
    
    constexpr double PI = std::numbers::pi; // c++20;
    constexpr double e = std::numbers::e; // c++20;
}


// -----------
#endif
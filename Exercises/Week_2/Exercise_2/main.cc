#include "header.h"
#include<iostream>

int main() {
    double x = 1.0; 
    double gamma_func = sfuns::fgamma(x);
    std::cout << "Gamma("<< x << ") =" << gamma_func << "\n"; 
}
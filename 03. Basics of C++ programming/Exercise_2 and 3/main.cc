#include "header.h"
#include<iostream>

int main() {
    std::cout << "Gammafunction recusive formula,   Gammafunction with stirlings approximation to 5'th order" << "\n"; 
    for (double i = 1; i < 11; i++) {
        double gamma_func = sfuns::fgamma(i);
        long double gamma_stir = sfuns::stirling_gamma(i);

        std::cout << "Gamma("<< i << ") =" << gamma_func << "   Gamma_stir("<< i <<") =" << gamma_stir << "\n";}
    for (double i = 11; i < 21; i++) {
        double gamma_func = sfuns::fgamma(i);
        std::cout << "Gamma("<< i << ") =" << gamma_func << "\n";
    }
}
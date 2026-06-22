#include "header.h"
#include<iostream>


int main() {
    double x_val;

    std::cout << "Enter a number as type (double) as the function imput:\n ";
    std::cin >> x_val;   // We choose x_val = 2 when computing Out.txt
    

    double Result_square = compute_sqrt(x_val);
    double Result_pow = Take_eksponent(x_val,  0.2);
    double e_raised_with_pi =  Take_eksponent(e, PI);
    double pi_raised_with_e = Take_eksponent(PI, e);
    complex pi_raised_with_i = Complex_exp(PI,I);
    complex e_pow_i = Complex_exp(e, I);
    complex i_pow_i = Comp_comp_exp(I, I);

    std::cout << "sqrt(" << x_val << ") = " << Result_square << std::endl;
    std::cout << "(" << x_val << ")^1/5 =" << Result_pow << std::endl; 
    std::cout << "(e)^pi =" << e_raised_with_pi << std::endl;
    std::cout << "(pi)^e =" << pi_raised_with_e << std::endl;
    std::cout << "(pi)^i =" << pi_raised_with_i << std::endl;
    std::cout << "(e)^i =" << e_pow_i << std::endl;
    std::cout << "(i)^i =" << i_pow_i << std::endl;
    std::cout << "log(I)=" << std::log(I) << "\n";
    return 0;
}

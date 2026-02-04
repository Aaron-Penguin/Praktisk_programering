#include "header.h"
#include<iostream>


int main() {
    double x_val;

    std::cout << "Enter a number as type (double) as the function imput:\n ";
    std::cin >> x_val;   // We choose x_val = 2 when computing Out.txt
    

    double Result_square = sfuns::compute_sqrt(x_val);
    double Result_pow = sfuns::Take_eksponent(x_val,  0.2);
    double e_raised_with_pi =  sfuns::Take_eksponent(sfuns::e, sfuns::PI);
    double pi_raised_with_e = sfuns::Take_eksponent(sfuns::PI, sfuns::e);

    std::cout << "sqrt(" << x_val << ") = " << Result_square << std::endl;
    std::cout << "(" << x_val << ")^1/5 =" << Result_pow << std::endl; 
    std::cout << "(e)^pi =" << e_raised_with_pi << std::endl;
    std::cout << "(pi)^e =" << pi_raised_with_e << std::endl; 
    return 0;
}

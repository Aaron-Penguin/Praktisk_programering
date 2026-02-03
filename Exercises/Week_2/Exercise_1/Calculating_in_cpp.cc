#include<iostream>
#include<cmath>


// function declaration (optional but common)
double compute_sqrt(double x);
long double Take_eksponent(long double x, long double n);


int main() {
    long double pi = 3.14159265358979323846;
    long double e = 2.71828182845904523536;
    double x_val;

    std::cout << "Enter a number as type (double) as the function imput:\n ";
    std::cin >> x_val;   // We choose x_val = 2 when computing Out.txt
    
    // ---- Choosing between diffrent computations
    // int method;
    // std::cout << "Enter the number of the choosen computation:\n";
    // std::cout << "1) Square root\n";
    // std::cout << "2) To the power of 1/5 \n";
    // std::cout << "Choice: ";
    // std::cin >> method;

    // if (method == 1) {
    //     double result = compute_sqrt(x_val);
    //     std::cout << "sqrt(" << x_val << ") = " << result << std::endl;
    // }
    // else if (method == 2) {
    //     double result = Take_eksponent(x_val);
    //     std::cout << "(" << x_val << ")^1/5 = " << result << std::endl;
    // }
    // else {
    //     std::cout << " Method not avialable " << std::endl;
    // }
    //  ----------------------------------------------
    double Result_square = compute_sqrt(x_val);
    long double Result_pow = Take_eksponent(x_val,  0.2);
    long double e_raised_with_pi =  Take_eksponent(e, pi);
    long double pi_raised_with_e = Take_eksponent(pi, e);

    std::cout << "sqrt(" << x_val << ") = " << Result_square << std::endl;
    std::cout << "(" << x_val << ")^1/5 =" << Result_pow << std::endl; 
    std::cout << "(e)^pi =" << e_raised_with_pi << std::endl;
    std::cout << "(pi)^e =" << pi_raised_with_e << std::endl; 
    return 0;
}

// function definition
double compute_sqrt(double x) {
    return std::sqrt(x);
}

long double Take_eksponent(long double x, long double n) {
    return std::pow(x, n);
}
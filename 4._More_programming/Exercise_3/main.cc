#include<iostream>
#include<cmath>
#include<iomanip>



bool approx(double a, double b, double acc = 1e-9) {
        double diff = std::abs(a - b);
        // double max_ab = std::max(std::abs(a), std::abs(b));

        if (diff <= acc) return true;  // absolute tolerance
        else {return false;}
}   

int main() {
    double d1 = 0.1+0.1+0.1+0.1+0.1+0.1+0.1+0.1;
    double d2 = 8*0.1;
    bool approx(double a, double b, double acc = 1e-9);

    std::cout << "d1==d2? " << (d1==d2 ? "true":"false") << "\n";   // matematicaly true, but rounding error gives false

    std::cout << std::fixed << std::setprecision(17);
    std::cout << "d1=" << d1 << "\n";
    std::cout << "d2=" << d2 << "\n";

    double number = 8;
    double tiny_number = std::pow(2, -10);


    std::cout << "Testing (a == b) =>" << approx(number, tiny_number, 1e-9) << "\n";
    return 0;
}

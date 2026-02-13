#include<iostream>
#include<limits>
#include<cmath>

int main() {
    float f= 1.0f; while((float)   (1.0f+f) != 1.0f){f/=2.0f;} f*=2.0f;
    double d=1.0d; while((double)     (1.0d+d) != 1.0d){d/=2.0d;} d*=2.0d;
    long double l=1.0L; while((long double)(1.0L+l) != 1.0L){l/=2.0L;} l*=2.0L;

    float f_sys = std::numeric_limits<float>::epsilon();
    double d_sys = std::numeric_limits<double>::epsilon();
    long double l_sys = std::numeric_limits<long double>::epsilon();

std::cout << "float epsilon from loop =" << f << "    float epsilon from system = " << f_sys << "   Shood equal to (2)^-23 =" << std::pow(2, -23) << "\n" ;
std::cout << "double epsilon from loop =" << d << "   double epsilon from system = " << d_sys << "   Shood equal to (2)^-52 =" << std::pow(2, -52) << "\n" ;
std::cout << "long doube epsilon from loop =" << l << "  long double epsilon from system = " << l_sys << "\n" ;
    return 0;
}

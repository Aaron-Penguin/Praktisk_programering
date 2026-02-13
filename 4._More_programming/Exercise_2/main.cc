#include<iostream>
#include<limits>
#include<cmath>
#include<iomanip>

int main() {
    double epsilon = std::numeric_limits<double>::epsilon();
    double tiny = epsilon/2.0f;

    double a= 1.0f +tiny+tiny; // should be 1+epsilon, that is, larger than 1, no?
    double b= tiny+tiny+ 1.0f; // should be the same mathematically, no?
    std::cout << " 1 + epsi/2 + epsi/2 = " << a << "\n";
    std::cout << " epsi/2 + epsi/2 + 1 = " << b << "\n";

    std::cout << "a==b ? " << (a==b ? "true":"false") << "\n";
    std::cout << "a>1  ? " << (a>1  ? "true":"false") << "\n";
    std::cout << "b>1  ? " << (b>1  ? "true":"false") << "\n";

    std::cout << std::fixed << std::setprecision(17);
    std::cout << "       tiny=" << tiny << "\n";
    std::cout << "1+tiny+tiny=" << a << "\n";
    std::cout << "tiny+tiny+1=" << b << "\n";    // a and b are diffrent. When adding a number smaller than the machine epsilon to 1, the machine just approximates it to 1. But when adding the smal numbers first, this samll contribution can not be neglected since it is the leading contribution.  
    return 0;
}

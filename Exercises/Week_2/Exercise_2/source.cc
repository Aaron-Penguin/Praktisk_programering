#include<cmath>
#include<numbers> // c++20
#include"header.h"


namespace sfuns{
constexpr double PI = std::numbers::pi; // c++20
constexpr double e = std::numbers::e;

// constexpr double PI = 3.14159265358979323846; // pre- c++20
double fgamma(double x){
	if(x<0)return PI/std::sin(PI*x)/fgamma(1-x);
	if(x<9)return fgamma(x+1)/x;
	double lnfgamma=x*std::log(x+1/(12*x-1/x/10))-x+std::log(2*PI/x)/2;
	return std::exp(lnfgamma);
	}

// double stirling_gamma(double x){return std::pow(x,x) * std::pow(e,-x);}

long double stirling_gamma(double n){
	if(n==1) {return 1;}
	else {return std::sqrt(2* PI* (n-1)) * std::pow( (n-1)/e,  (n-1) ) * std::pow(e,
(1/(12* (n-1)) - 1/(360* std::pow(n-1, 3))  + 1/(1260* std::pow(n-1, 5))   ))  ;}}    // n! approx sqrt(2 pi n)* (n/e)^n,  Gamma(n) = (n -1)!
}
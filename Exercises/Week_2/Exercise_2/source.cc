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

double stirling_gamma(double x){return std::sqrt(2* PI) * std::pow(x, x - 0.5) * std::pow(e, -x) ;}

}
#include<cmath>
#include <numbers>
#include<iostream>

#include "Functions.h"
#include "Integrate.h"


extern int ncalls;
double g(double x){
    ::ncalls += 1;      // Acting on global variables: From AI
    if (x < 0.0){return NaN::quiet_NaN();}
    else {return std::sqrt(x);}
}; 

double g2(double x){
    ::ncalls +=1;
    if (x <= 0.0){return NaN::quiet_NaN();}
    else {return  1/(std::sqrt(x));}
}

double g3(double x){
    ::ncalls +=1;
    if (x > 1.0 || x < -1.0){return NaN::quiet_NaN();}
    else {return  (std::sqrt(1 - std::pow(x,2) ));}
}

double g4(double x){
    ::ncalls +=1;
    if (x <= 0.0){return NaN::quiet_NaN();}
    else {return  std::log(x)/(std::sqrt(x));}
}


double gausian(double x){
    return std::exp( -std::pow(x,2) );
}

double gaussian_like(double x, double t){
    return 1/(std::pow(t,2)) * std::exp( -std::pow(x + (1.0 - t) / t, 2) );   
}


double erf(double x, double ACC, double EPS){
    // std::cout << "erf() is called" << std::endl;
    ::ncalls +=1;
    if (x < 0.0){
        return - erf(-x, ACC, EPS);
    }
    if (x <= 1.0){
        return 2.0/(std::sqrt(std::numbers::pi))* Integrate(gausian ,0.0,x, ACC, EPS,
                                                       std::numeric_limits<double>::quiet_NaN(),
                                                       std::numeric_limits<double>::quiet_NaN());   // ----------    From AI --- Begins here
    }
    else {
        auto f = [x](double t) {
        return gaussian_like(x, t);
    };                                  // ---------- From AI ---- Ends here
        return 1 - 2.0/std::sqrt(std::numbers::pi)* Integrate(f,0.0,1.0, ACC, EPS,
                                                       std::numeric_limits<double>::quiet_NaN(),
                                                       std::numeric_limits<double>::quiet_NaN());
    }
};

#include<iostream>
#include<tuple>
#include <cstddef>
#include<functional>
// #include<cmath>

using vector = std::vector<double>;


// Operator overloading for Runge Kuta --  Chat-GPT
static vector operator+(const vector& a, const vector& b){
    vector r(a.size());
    for(std::size_t i=0;i<a.size();++i) r[i]=a[i]+b[i];
    return r;
}
static vector operator-(const vector& a, const vector& b){
    vector r(a.size());
    for(std::size_t i=0;i<a.size();++i) r[i]=a[i]-b[i];
    return r;
}
static vector operator*(const vector& a, double s){
    vector r(a.size());
    for(std::size_t i=0;i<a.size();++i) r[i]=a[i]*s;
    return r;
}
static vector operator*(double s, const vector& a){ return a*s; }

// -----------------------

std::tuple<vector, vector> rkstep12(
	const std::function<vector(double, const vector&)>& f, /* the f from dy/dx=f(x,y) */
	double x,                    /* the current value of the variable */
	const vector& y,                   /* the current value y(x) of the sought function */
	double h                     /* the step to be taken */
	)
{
	vector k0 = f(x,y);              /* embedded lower order formula (Euler) */   // (Eq.32)
	vector k1 = f(x+h/2, y+ k0*(h/2)); /* higher order formula (midpoint) */        // (Eq.33)  with alpha = 1/2
	vector yh = y+k1*h;              /* y(x+h) estimate */
	vector δy = (k1 - k0)*h;           /* error estimate */     // (Eq.34) - (Eq.24) 
	return std::make_tuple(yh,δy);
}


int main(){

std::cout << "Hello world" << std::endl;


return 0;
}



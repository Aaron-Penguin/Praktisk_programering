
#include<tuple>
#include <cstddef>
#include<functional>
#include<cmath>

#include "RK12.h"
#include "Driver.h"

using vector = std::vector<double>;


static double norm(const vector v){
   int N = v.size();
    double L = 0.0;
   for (int i =0; i < N; i++){
        L += v[i]*v[i];
   }
   double l = std::sqrt(L);
   return l;
}


// --- The Driver is based on Dimitri's code
std::tuple<std::vector<double>,std::vector<vector>> driver(
    std::function<vector(double, const vector&)> F,
    double a, double b,
    vector yinit,
    double h,
    double acc,
    double eps
)
{
double x=a; vector y(yinit);
std::vector<double> xlist; xlist.push_back(x);
std::vector<vector> ylist; ylist.push_back(y);
do{
	if(x>=b) return std::make_tuple(xlist,ylist);                   /* job done */
	if(x+h>b) h = b-x;                                              /* last step should end at b */
	auto [yh,δy] = rkstep12(F,x,y,h);
	double tol = (acc+eps* norm(yh)) * std::sqrt(h/(b-a));          // (Eq.9) Calculating the tolerance 
	double err = norm(δy);
	if(err<=tol){ // accept step
		x+=h; y=yh;
		xlist.push_back(x);
		ylist.push_back(y);
		}
	if(err>0) h *= std::min( std::pow(tol/err,0.25)*0.95 , 2.0); // readjust stepsize
	// else h*=2;
	}while(true);
}//driver
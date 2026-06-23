#include<assert.h>

#include "Linear_spline.h"
#include "binsearch.h"

double linterp(std::vector<double> x, std::vector<double> y, double z){        // Initial data (x,y), New data points.
	int i=binsearch(x,z);
  	double dx=x[i+1]-x[i];
  	assert(dx>0);
  	double dy=y[i+1]-y[i];
  	return y[i]+dy/dx*(z-x[i]);
}

double linterpInteg(std::vector<double> x, std::vector<double> y, double z){     // We just use the interpolated data
	int i = binsearch(x,z);
	double dx = x[i+1] - x[i];
    assert(dx > 0);
    double dy = y[i+1] - y[i];
	double dz= z -x[i];
	return y[i]* dz + 1/2 *dy/dx * dz * dz;
}

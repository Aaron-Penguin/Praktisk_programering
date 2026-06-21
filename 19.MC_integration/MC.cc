#include<tuple>
#include<vector>
#include<functional>
#include<cmath>
#include<iostream>
// #include <cstddef>

#include "MC.h"

std::tuple<double, double> MC(
    std::function<double(std::vector<double>)> f,         // vector as input and double as output, This is the function we want to integrate.
    std::vector<double> a,
    std::vector<double> b,
    int N,
    int resolution){                      

        int dim = a.size();
        // std::cout << "dim = " << dim << std::endl;
        double V = 1.0;
        
        for (int i=0; i < dim; i++){
            V *= b[i] - a[i];
        }
        double sum1 = 0.0;  double sum2 = 0.0;
        std::vector<double> x(dim);                                      // Initialize the vector, descibing a point like coordinate.
        
        for (int j=0; j < N; j++){
            for (int i=0; i < dim; i++){
                double Random_num = (rand() % resolution);
                double Random_scaled = Random_num/resolution;

                // std::cout << Random_scaled << std::endl;
                x[i] = a[i] + Random_scaled *(b[i] - a[i]);
            }
            double fx = f(x);
            // if (x[dim-1] < fx){
            // std::cout << fx << std::endl;
            sum1 += fx;
            sum2 += fx*fx;
            
        }
        double mean = sum1/N;                                            // mean of f(x) over the region of integration
        double sigma = std::sqrt(sum2/N - std::pow(mean,2));             // sigma = sqrt( <f^2>  - <f>^2 ). Spread in f(x).
        double Integrated_volume = mean*V;
        double Error = sigma*V/std::sqrt(N);                             // estimeted error of integration (Eq.3)
        return std::make_tuple(Integrated_volume, Error) ;           
    }; 


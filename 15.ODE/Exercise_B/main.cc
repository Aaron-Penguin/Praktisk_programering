#include<iostream>
#include<cmath>
#include<numbers>

#include "RK12.h"
#include "Driver.h"

using vector = std::vector<double>;

// We want to solve u''(phi) + u(phi) = 1 + epsilon u(phi)^2

vector f(double eps ,double phi, const vector y) {         
    vector dy(2);
    dy[0] = y[1];
    dy[1] = -y[0] + 1 + eps*y[0]*y[0];
    return dy;
}


 vector Newtonian(double Phi, const vector Y){
    double EPSI = 0.0;
    return f(EPSI, Phi, Y);
    };

 vector GR(double Phi, const vector Y){
    double EPSI = 0.01;
    return f(EPSI, Phi, Y);
    };


int main(int argc, char* argv[]) {

std::string input_type;

for(int i=0; i < argc; ++i){
    std::string arg=argv[i];    // Converting to string

    if(arg=="-printtype" && i+1 < argc){
        input_type = argv[i+1];
    }
}





if(input_type == "Solver_1"){
    vector vec = {1, 0};   //Initial valoues 
    
    std::tuple Solution = driver(Newtonian, 0, 100, vec);
    auto [theta, u] = Solution;
    // std::vector<double> a = Solution{0};

    int I = static_cast<int>(theta.size());

    for (int i=0; i < I; i++){
        double r = 1/(u[i][0]);

        auto two_pi = 2.0L * std::numbers::pi;
        auto vinkel = std::fmod(static_cast<long double>(theta[i]), two_pi);
        // std::cout << vinkel << "   " << r << std::endl;
        if (vinkel <= std::numbers::pi/2){
            double x = r*std::cos(vinkel);
            double y = r*std::sin(vinkel);  
            std::cout << x << "   " << y << std::endl;
        }
        else if (vinkel < std::numbers::pi){
            double v = std::numbers::pi - vinkel;
            double x = -r*std::cos(v);
            double y = r*std::sin(v);  
            std::cout << x << "   " << y << std::endl;
        }
        else if (vinkel < (3* std::numbers::pi)/2 ){
            double v = vinkel - std::numbers::pi ;
            double x = -r*std::cos(v);
            double y = -r*std::sin(v);  
            std::cout << x << "   " << y << std::endl;
        }
         else {
            double v =  2*std::numbers::pi - vinkel;
            double x = r*std::cos(v);
            double y = -r*std::sin(v);
            std::cout << x << "   " << y << std::endl;
        }
    }
}




if(input_type == "Solver_2"){
    vector vec = {1, -0.5};   //Initial valoues 
    
    std::tuple Solution = driver(Newtonian, 0, 100, vec);
    auto [theta, u] = Solution;
    // std::vector<double> a = Solution{0};

    int I = static_cast<int>(theta.size());

    for (int i=0; i < I; i++){
        double r = 1/(u[i][0]);

        auto two_pi = 2.0L * std::numbers::pi;
        auto vinkel = std::fmod(static_cast<long double>(theta[i]), two_pi);
        // std::cout << vinkel << "   " << r << std::endl;
        if (vinkel <= std::numbers::pi/2){
            double x = r*std::cos(vinkel);
            double y = r*std::sin(vinkel);  
            std::cout << x << "   " << y << std::endl;
        }
        else if (vinkel < std::numbers::pi){
            double v = std::numbers::pi - vinkel;
            double x = -r*std::cos(v);
            double y = r*std::sin(v);  
            std::cout << x << "   " << y << std::endl;
        }
        else if (vinkel < (3* std::numbers::pi)/2 ){
            double v = vinkel - std::numbers::pi ;
            double x = -r*std::cos(v);
            double y = -r*std::sin(v);  
            std::cout << x << "   " << y << std::endl;
        }
         else {
            double v =  2*std::numbers::pi - vinkel;
            double x = r*std::cos(v);
            double y = -r*std::sin(v);
            std::cout << x << "   " << y << std::endl;
        }
    }
}




if(input_type == "Solver_3"){
    vector vec = {1, -0.5};   //Initial valoues 
    
    std::tuple Solution = driver(GR, 0, 300, vec);
    auto [theta, u] = Solution;
    // std::vector<double> a = Solution{0};

    int I = static_cast<int>(theta.size());

    for (int i=0; i < I; i++){
        double r = 1/(u[i][0]);

        auto two_pi = 2.0L * std::numbers::pi;
        auto vinkel = std::fmod(static_cast<long double>(theta[i]), two_pi);
        // std::cout << vinkel << "   " << r << std::endl;
        if (vinkel <= std::numbers::pi/2){
            double x = r*std::cos(vinkel);
            double y = r*std::sin(vinkel);  
            std::cout << x << "   " << y << std::endl;
        }
        else if (vinkel < std::numbers::pi){
            double v = std::numbers::pi - vinkel;
            double x = -r*std::cos(v);
            double y = r*std::sin(v);  
            std::cout << x << "   " << y << std::endl;
        }
        else if (vinkel < (3* std::numbers::pi)/2 ){
            double v = vinkel - std::numbers::pi ;
            double x = -r*std::cos(v);
            double y = -r*std::sin(v);  
            std::cout << x << "   " << y << std::endl;
        }
         else {
            double v =  2*std::numbers::pi - vinkel;
            double x = r*std::cos(v);
            double y = -r*std::sin(v);
            std::cout << x << "   " << y << std::endl;
        }
    }
}




}

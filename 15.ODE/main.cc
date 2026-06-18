#include<iostream>
// #include<cmath>

#include "RK12.h"
#include "Driver.h"

using vector = std::vector<double>;


// Simple Harmonic ossilator
// u''(x) = - u(x)
// y1(x) = u(x)

// y1' = y2
// y2' = - y1

vector f(double x, const vector y) {       //Based on ai     
    vector dy(2);
    dy[0] = y[1];
    dy[1] = -y[0];
    return dy;
}

// HO with friction
// u''(x) + b* u'(x) + c*u(x) = 0;    we set b = 1/2 and c = 1

vector f_friction(double x, const vector y){
    vector dy(2);
    dy[0] = y[1];
    dy[1] = - 0.25* y[1] - 5* y[0];
    return dy;
}




int main(int argc, char* argv[]) {

std::string input_type;

for(int i=0; i < argc; ++i){
    std::string arg=argv[i];    // Converting to string

    if(arg=="-printtype" && i+1 < argc){
        input_type = argv[i+1];
    }
}      

vector vec = {1, 0};   //Initial valoues 


if(input_type == "Solver_1"){                         // First solving SHO
    std::tuple Solution = driver(f, 0, 10, vec);
    auto [xes, yes] = Solution;

    int I = static_cast<int>(xes.size());

    for (int i=0; i < I; i++){
        std::cout << xes[i] << "   " << yes[i][0] << std::endl;
    }
}



if(input_type == "Solver_2"){                           // Now including friction, with same initial valoue
    std::tuple Solution_2 = driver(f_friction, 0, 10, vec);
    auto [x_ny, y_ny] = Solution_2;

    int J = static_cast<int>(x_ny.size());

    for (int i=0; i < J; i++){
        std::cout << x_ny[i] << "   " << y_ny[i][0] << std::endl;
    }
}


return 0;
}



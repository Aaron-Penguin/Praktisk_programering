#include<iostream>
#include<vector>


#include "Matrix.h"
#include "QR.h"
#include "Predictor.h"
#include "function.h"



int main(int argc, char* argv[]) {
std::string input_type;

for(int i=0; i < argc; ++i){
    std::string arg=argv[i];    // Converting to string

    if(arg=="-printtype" && i+1 < argc){
        input_type = argv[i+1];
    }
} 



// ---  Set number of terms in the linear prediction formular ----
int n = 4;


// ----- Constructing data, with no noise -----
std::vector<double> x_list(0);
for (double i=0.0; i < 2.0; i = i+0.005){
    x_list.push_back(i);
}
std::vector<double> y_list = f(x_list);              // f is defined in function.cc
int N = x_list.size(); 
// ---------------------



if (input_type == "Sample"){                         // Sample date for the plot.
    for (int i=0; i < N; i++){
        std::cout << x_list[i] << "    " << y_list[i] << std::endl;
    }
}


if (input_type == "fit"){
    y_list.resize(N/2);      // Now we have removed hafe of the total number of points. These we want to find through extrapolation. 

    std::vector<double> y_fitted = predict(y_list, n);
    int total_dim = y_fitted.size();
    
    for (int i = N/2; i < total_dim; i++){
        std::cout << x_list[i] << "    " << y_fitted[i] << std::endl;
    }
}


return 0;
}
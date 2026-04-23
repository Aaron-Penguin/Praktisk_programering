#include<iostream>
#include<vector>
#include<functional>
#include<cmath>
#include<fstream>   //For import and export txt files. 
#include <sstream>

#include "Matrix.h"
#include "QR.h"
#include "OLS.h"



std::vector<std::function<double(double)>> fs {
	[](double z) { return 1.0+0*z; },
	[](double z) { return z; },
	[](double z) { return z * z; }
};




int main(int argc, char* argv[]){

std::string input_type;

for(int i=0; i < argc; ++i){
    std::string arg=argv[i];    // Converting to string

    if(arg=="-printtype" && i+1 < argc){
        input_type = argv[i+1];
    }
}       

std::vector<double> t = {1,  2,  3, 4, 6, 9,   10,  13,  15};
std::vector<double> Activety = {117,100,88,72,53,29.5,25.2,15.2,11.1};
std::vector<double> Ac_err = {6,5,4,4,4,3,3,2,2};

int I = static_cast<int>(t.size());

std::vector<double> ln_y;
std::vector<double> dln_y;

for (int i =0; i < I; ++i){
    double num = std::log(Activety[i]);
    ln_y.push_back(num);

    double d_num =  Ac_err[i]/Activety[i];  //  dln(y) = sqrt(( dln(y)/dy* dy)^2) = dy/y
    dln_y.push_back(d_num);
};




if (input_type == "Test_QR"){

    double A[4][2] = {                        // Arbitrary tall matrix for testing old QR class.
        {1,4},
        {1,2},
        {1,3},
        {1,10}
    };

    Matrix mat_A(A);
    QR qr(mat_A);

    std::cout << "For a given Matrix A =" << "\n";
    mat_A.print();
    std::cout << "we do QR facorization." << "\n";

    std::cout << "Q =" << "\n";
    qr.Q.print();

    std::cout << "R =" << "\n";
    qr.R.print();

    std::cout << "===============" << "\n";
    std::cout << "Now we Calculate QR. This shood equal to matrix A." << "\n";

    Matrix mat_new_A = qr.Q * qr.R; 
    mat_new_A.print();

    std::cout << "We test whether Q.T * Q = 1" << "\n";
    Matrix mat_I = qr.Q.T() * qr.Q;
    mat_I.print(); 

    std::cout << "=================================================" << "\n";
    std::cout << "=================================================" << "\n";
}


if (input_type == "Fit"){
    OLS ols(2, fs ,t, ln_y, dln_y);
    // std::cout << "# Fitting params" << "\n";
    for (int i=0; i < ols.n; ++i){   // Priting fiting params
        std::cout << ols.c.array[i][0] <<  "\n";
    }

    std::cout << "# Covariance matrix" << "\n";
    ols.C_cov.print_for_txt();

}



if (input_type== "Fit_sample"){
    
std::string infile;
std::string outfile;

for(int i=0; i < argc; ++i){
    std::string arg=argv[i];    

    if(arg=="--input" && i+1 < argc){
        infile = argv[i+1];
    }
    if (arg=="--output" && i+1 < argc){
        outfile = argv[i+1];
    }
}  

std::ifstream myinput(infile);
std::ofstream myoutput(outfile);


double params[2] = {0.0, 0.0};
double x;


for (int i=0; i < 2; ++i){
    myinput >> x;
    std::cerr << "Imported fiting coefficents   " << x << "\n";
    params[i] = x;
}


// while (myinput >> x){
//     params[i] = x;
//     i += 1;
// }

for (double x=0; x < 16; x += 0.02){
    double fit_y_val = params[0]*fs[0](x) + params[1]*fs[1](x);
    // std:: cout << fit_y_val << "\n";
    myoutput << x << "   "<< fit_y_val << "\n";
}

myinput.close();
myoutput.close();

}


if (input_type == "Print_data"){
    int J = static_cast<int>(t.size());
    for (int j=0; j < J; ++j){  // Printing datapoints
        std::cout << "t" << j << "   " << t[j] << "   "
        << "ln_y_" << j << "   " << ln_y[j]
        << "   " << "dln_y_" << j << "   " << dln_y[j] << "\n";
    }

}


if (input_type == "Find_half-life"){

// double params[2] = {0.0, 0.0};
// Matrix C_COV(2,2,0);
// double x;
// double y;


// int i = 0;
// while (myinput >> x){
//     params[i] = x;
//     i += 1;
//     std::cerr << x << "\n";
// }


std::ifstream in("Fit_params.txt");    // AI based method to import data from txt file.
    if (!in) {
        std::cerr << "Cannot open txt file \n";
        return 1;
    }



std::vector<double> values;
std::string line;
while (std::getline(in, line)) {
    // remove leading spaces
    size_t p = line.find_first_not_of(" \t");
    if (p == std::string::npos) continue;      // skip blank lines
    if (line[p] == '#') continue;              // skip comment lines

    // parse numbers on the line
        std::istringstream iss(line);
        double x;
        while (iss >> x) {
            values.push_back(x);
        }
        // any non-numeric tokens will be ignored by >> double
}


// int j = 0;
// while (myinput >> x >> y){
//     C_COV.array[j][0] = x;
//     C_COV.array[j][0] = y;
//     j +=1;
//     std::cerr << x << y << "\n";
// }

// for (int i=0; i < 2; ++i){
//     for (int j=0; j <2; ++j){
//         std::cout << C_COV.array[i][j] << "\n";
//     }
// }


double Half_life = std::log(2)/(-values[1]);

double sigma_lambda = std::sqrt(values[5]) ;
double sigma_T_half =  std::abs(std::log(2)/ std::pow(-values[1], 2) * sigma_lambda) ;


std::cout << "T_(1/2)[measured] =   " << Half_life << "+-" << sigma_T_half << " days" << "\n";
std::cout <<  "Ra-224  decays with a alpha decay." << "\n";
std::cout << "Hafe-life today measured to be: T_(1/2)[modern] = 3.6 days." << "\n";
std::cout << "(T_(1/2)[measured] - T_(1/2)[modern]) =" << (Half_life - 3.6)<< "\n";
std::cout << "The deviation between the two valoues is computed to be   " << (Half_life - 3.6)/sigma_T_half << "    standartdeviations \n";

// myinput.close();
// myoutput.close();
}


return 0;
}
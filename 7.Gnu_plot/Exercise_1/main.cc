#include<iostream>
#include<cmath>
#include<string>
#include <fstream>    // std::ifstream, std::ofstream
#include <cstdlib>
#include<vector>

// using namespace std;


double erfunc(double x){
// single precision error function (Abramowitz and Stegun, from Wikipedia)
if (x<0) return -erf(-x);
std::vector<double> a {0.254829592,-0.284496736,1.421413741,-1.453152027,1.061405429};
double t=1/(1+0.3275911*x);
double sum=t*(a[0]+t*(a[1]+t*(a[2]+t*(a[3]+t*a[4]))));/* the right thing */
return 1-sum*std::exp(-x*x);
} 


int main () {
// ------------------------ Importing txt file ----------------------------------------------
std::ifstream file("Error_function_data.txt");
    
if (file.is_open()) {
    std::cout << "File opened successfully\n";}


// Decalring variables to store the imported data
double x, err_x, subtracted_err_x;

std::vector<double> colum_x, coulm_err, coulm_subt_err;


std::string header;
std::getline(file, header);

while (file >> x >> err_x >> subtracted_err_x) {
    colum_x.push_back(x);
    coulm_err.push_back(err_x);
    coulm_subt_err.push_back(subtracted_err_x);
}
file.close();


if (!colum_x.empty()) {
    std::cout << "Coulum is not empty" << std::endl;}    // Test for emtynes of the colum
else {std::cout << "Comulm is empty. Fail" << std::endl; 
}


// ---------- output file for computed Errorfunction -------------
double erfunc(double x);
std::vector<double> Computed_error_func;
std::ofstream outFile("Ouput_data.txt");

if (outFile.is_open()) {
        // Write header
        // outFile << "x\t Errfunc(x) \n";

        // Write data
        for(double x_val : colum_x){
            double erf_val =  erfunc(x_val);    
            outFile << x_val << "\t" << erf_val << "\n";}

        outFile.close();  // Always close the file
        std::cout << "Data written successfully.\n";
    } 
else {
std::cout << "Unable to open file.\n";}
// -----------------------------------------

system("gnuplot plot.gp");

std::cout << "System succesfully finisched" << std::endl;

return 0;
}
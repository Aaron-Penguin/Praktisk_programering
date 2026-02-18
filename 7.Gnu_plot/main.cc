#include<iostream>
#include<cmath>
#include<string>
#include <fstream>    // std::ifstream, std::ofstream
#include <cstdlib>
#include<vector>

// using namespace std;



int main () {
// ------------------------ Importing txt file ----------------------------------------------
// std::ifstream file("Error_function_data.txt");
    
// if (!file.is_open()) {
//     std::cerr << "Error opening file\n";    // Just testing that the file is opened.
//     return 1;
// }

// // Decalring variables to store the imported data
// double x, err_x, subtracted_err_x;

// std::vector<double> colum_1;
// std::vector<double> coulm_2;

// while (file >> x >> err_x >> subtracted_err_x) {
//     colum_1.push_back(x);
//     coulm_2.push_back(err_x);
// }
// file.close();

// ------------------------Export dat file--------------------------------

system("gnuplot plot.gp");

return 0;
}
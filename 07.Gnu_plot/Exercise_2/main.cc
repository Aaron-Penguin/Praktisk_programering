#include<iostream>
#include<cmath>
#include <chrono>  // for time  measure
#include<vector>

using namespace std::chrono;
using namespace std;

constexpr double PI = numbers::pi; // c++20
constexpr double e = numbers::e;


long double stirling_gamma(double n){
	if(n==1) {return 1;}
	else {return std::sqrt(2* PI* (n-1)) * std::pow( (n-1)/e,  (n-1) ) * std::pow(e,
(1/(12* (n-1)) - 1/(360* std::pow(n-1, 3))  + 1/(1260* std::pow(n-1, 5))   ))  ;}}    // n! approx sqrt(2 pi n)* (n/e)^n,  Gamma(n)


int main() {
// auto start = high_resolution_clock::now();

for (double x = -5; x < 5; x+= 0.001){
    cout << x << "\t" << tgamma(x);
    if (int(x+0.0005) != int(x-0.0005) && x>0) { 
        cout << "\t" << stirling_gamma(x) << endl;}
    else {cout << endl;}
}

// std::ofstream outFile("Ouput_data.txt");
// if (outFile.is_open()) {
//         for(double i=0; i<5; i++){
//             double erf_val =  erfunc(x_val);    
//             outFile << x_val << "\t" << erf_val << "\n";}

//         outFile.close();  // Always close the file
//         std::cout << "Data written successfully.\n";
//     } 
// else {
// std::cout << "Unable to open file.\n";}


system("gnuplot plot.gp");

// auto stop = high_resolution_clock::now();
// auto duration = duration_cast<microseconds>(stop - start);
// cerr << duration.count() << endl;
return 0;
}
#include<iostream>
#include<vector>
#include<string>
#include<cmath>


int main (int argc, char* argv[]) {
	std::vector<double> numbers;     // Storing all numbers

	for(int i=0; i < argc; ++i){
		std::string arg=argv[i];    // Converting to string
		if(arg=="-n" && i+1 < argc)
			numbers.push_back(std::stod(argv[i+1]));}    // stod -> converts string back to double


std::cout << "Number   Sin(Number)  Cos(Number)" << std::endl;

for(auto n: numbers)
std::cout << n <<" "<< std::sin(n) <<" "<< std::cos(n) <<std::endl;
exit(EXIT_SUCCESS);
}
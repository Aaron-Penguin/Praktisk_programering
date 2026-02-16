#include<iostream>
#include<cmath>

int main () {
double x;
std::cout << "Number   Sin(Number)  Cos(Number)" << std::endl;

while( std::cin >> x ){
	std::cout << x <<" "<< std::sin(x) <<" "<< std::cos(x) << std::endl;}
}


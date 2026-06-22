#include<iostream>
#include<cmath>
#include<vector>

#include "Matrix.h"
#include "EVD.h"


using namespace std;

int main(){

// Constructing a random (size)*(size) symetric matix.
constexpr int size = 4;
double A[size][size] = {};

for (int i=0; i < size; ++i){
    for (int j=i; j < size; ++j){
        A[i][j] = (rand() % 101);
        A[j][i] = A[i][j];
    }
}

Matrix mat_A(A);
std::cout << "Random symetrix matrix A =" << "\n";
mat_A.print();

EVD evd(mat_A);

std::cout << "Testing the EVD class results" << "\n";
// mat_A.print();
Matrix D_test = evd.V.T() * mat_A * evd.V;

std::cout << " V.T * A * V =  " << "\n";
D_test.print();

std::cout << "-----------------------" << "\n";
std::cout << "Matrix D = " << "\n";
evd.D.print();

std::cout << "======================" << "\n";

std::cout << "V* D * V.T = " << "\n";
Matrix A_test = evd.V * evd.D  *  evd.V.T();
A_test.print();

std::cout << " A = " << "\n";
mat_A.print();
std::cout << "======================" << "\n";

std::cout << "This shood give the Identety matrix, V.T * V =" << "\n";
(evd.V.T() * evd.V).print();

std::cout << "======================" << "\n";

std::cout << "This shood give the Identety matrix, V * V.T =" << "\n";
(evd.V * evd.V.T()).print();

return 0;
}
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
mat_A.print();

return 0;
}
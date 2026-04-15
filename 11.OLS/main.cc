#include<iostream>

#include "Matrix.h"
#include "QR.h"


int main(){

// Testing OLS with 4 abitrary points (4,2), (2,3), (3,5), (10, 1)
double A[4][2] = {
    {1,4},
    {1,2},
    {1,3},
    {1,10}
};

double b[4][1] = {
    {2},
    {3},
    {5},
    {1}
};

Matrix mat_A(A);
Matrix mat_b(b);

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

// Matrix Solution = qr.solve(mat_b);
// std::cout << "First order OLS coeficents shood equal: b0 = 4.37419,  b1 = -0.341935" << "\n";
// std::cout << "Computed OLS gives" << "\n";
// Solution.print();




}
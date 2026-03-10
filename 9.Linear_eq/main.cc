#include<iostream>
// #include <optional>
#include "Matrix.cc"

using namespace std;


int main() {


double A[2][3] = {
    {1,2,3},
    {2,3,4}
};

double B[2][3] = {
    {1,1,1},
    {1,1,1}
};

double vec[3][1] = {
    {1},
    {0},
    {0}
};


Matrix mat_A(A);
Matrix mat_B(B);

// mat_A.print();

// mat_A += mat_B;
// mat_A -= mat_B;

Matrix ny_vec = mat_A * vec;  
ny_vec.print();

// Matrix mat_D(2,3);
// mat_D.print();

return 0; 
}
#include<iostream>
// #include <optional>
#include "Matrix.cc"
#include<vector>

using namespace std;


int main() {


double A[2][3] = {
    {1,2,3},
    {2,3,4}
};

double B[3][1] = {
    {1},
    {2},
    {0}
};

Matrix mat_A(A);
Matrix mat_B(B);


mat_A.print();
Matrix Q = mat_A.Gram_schmidt();
Q.print();

QR qr(mat_A);

return 0; 
}
#include<iostream>
#include<vector>
#include "Matrix.cc"
#include "QR.cc"


using namespace std;


int main() {


double A[3][2] = {
    {1,2},
    {1,0},
    {1,0}
};


Matrix mat_A(A);
QR qr(mat_A);


return 0; 
}
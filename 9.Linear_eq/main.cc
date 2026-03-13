#include<iostream>
// #include <optional>
#include "Matrix.cc"
#include<vector>

using namespace std;


int main() {


double A[3][2] = {
    {1,2},
    {1,0},
    {1,0}
};


Matrix mat_A(A);
QR qr(mat_A);


cout << "Matrix A =" << endl;
mat_A.print();


cout << "Q after gramm schmidt" << endl;
qr.Q.print();

cout << "(Shood be upper triangle matrix) Matrix R =" << endl;
qr.R.print();

cout << "This matrix shood be an identety matrix" << endl;
Matrix identety = qr.Q.T() * qr.Q;
identety.print(); 

// cout << &mat_A << endl;

return 0; 
}
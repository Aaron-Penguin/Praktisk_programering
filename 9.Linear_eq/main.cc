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

cout << "This matrix shood be an identety matrix QT * Q =" << endl;
Matrix identety = qr.Q.T() * qr.Q;
identety.print(); 

cout << "The product RQ must equal to A. Matrix QR =" << endl;
Matrix A_new = qr.Q * qr.R;
A_new.print();

cout << "We define a vector: b =" << endl;
double b[3][1] = {
    {2},
    {1},
    {1}
};

Matrix vec_b(b);
vec_b.print();

cout << "Solution to the equation Ax = b, is found to be: x =" << endl;
Matrix solution = qr.solve(vec_b);
solution.print();


cout << "Testing the correctnis of the solution. Ax =" << endl;
Matrix Test_b = mat_A * solution;
Test_b.print();


return 0; 
}
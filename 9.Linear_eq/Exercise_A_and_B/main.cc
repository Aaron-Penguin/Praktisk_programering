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

// double B[2][2] {};

// Matrix mat_B(B);
// mat_B.print();

Matrix mat_A(A);
QR qr(mat_A);


cout << "==== Exercise A ====" << endl;

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


cout << "Testing the correctnes of the solution. Ax =" << endl;
Matrix Test_b = mat_A * solution;
Test_b.print();

cout << "Determinant of A, compuded as det(R): det(R) =" << endl;
double det_R = qr.det();
cout << det_R << endl;

cout << "===== Exercise B ====== " << endl;

cout << "We now define a new Matix B, for witch we want to find it's inverse. B =" << endl;
double B[3][3] = {
    {1,2,0},
    {1,0,0},
    {1,0,3}
};

Matrix mat_B(B);
QR qrB(mat_B);

mat_B.print();

Matrix mat_B_inv = qrB.Inverse();

cout << "The inverse of B must then be:" << endl;
mat_B_inv.print();

cout << "We can test the reult, be cheking that B*B^{-1} = I. We get" << endl;
Matrix identety_mat = mat_B_inv*mat_B;
identety_mat.print();

return 0; 
}
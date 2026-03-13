#include<iostream>
#include<cstdlib>

#include "Matrix.cc"
#include "QR.cc"
using namespace std;


int main() {

int N = 3;
double A[N][N];

for (int i =0; i < N; ++i){
    for (int j=0; j < N; ++j){
        A[i][j] =  (rand() % 101);
    }
}


// double B[2][2] = {
//     {1,2},
//     {4,0}
// };

Matrix mat_A(A);
mat_A.print();


return 0; 
}
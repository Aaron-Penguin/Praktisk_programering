#include<iostream>
#include<cmath>
#include<vector>

#include "Matrix.h"
#include "EVD.h"


using namespace std;

int main(){

double A[3][3] = {
    {1,4,2},
    {4,0,1},
    {2,1,1}
};

Matrix mat_A(A);
mat_A.print();

EVD evd(mat_A);


return 0;
}
#include<iostream>
#include<cmath>

#include "Matrix.h"
#include "EVD.h"

using namespace std;

int main(){
double A[3][3] = {
    {1,4,7},
    {0,3,1},
    {1,1,1}
};

Matrix mat_A(A);


return 0;
}
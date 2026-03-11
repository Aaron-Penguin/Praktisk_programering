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

vector<Matrix> arr;

for (int j=0; j< mat_A.get_cols(); ++j){
    Matrix a_j(mat_A.get_rows(), 1, 0);
    for (int i=0; i < mat_A.get_rows(); ++i){
        a_j.array[i][0] = mat_A.array[i][j];
    }
    arr.push_back(a_j);
}

Matrix a_1 = arr[2];
a_1.print();

// for (int i=0; i< mat_A.get_cols(); ++i){             // Starting Gram-Schmidt
//         arr[i] /= arr[i].norm();
//         for (int j= i +1 ; j < mat_A.get_cols(); ++j){
//             Matrix A_J = arr[j];
//             double in_prod = Inner_prod(arr[i].T(), arr[j]); 
//             arr[j] = in_prod * A_J;

//         }
//     }


double k = 2;
Matrix K = k * mat_B;


return 0; 
}
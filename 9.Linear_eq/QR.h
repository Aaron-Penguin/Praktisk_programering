#include "Matrix.h"
#include<vector>

class QR{
public:
    Matrix R;
    Matrix Q;

    template<int row, int col>
    QR(Matrix A(double (&mat)[row][col]));
    ~QR() = default;
};


template<int row, int col>    //Obs!!!   Gram-Schmidt method assumes that the initial basis consists of linear independent elements.
QR::QR(Matrix A(double (&mat)[row][col])){
    Q(A.get_rows(), A.get_cols(), 0);
    vector<Matrix> arr;

    for (int j=0; j< A.get_cols(); ++j){         // Separating the matrix into diffrent colums
        Matrix a_j(A.get_rows(), 1, 0);
        for (int i=0; i < A.get_rows(); ++i){
            a_j.array[i][0] = A.array[i][j];
        }
        arr.push_back(a_j);
    }

    for (int i=0; i< A.get_cols(); ++i){             // Starting Gram-Schmidt
        arr[i] /= arr[i].norm();
        for (int j= i +1 ; j < A.get_cols(); ++j){
            arr[j] -= Inner_prod(arr[i].T(), arr[j]) * arr[i];
            Q[i][j] = arr[j][i];
        }
    }
};
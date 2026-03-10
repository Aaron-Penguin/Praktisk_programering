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


template<int row, int col>
QR::QR(Matrix A(double (&mat)[row][col])){
    Matrix vectors(row, 1, 0);

    vector<Matrix> arr;
    for (int i=0; i < col; ++i){
        arr.push_Back(vectors)           //The matrix A is now seperated into vectors for every coloum.
    }

};
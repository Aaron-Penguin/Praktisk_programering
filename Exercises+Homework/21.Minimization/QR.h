#ifndef QR_H
#define QR_H

#include "Matrix.h"

class QR{
public:
    Matrix A;
    Matrix Q;
    Matrix R;

    QR(Matrix& M);
    ~QR() = default;

    // Solve the system of linear equations Ax = b
    Matrix solve(Matrix b);

    // Det of A and R
    double det();

    Matrix Inverse();

};
#endif
// #include "Matrix.h"



class QR{               //Obs!!!   Gram-Schmidt method assumes that the initial basis consists of linear independent elements.
public:
    Matrix A;
    Matrix Q;
    Matrix R;

    QR(Matrix& M);
    ~QR() = default;

    // Solve the system of linear equations Ax = b
    Matrix solve(Matrix b);

    double det();

    Matrix Inverse();

};
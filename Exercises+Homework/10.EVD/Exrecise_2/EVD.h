#ifndef EVD_H
#define EVD_H

#include "Matrix.h"
#include<cmath>


class EVD{       // Must ensure that the input matrix A is real and symetric
    public:

    Matrix D;    // Matrix of Eigen values
    Matrix V;    // Eigenvectors
    Matrix w;    // Vector of Eigen values

    static void timesJ(Matrix& A, int p, int q, double theta);     // We avoid creating J as a new matrix and just multiply directly on the specifix index that chainge.
	static void Jtimes(Matrix& A, int p, int q, double theta);

    EVD(Matrix A);

    // void Sort_eig();
};


#endif
#include "Matrix.h"

#include<cmath>
using namespace std;

class EVD{       // Must ensure that the input matrix A is real and symetric

    EVD(const Matrix A);


    static void timesJ(Matrix A, int p, int q, double theta);     // We avoid creating J as a new matrix and just multiply directly on the specifix index that chainge.
	static void Jtimes(Matrix A, int p, int q, double theta);
};
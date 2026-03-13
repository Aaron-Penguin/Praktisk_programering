#include "QR.h"


QR::QR(Matrix& M): 
    A(M), 
    Q(M.Gram_schmidt()),  
    R(Q.T()*M)
{};

Matrix QR::solve(Matrix b){
    Matrix c = Q.T() * b;
 
    for (int i= c.get_rows() -1; i >=0; i--){              // This method is based on a Lecture Note
        double sum = 0;
        for (int k = i+1; k < c.get_rows(); ++k){
            sum += R.array[i][k] * c.array[k][0];
        }
        c.array[i][0] = ( c.array[i][0] - sum  )/ R.array[i][i]; 
    }
    return c;
}

double QR::det(){
    int size = R.get_rows();

    double det_of_R = 1;
    for (int i=0; i < size; ++i){
        det_of_R *= R.array[i][i];
    }
    return det_of_R;
}
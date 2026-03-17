#include "Matrix.h"
#include "QR.h"

#include<iostream>
#include<vector>

using namespace std;

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


Matrix QR::Inverse(){
    int dim = A.get_rows(); 
    if (dim == A.get_cols()){                //Tjeck that the matrix is square.
        QR qr_solver = *this;
        
        vector<Matrix> arr;
        for (int i=0; i < dim; ++i){
            Matrix e_i(dim, i);
            Matrix x_i = qr_solver.solve(e_i);
            arr.push_back(x_i);
        }
        Matrix inverse(dim, dim, 0);

        for(int i=0; i< dim; ++i){
            for (int j=0; j < dim; ++j){
                inverse.array[i][j] = arr[j].array[i][0];
            }
        }
        return inverse;
    } else {
        cout << "Only a square Matrix can have an inverse. This matrix A is not a square Matrix" << endl;
        return A;
    }   
}
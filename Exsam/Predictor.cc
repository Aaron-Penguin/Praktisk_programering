#include<iostream>
#include "Predictor.h"
#include "Matrix.h"
#include "QR.h"


std::vector<double> predict(std::vector<double> x, int n){
    int N = x.size();
    int rows = N-n;
    int cols = n;
    
    Matrix A(rows, cols, 0.0);                  // Initializing the matrix
    Matrix b(rows, 1, 0.0);                     // Initializing the vector

    for (int i=0; i < rows; i++){               //Inserting the corret components
        for (int j=0; j < cols; j++){
            A.array[i][j] = x[i + j];
        }
    }
    for (int k = 0; k < rows; k++){
        b.array[k][0] = x[n+k];
    }

    QR qr(A);
    Matrix a = qr.solve(b);                     // Fitting parameters a are now determind
    // std::cout << "a = " << std::endl;
    // a.print();

    std::vector<double> X = x;
    X.resize(2*N);

    for (int i =0; i < N; i++){
        double sum = 0.0;
        for (int j =0; j < cols; j++){
             sum += a.array[j][0]*X[N -n + j + i];   // (Eq.43) and (Eq.44) in the note. The indexing error was fixed with the help of ai.
            //  std::cout << X[N+i] << std::endl;
        }
        X[N+i] = sum;
    }
    return X;
}
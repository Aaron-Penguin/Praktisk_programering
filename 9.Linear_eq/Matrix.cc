#include<iostream>
#include <optional>
#include "Matrix.h"

using namespace std;


// Constructor definition ------------------------------------------------------------

template<int R, int C>
Matrix::Matrix(double (&mat)[R][C]) {
    rows = sizeof(mat)/sizeof(mat[0]);         // Number of rows 
    cols = sizeof(mat[0])/sizeof(mat[0][0]);  //  Number of colums

    array = new double*[rows];

    for (int i=0; i< rows; ++i) {
        array[i] = new double[cols]();
        
        for (int j=0; j < cols; ++j) {
            array[i][j] = mat[i][j];
        }
    }
};



Matrix::Matrix(int Rows, int Cols, double a_ij){
    rows = Rows;
    cols = Cols;

    array = new double*[rows];           // Setting rows in matrix

    for (int i=0; i< rows; ++i){
        array[i] = new double[cols]();  //Setting colums for eatch row
        
        for (int j=0; j < cols; ++j){
            array[i][j] = a_ij;
        }
    }
}


// Printing the matrix ----------------------
void Matrix::print() {
    cout << "printed matrix =" << endl;
    for (int i = 0; i < rows; ++i) {
        cout <<"| ";
        for (int j = 0; j < cols; ++j) {
            std::cout << array[i][j] << " ";
        }
        cout << "| " << endl;
    }
}

// Norm ------------------------------------
double Matrix::norm(){
    if (cols == 1 || rows == 1){                 // column vector
        double inner_prod;
        
    }
}



// ============================  Definition of operations ===============================================


// Definition of (+=)
Matrix& Matrix::operator+=(const Matrix& mat_b) {
    if (rows == mat_b.rows && cols == mat_b.cols){
        for (int i=0; i < rows; ++i){
            for (int j=0; j < cols; ++j){
                array[i][j] += mat_b.array[i][j];
            }
        }
    return *this;    
    } else {
        cout << "Shapes of the added matixes do not match." << endl;
        return *this;
    }
};

// Definition of (-=)
Matrix& Matrix::operator-=(const Matrix& mat_b) {
    if (rows == mat_b.rows && cols == mat_b.cols){
        for (int i=0; i < rows; ++i){
            for (int j=0; j < cols; ++j){
                array[i][j] -= mat_b.array[i][j];
            }
        }
    return *this;    
    } else {
        cout << "Shapes of the added matixes do not match." << endl;
        return *this;
    }
};




// Definition of (*)
Matrix operator*(const Matrix& mat_a , const Matrix& mat_b) {
    Matrix mat_c(mat_a.rows, mat_b.cols, 0);                   // initializing empty matrix
    
    if (mat_a.cols == mat_b.rows){

        for (int i=0; i < mat_a.rows; ++i){                             //rows of the final matix
            for (int j=0; j< mat_b.cols; ++j){                          //cols of final matrix
                for (int k=0; k < mat_a.cols; ++k){                           //loop for summed elements in every (row, col) in the final matrix
                    mat_c.array[i][j] += mat_a.array[i][k] * mat_b.array[k][j] ;
                }
            }
        }
        return mat_c;
    } else{cout << "Shapes do not match for matrix multiplication." << endl;
        return mat_c;}
}
#include<iostream>
#include<cmath>
#include "Matrix.h"
#include<vector>

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
    // cout << "printed matrix =" << endl;
    for (int i = 0; i < rows; ++i) {
        cout <<"| ";
        for (int j = 0; j < cols; ++j) {
            std::cout << array[i][j] << " ";
        }
        cout << "| " << endl;
    }
}

// Inner_product ------------------------------------
double Matrix::inner_prod(){
    Matrix v = *this;
    
    if (v.cols == 1){                 // column vector
        Matrix inner_product = v.T() * v;
        return inner_product.array[0][0];
    } else if(v.rows == 1){           // row vectors
        Matrix inner_product = v * v.T();
        return inner_product.array[0][0];
    } else {
        cout << "Shapes do not match. You can't take the inner product of this object." << endl;
        return -1;
    }
}

// Norm -------------------------------------------------

double Matrix::norm(){
    Matrix v = *this;
    double inner_prod = v.inner_prod();
    return pow(inner_prod, 0.5);
}


// Transposing a matrix
Matrix Matrix::T(){
    Matrix mat_T(cols, rows, 0);
    for (int i=0; i < rows; ++i){
        for (int j=0; j< cols; ++j){
            mat_T.array[j][i] = array[i][j];
        }
    }
    return mat_T; 
}


// Gram-Schmidt

Matrix Matrix::Gram_schmidt(){
    vector<Matrix> arr;
    for (int j=0; j< cols; ++j){         // Separating the matrix into diffrent colums
        Matrix a_j(rows, 1, 0);
        // cout << "Test for a_j" << endl;
        // a_j.print();
        for (int i=0; i < rows; ++i){
            a_j.array[i][0] = array[i][j];
        }
        arr.push_back(a_j);
    }
    // cout << "Test for matrix seperated into colum vectors: first ved" << endl;
    // arr[0].print();
    // cout << "second vec" << endl;
    // arr[1].print();

    Matrix final_mat(rows, cols, 0);
    for (int i=0; i< cols; ++i){             // Starting Gram-Schmidt

        // cout << "a_i before normalizing" << endl;
        // arr[i].print();
        arr[i] /= arr[i].norm();
        // cout << "a_i after normalizing" << endl;
        // arr[i].print();


        for (int j= i +1 ; j < cols; ++j){
            //cout << "a_j before Gramm schmidt" << endl;
            // arr[j].print();

            arr[j] -= Inner_prod(arr[i].T(), arr[j]) * arr[i];
    
            // cout << "a_j after Gramm schmidt" << endl;
            // arr[j].print();
        }
    }
    for (int i=0; i < rows; ++i){
        for (int j=0; j < cols; ++j){
            // if (arr[j].array[i][0] < 1e-15){
                // final_mat.array[i][j] = 0;    
            // } else {
            final_mat.array[i][j] = arr[j].array[i][0];    
        }
    }
    return final_mat;
}

// Fix numeric zeros
void Matrix::Fix_numeric_zeros(){
    for (int i=0; i < rows; ++i){
        for (int j=0; j < cols; ++j){
            if (abs(array[i][j]) < 1e-15){
                array[i][j] = 0;
            } else{
                array[i][j] = array[i][j];
            }
        }
    }
}

// ============================  Definition of operations ===============================================


// Definition of (+=) with Matrix
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

// Definition of (-=) with Matrix
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


// Definition of (*=) with double
Matrix& Matrix::operator*=(const double& alpha){
    for (int i=0; i < rows; ++i){
        for (int j=0; j< cols; ++j){
            array[i][j] *= alpha;
        }
    }
    return *this; 
}


// Definition of (/=) with double
Matrix& Matrix::operator/=(const double& alpha){
    for (int i=0; i < rows; ++i){
        for (int j=0; j< cols; ++j){
            array[i][j] /= alpha;
        }
    }
    return *this; 
}

// Definition of (*) Matrix with Matrix
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

// Definition of (*) scalar with Matrx
Matrix operator*(const double& alpha , const Matrix& mat_a){
    int rows = mat_a.rows;
    int cols = mat_a.cols;
    Matrix output_mat(rows, cols, 0);
    for (int i=0; i < rows; ++i){
        for (int j=0; j < cols; ++j){
            output_mat.array[i][j] = alpha * mat_a.array[i][j];
        }
    }
    return output_mat;
}

// Definition of general inner product
double Inner_prod(const Matrix& vec_1, const Matrix& vec_2){
    if (vec_1.rows == 1 && vec_2.cols == 1){                 // column vector
        Matrix inner_product = vec_1 * vec_2;
        return inner_product.array[0][0];
    } else {
        cout << "Shapes do not match. You can't take the inner product of this object." << endl;
        return -1;
    }
}
#include<iostream>
#include<cmath>
#include<vector>

#include "Matrix.h"






// Constructors definition ------------------------------------------------------------

// Default constructor
Matrix::Matrix(): rows(1), cols(1){
    array = new double*[rows];           // Setting rows in matrix
    array[0] = new double[cols]();  //Setting colums for eatch row
    array[0][0] = 0;
}


// Matrix with same index
Matrix::Matrix(int Rows, int Cols, double a_ij): rows(Rows), cols(Cols){
    array = new double*[rows];           // Setting rows in matrix

    for (int i=0; i< rows; ++i){
        array[i] = new double[cols]();  //Setting colums for eatch row
        
        for (int j=0; j < cols; ++j){
            array[i][j] = a_ij;
        }
    }
}


// Identety Matrix
Matrix::Matrix(int size): rows(size), cols(size){
    array = new double*[rows];           // Setting rows in matrix

    for (int i=0; i< rows; ++i){
        array[i] = new double[cols]();  //Setting colums for eatch row
        array[i][i] = 1.0;
    }
}

// Unit column vector
 Matrix::Matrix(int size, int position){
    rows = size;
    cols = 1;

    array = new double*[rows];           // Setting rows in matrix

    for (int i=0; i< rows; ++i){
        array[i] = new double[cols]();  //Setting colums for eatch row
        
        for (int j=0; j < cols; ++j){
            array[i][j] = 0;
        }
    }
    array[position][0] = 1;
 }





// Printing the matrix ----------------------
void Matrix::print() {
    // cout << "printed matrix =" << endl;
    for (int i = 0; i < rows; ++i) {
        std::cout <<"| ";
        for (int j = 0; j < cols; ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << "| " << std::endl;
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
        std::cout << "Shapes do not match. You can't take the inner product of this object." << std::endl;
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
    std::vector<Matrix> arr;
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


Matrix Matrix::copy(){
    Matrix B(rows, cols, 0);         //Declaring new Matrix

    for (int i=0; i < rows; ++i){
        for (int j=0; j < cols; ++j){
            B.array[i][j] = array[i][j];
        }
    }
    return B;
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
        std::cout << "Shapes of the added matixes do not match." << std::endl;
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
        std::cout << "Shapes of the added matixes do not match." << std::endl;
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

// Definition of (+) Matrix with Matrix

Matrix operator+(const Matrix& mat_a, const Matrix& mat_b){
    Matrix C(mat_a.rows, mat_a.cols, 0.0);

    if (mat_a.rows == mat_b.rows && mat_a.cols == mat_b.cols){

        for (int i=0; i < mat_a.rows; ++i){
            for (int j=0; j < mat_a.cols; ++j){
                C.array[i][j] = mat_a.array[i][j] + mat_b.array[i][j];
            }
        }
    return C;    
    } else{
        std::cout << "Shapes of the added matixes do not match." << std::endl;
        return C;
    }
};


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
    } else{std::cout << "Shapes do not match for matrix multiplication." << std::endl;
        return mat_c;}
}


// Friend of Matrix; Test whether 2 Matricys are identical for 



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
        std::cout << "Shapes do not match. You can't take the inner product of this object." << std::endl;
        return -1;
    }
}
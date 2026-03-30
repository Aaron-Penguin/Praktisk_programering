#ifndef MATRIX_H
#define MATRIX_H

#include<string>

class Matrix{
private:

    int rows;
    int cols;

public:    
    double **array;



    template<int R, int C>                     // Standart constructor
    Matrix(double (&mat)[R][C]);

    Matrix();                                  // Default constructor
    Matrix(int Rows, int Cols, double a_ij);   // Same idex matrix constructor
    Matrix(int size);                          // Identety

    Matrix(int size, int position);


    ~Matrix() = default;


    // Fundamental operations
    Matrix& operator+=(const Matrix&);
    Matrix& operator-=(const Matrix&);
    Matrix& operator*=(const double&);
    Matrix& operator/=(const double&);

    
    friend Matrix operator*(const Matrix& mat_a , const Matrix& mat_b);
    friend Matrix operator*(const double& alpha , const Matrix& mat_a);

    // Smart matrix stuff
    Matrix T();
    Matrix Gram_schmidt();
    void Fix_numeric_zeros();  // Must still be modified. seems do do nothing.

    //Only for vectors  (Maybe start using child class)
    friend double Inner_prod(const Matrix& vec_1, const Matrix& vec_2);
    
    double inner_prod();
    double norm();

    //Getter methods
    void print();

    int get_rows(){return rows;};
    int get_cols(){return cols;};
};


template<int R, int C>
Matrix::Matrix(double (&mat)[R][C]) {
    rows = R;
    cols = C;

    array = new double*[rows];

    for (int i=0; i< rows; ++i) {
        array[i] = new double[cols]();
        
        for (int j=0; j < cols; ++j) {
            array[i][j] = mat[i][j];
        }
    }
};



#endif


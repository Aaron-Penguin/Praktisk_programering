#include<string>

class Matrix{
private:

    int rows;
    int cols;

public:    
    double **array;


    template<int R, int C>
    Matrix(double (&mat)[R][C]); 
    // Matrix(int Rows, int Cols, double a_ij);      // matrix (Rows, Cols), with a for every index.

    Matrix(int Rows, int Cols, double a_ij);

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





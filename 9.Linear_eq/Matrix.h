class Matrix{
private:

    int rows;
    int cols;

public:    
    double **array;


    template<int R, int C>
    Matrix(double (&mat)[R][C]); 
    Matrix(int Rows, int Cols, double a_ij);      // matrix (Rows, Cols), with a for every index.

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

    //Only for vectors  (Maybe start using child class)
    friend double Inner_prod(const Matrix& vec_1, const Matrix& vec_2);
    
    double inner_prod();
    double norm();

    //Getter methods
    void print();

    int get_rows(){return rows;};
    int get_cols(){return cols;};
};


// ----------- For QR ----------------

class QR{
public:
    Matrix A;
    Matrix Q;
    Matrix R;

    QR(Matrix& M);
    ~QR() = default;
};


// template<int row, int col>    //Obs!!!   Gram-Schmidt method assumes that the initial basis consists of linear independent elements.

QR::QR(Matrix& M): A(M), Q(M.Gram_schmidt()),  R(Q.T()*M)
{};









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


// ----------- For QR ----------------

class QR{
public:
    Matrix A;
    Matrix Q;
    Matrix R;

    QR(Matrix& M);
    ~QR() = default;

    Matrix solve(Matrix b);
};


//Obs!!!   Gram-Schmidt method assumes that the initial basis consists of linear independent elements.

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








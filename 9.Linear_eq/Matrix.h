class Matrix{
public:

    int rows;
    int cols;

    double **array;



    template<int R, int C>
    Matrix(double (&mat)[R][C]);
    Matrix(int Rows, int Cols);

    ~Matrix() = default;

    void print();


    Matrix& operator+=(const Matrix&);
    Matrix& operator-=(const Matrix&);  
};


Matrix operator*(const Matrix& mat_a , const Matrix& mat_b);





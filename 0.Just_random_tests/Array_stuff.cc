#include<iostream>

using namespace std;



class Matrix{
public:

    int dim_m;
    int dim_n;

    double array[10][10];
public:

    template<int R, int C>
    Matrix(double (&mat)[R][C]);
    ~Matrix() = default;
};


template<int R, int C>
Matrix::Matrix(double (&mat)[R][C]) {
    const int dim_m = sizeof(A)/sizeof(A[0]);         // Number of rows 
    const int dim_n = sizeof(A[0])/sizeof(A[0][0]);  //  Number of colums

    double my_matrix[dim_m][dim_n];
    
    for (int i=0, i< dim_m, ++i) {
        for (int j=0, j < dim_n, ++i) {
            double my_matrix[i][j] = mat[i][j];
        }
    }
};



template<size_t R, size_t C>
void print_matrix(double (&mat)[R][C]) {
    cout << "printed matrix =" << endl;
    for (size_t i=0;i<R;++i) {
        cout <<"| ";
      for (size_t j=0;j<C;++j) {
        cout << mat[i][j] << " ";}
    cout << "|" << endl;
    }
}




int main() {

// int rows = 2;
// int colums = 3;


double A[2][3] = {
    {1,2,3},
    {2,3,4}
};



const int anz_elem_A = sizeof(A)/sizeof(A[0][0]); // Total number of elements
const int dim_m = sizeof(A)/sizeof(A[0]);         // Number of rows 
const int dim_n = sizeof(A[0])/sizeof(A[0][0]);  //  Number of colums



cout << "Number of all elements = " << anz_elem_A << endl;
cout << "Number of all rows = " << dim_m << endl;
cout << "Number of all colums = " << dim_n << endl;

print_matrix(A);

cout << &A[0][0] << endl;

return 0; 
}
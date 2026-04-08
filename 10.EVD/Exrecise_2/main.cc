#include <iostream>
// #include<algorithm>



#include "Matrix.h"
#include "EVD.h"
#include "Vector.h"

#include "Quicksort.h"






int main(){

double rmax = 15.0;
double dr = 0.1;
int N = (int) (rmax/dr) -1;


// Kinetic energy Matrix
Matrix ddx(N, N, 0.0);
Matrix V(N, N, 0.0);

// This part uses finite diffrence, and includes the boundary condition.
for (int i=0; i < N; ++i){
    ddx.array[i][i] = - 2.0;    // Second spacial derivative

    double r_i = (i+1)*dr;
    V.array[i][i] = -1/r_i;
    if (i+1 < N){
        ddx.array[i+1][i] = 1.0;
        ddx.array[i][i+1] = 1.0;
    }
};

Matrix K = - (1/(2*dr*dr)) *ddx;
// K.print();
// V.print();

Matrix H = K + V;
H.print();

EVD evd(H);  // Diagonalizing the Hamiltonian

std::cout << " Unsorted vector of eigenvaloues =" << "\n";

evd.w.print();

// evd.V.print();

// evd.Sort_eig();



// int len = evd.w.get_rows();

// double arr[evd.w.get_rows()] = {};
// for (int i=0; i<evd.w.get_rows(); ++i){
//     arr[i] = evd.w.array[i][0];
// }

// for (int j=0; j <evd.w.get_rows(); ++j){
//     std::cout << arr[j] <<"\n";
// }

// std::cout << "---------Vector -------" <<"\n";

// std::vector<double> u_sort_eig(arr, arr + 6);
// for (int j=0; j <evd.w.get_rows(); ++j){
//     std::cout << u_sort_eig[j] <<"\n";
// }

// for (int i=0; i<evd.w.get_rows(); ++i){
//     std::cout << u_sort_eig[i]  << "\n";
// }



// std::vector<int> vec = func::quicksort(arr, len);




// for (int i=0; i < len; ++i){
//     std::cout << vec[i] << " ";    
// }
// std::cout << std::endl;






}
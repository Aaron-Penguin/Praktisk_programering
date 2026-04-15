#include<iostream>
#include<vector>

#include "EVD.h"
// #include "Quicksort.h"

// Constructor
EVD::EVD(Matrix A): D(A.get_rows()), V(A.get_rows()), w(A.get_rows(), 1, 0){  // Only use A as real symetric matrix.

	Matrix A_copy = A.copy();

	// std::cout << "========================================" << "\n";
	// std::cout << "Constructor of the EVD class is called" << "\n";
	int counter=1;
	// std::cout << "This shood be an identety matrix" << "\n";
	// V.print();

	bool changed;
	do{
		changed=false;
		for(int p=0; p < A_copy.get_rows() -1; p++){
			for(int q=p+1; q < A_copy.get_rows(); q++){

				double a_pq=A_copy.array[p][q], a_pp=A_copy.array[p][p], a_qq=A_copy.array[q][q];   // Becorse A is symetrix A[p][q] = A[q][p]
				double theta = 0.5*std::atan2(2*a_pq, a_qq - a_pp);
				double c=std::cos(theta),s=std::sin(theta);
				double new_a_pp =c*c*a_pp -2*s*c*a_pq +s*s*a_qq;
				double new_a_qq= s*s*a_pp +2*s*c*a_pq +c*c*a_qq;
				
				if(new_a_pp != a_pp || new_a_qq != a_qq){  // This critiria checks whether some dioganal elements have chainged. If its the case do a rotation.
					// std::cout << "Rotaion nr = " << counter << "\n";
					changed = true;
					timesJ(A_copy,p,q, theta); // A←A*J 
					Jtimes(A_copy,p,q, -theta); // A←J.T()*A 

					timesJ(V,p,q, theta); // V←V*J
					// A_copy.print();
					counter += 1;
				}
			}
		}
	}while(changed);
	// }while (counter < 25);
	

	// std::cout << "========================================" << "\n";
	// std::cout << "Final diagonal matrix D =" << std::endl;
	// A_copy.print();
	// std::cout << "========================================" << "\n";

	D = D*A_copy;
	for (int k=0; k < A_copy.get_rows(); ++k){
		w.array[k][0] = A_copy.array[k][k];		
	}
};



//--------------------------------  Member functions   ---------------------------------

void EVD::timesJ(Matrix& A, int p, int q, double theta){
	double c = std::cos(theta), s = std::sin(theta);
	for(int i=0; i<A.get_rows(); ++i){
        double aip=A.array[i][p], aiq= A.array[i][q];  // For every row the indicis of 2 columns chainge 

        A.array[i][p] = c*aip - s* aiq;
        A.array[i][q] = s*aip + c* aiq;   
    }
}

void EVD::Jtimes(Matrix& A, int p, int q, double theta){
	double c= std::cos(theta), s= std::sin(theta);
	for(int j=0; j < A.get_cols(); ++j){
		double apj= A.array[p][j], aqj=A.array[q][j];    //  For every coloum, 2 rows are chainged
		A.array[p][j] = c*apj  + s*aqj;
		A.array[q][j] = -s*apj + c*aqj;
	}
}

// void EVD::Sort_eig(){

// 	double arr[w.get_rows()] = {};          // Converting to a rank 1 tensor.
// 	for (int i=0; i < w.get_rows(); ++i){
// 		arr[i] = w.array[i][0];
// 	}

// 	std::vector<int> Index = func::quicksort(arr, w.get_rows());     // List of index, for sorting eigenvalues with increasing order. 

// 	Matrix New_V(V.get_rows(), V.get_cols(), 0);
// 	for (int i=0; i < V.get_rows(); ++i){
// 		for (int j=0; j < V.get_cols(); ++j){
// 			New_V.array[i][j] = V.array[Index[i]][j];
// 		}
// 	}
// };
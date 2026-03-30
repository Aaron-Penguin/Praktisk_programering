#include<iostream>
#include "EVD.h"


// Constructor
EVD::EVD(Matrix A): V(A.get_rows()), w(A.get_rows(), 1, 0){  // Only use A as real symetric matrix.

	int counter=0;
	// std::cout << "This shood be an identety matrix" << "\n";
	// V.print();

	bool changed;
	do{
		std::cout << "Swap nr = " << counter << "\n";
		changed=false;
		for(int p=0; p < A.get_rows() -1; p++){
			for(int q=p+1; q < A.get_rows(); q++){

				double a_pq=A.array[p][q], a_pp=A.array[p][p], a_qq=A.array[q][q];   // Becorse A is symetrix A[p][q] = A[q][p]
				double theta = 0.5*std::atan2(2*a_pq, a_qq - a_pp);
				double c=std::cos(theta),s=std::sin(theta);
				double new_a_pp =c*c*a_pp -2*s*c*a_pq +s*s*a_qq;
				double new_a_qq= s*s*a_pp +2*s*c*a_pq +c*c*a_qq;
				
				if(new_a_pp != a_pp || new_a_qq != a_qq){  // This critiria checks whether some dioganal elements have chainged. If its the case do a rotation.
					std::cout << "Rotation is performed" << "\n";
					changed = true;
					timesJ(A,p,q, theta); // A←A*J 
					Jtimes(A,p,q, -theta); // A←J.T()*A 

					timesJ(V,p,q, theta); // V←V*J
					A.print();

					counter += 1;
				}
			}
		}
	// }while (counter < 5);
	}while(changed);
	std::cout << "Final diagonal matrix" << std::endl;
	A.print();

	for (int k=0; k < A.get_rows(); ++k){
		w.array[k][0] = A.array[k][k];		
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
	double c= cos(theta), s= sin(theta);
	for(int j=0; j < A.get_cols(); ++j){
		double apj= A.array[p][j], aqj=A.array[q][j];    //  For every coloum, 2 rows are chainged
		A.array[p][j] = c*apj  + s*aqj;
		A.array[q][j] = -s*apj + c*aqj;
		}
}
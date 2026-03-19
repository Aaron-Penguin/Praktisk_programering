#include "EVD.h"

void EVD::timesJ(Matrix& A, int p, int q, double theta){
	double c = cos(theta), s = sin(theta);
	for(int i=0; i<A.get_rows(); ++i){
        double aip=A.array[i][p], aiq= A.array[i][q];  // For every row the indicis of 2 columns chainge 

        A.array[i][p] = c*aip - s* aiq;
        A.array[i][q] = c*aip + s* aiq;   
    }
}

void EVD::Jtimes(Matrix& A, int p, int q, double theta){
	double c= cos(theta), s= sin(theta);
	for(int j=0; j < A.get_cols(); ++j){
		double apj= A.array[p][j], aqj=A.array[q][j];    //  For every coloum 2 rows are chainged
		A.array[p][j] = c*apj  + s*aqj;
		A.array[q][j] = -s*apj + c*aqj;
		}
}
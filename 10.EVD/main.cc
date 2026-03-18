#include<iostream>
#include<cmath>
#include "Matrix.h"

using namespace std;


static void timesJ(Matrix& A, int p, int q, double theta){
	double c = cos(theta), s= sin(theta);
	for(int i=0; i<A.get_rows(); ++i){
        for (int j=0; j< A.get_cols(); ++j){
            double aip=A.array[i][p], aiq= A.array[i][q]; 
            A.array[i][p] = c*aip - s* aiq;   
        }
		// A[i,p]=c*aip-s*aiq;
		// A[i,q]=s*aip+c*aiq;
    }
}



int main(){

return 0;
}
#include<iostream>
#include<cstdlib>
#include<string>

// #include "Matrix.cc"
// #include "QR.cc"
#include "Matrix.h"
#include "QR.h"

using namespace std;


int main(int argc, char* argv[]) {

    int size;
    for(int i=0; i < argc; ++i){
        std::string arg=argv[i];    // Converting to string
        if(arg=="-size" && i+1 < argc) {
            size = stoi(argv[i+1]);
        }
    }

    if (size <= 0) {
        std::cerr << "Invalid matrix size." << std::endl;
        return 1; // Exit with an error code
    }


    Matrix A(size, size, 0);

    for (int i =0; i < size; ++i){
        for (int j=0; j < size; ++j){
            A.array[i][j] =  (rand() % 101);
        }
    }

    QR qr(A);
return 0; 
}
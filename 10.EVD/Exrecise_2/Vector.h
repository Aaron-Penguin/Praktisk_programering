#ifndef VECTOR_H
#define VECTOR_H

#include <cstring>
#include <iostream>
#include "Matrix.h"

class Vector: public Matrix{
private:
    std::string type = "None";

public:

    template<int R, int C>                     // Standart constructor
    Vector(double (&mat)[R][C]);

    Vector(int size, bool colum_vec, double numbers);    // Vector with same values

    Vector(int size, int position, bool colum_vec);      // Unit vector

    // Geter methods
    void get_type(){
        std::cout << type << "\n";
    }
};


template<int R, int C>
Vector::Vector(double (&mat)[R][C]) {
    set_cols(C);
    set_rows(R);

    if (C == 1){             // specifing size for row and colum vectors.
        type = "column vector";
    } else if(R == 1){
        type = "row vector";
    } else{
        std::cout << "Shapes do not match for a vector!" << "\n";
    }


    array = new double*[get_rows()];

    for (int i=0; i< get_rows(); ++i) {
        array[i] = new double[get_cols()]();
        
        for (int j=0; j < get_cols(); ++j) {
            array[i][j] = mat[i][j];
        }
    }
};






#endif
// Will be used in later implementations.

#include "Vector.h"


Vector::Vector(int size, bool colum_vec, double numbers){

    if (colum_vec == true){             // specifing size for row and colum vectors.
        set_cols(1);
        set_rows(size);
        type = "column vector";
    } else{
        set_cols(size);
        set_rows(1);
        type = "row vector";
    }

    array = new double*[get_rows()];           // Setting rows in matrix

    for (int i=0; i< get_rows(); ++i){
        array[i] = new double[get_cols()]();  //Setting colums for eatch row
        
        for (int j=0; j < get_cols(); ++j){
                    array[i][j] = numbers;
        }
    }
}




 Vector::Vector(int size, int position, bool colum_vec){
    if (colum_vec == true){             // specifing size for row and colum vectors.
        set_cols(1);
        set_rows(size);
        type = "column vector";
    } else{
        set_cols(size);
        set_rows(1);
        type = "row vector";
    }

    array = new double*[get_rows()];           // Setting rows in matrix

    for (int i=0; i< get_rows(); ++i){
        array[i] = new double[get_cols()]();  //Setting colums for eatch row
        
        for (int j=0; j < get_cols(); ++j){
            array[i][j] = 0.0;
        }
    }

    if (colum_vec == true){
        array[position][0] = 1.0;
    } else {
        array[0][position] = 1.0;
    }
 }


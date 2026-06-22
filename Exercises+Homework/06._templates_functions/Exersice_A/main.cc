#include<iostream>
#include<string>


template <typename T>
class vec {
    public:
    T x,y,z;
};


int main () {
    vec<double> double_vec;
    double_vec.x = 1;
    double_vec.y = 2;
    double_vec.z = 3;

    vec<float> float_vec;
    float_vec.x = 1;
    float_vec.y = 2;
    float_vec.z = 3;

    std::cout << "x_double  =" << double_vec.x << std::endl;
    std::cout << "y_double  =" << double_vec.y << std::endl;
    std::cout << "z_double  =" << double_vec.z << std::endl;

    std::cout << "x_float  =" << float_vec.x << std::endl;
    std::cout << "y_float  =" << float_vec.y << std::endl;
    std::cout << "z_float  =" << float_vec.z << std::endl;
return 0;
}



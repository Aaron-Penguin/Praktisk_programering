#include<iostream>



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



    std::cout << "x =" << double_vec.x << std::endl;
return 0;
}



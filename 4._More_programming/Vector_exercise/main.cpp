#include<iostream>

using namespace std;


struct vec{
    double x, y, z;

    // Constructor
    vec(double x_in, double y_in, double z_in);
    vec();                                    // default
    vec(const vec&) = default;                                 // copy
    vec(vec&&) = default;                                      // move
    ~vec() = default;                                          // destructor

    // assignment
    vec& operator=(const vec&) = default;                     // copy assignment
    vec& operator=(vec&&) = default;                          // move assignment

    // arithmetic
    vec& operator+=(const vec&);
    vec& operator-=(const vec&);
    vec& operator*=(double);
    vec& operator/=(double);

    // utility
    void set(double a, double b, double c) { x = a; y = b; z = c; };
    void print(const std::string& s = "") const;                              // for debugging

    // stream output
    friend std::ostream& operator<<(std::ostream&, const vec&);
};


// Definition of member functions
vec::vec(double x_in, double y_in, double z_in){
    x = x_in;
    y = y_in;
    z = z_in;
};

vec::vec(){x = 0.0; y=0.0, z = 0.0;};

// void vec::print(std::string s) const {
//     std::cout << s << x << " " << y << " " << z << std::endl;
// }


// non-member operators
vec operator-(const vec&);
vec operator-(const vec&, const vec&);
vec operator+(const vec&, const vec&);
vec operator*(const vec&, double);
vec operator*(double, const vec&);
vec operator/(const vec&, double);


// approximate equality
bool approx(const vec&, const vec&, double acc = 1e-6, double eps = 1e-6);


int main() {

vec Vector1 = vec(1.0, 3.0, 2.0);
vec Vector2 {1.0,1.0,1.0};

vec ny_vec = Vector1.operator+=(Vector2);
cout << "ny_vec_x" << ny_vec.x << endl;

return 0;
}
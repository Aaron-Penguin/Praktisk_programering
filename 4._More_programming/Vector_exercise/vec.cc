#include<iostream>
#include <string>
#include"vec.h"
#include<cmath>

using namespace std;



// Constructors
vec::vec(double x_in, double y_in, double z_in){
    x = x_in;
    y = y_in;
    z = z_in;
};

vec::vec(){x = 0.0; y=0.0, z = 0.0;};

// += operator  (vec + vec)
vec& vec::operator+=(const vec& v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

// -= operator  (vec - vec)
vec& vec::operator-=(const vec& v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

// *= scalar     (vec * scalar)
vec& vec::operator*=(double s)
{
    x *= s;
    y *= s;
    z *= s;
    return *this;
}

// /= scalar     (vec /scalar)
vec& vec::operator/=(double s)
{
    x /= s;
    y /= s;
    z /= s;
    return *this;
}

// -----------------------------------------------

// Just operations on one vector objekt

double vec::norm() const {
    double indre_prod = *this * *this;
    return pow(indre_prod, 0.5);
}

// print method
void vec::print(const std::string& s) const
{
    if (!s.empty())
        std::cout << s << " ";

    std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
}

// stream operator <<
std::ostream& operator<<(std::ostream& os, const vec& v)
{
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}



//  -------------  Non member functions -------------------

// Inner product
double operator*(const vec& v, const vec& v_in) {
    return v.x *v_in.x +   v.y* v_in.y   + v.z *v_in.z;
}


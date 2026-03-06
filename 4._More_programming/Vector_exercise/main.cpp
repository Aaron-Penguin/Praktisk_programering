#include<iostream>
#include <string>
#include"vec.h"

using namespace std;


// Definition of member functions
vec::vec(double x_in, double y_in, double z_in){
    x = x_in;
    y = y_in;
    z = z_in;
};

vec::vec(){x = 0.0; y=0.0, z = 0.0;};

// += operator
vec& vec::operator+=(const vec& v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

// -= operator
vec& vec::operator-=(const vec& v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

// *= scalar
vec& vec::operator*=(double s)
{
    x *= s;
    y *= s;
    z *= s;
    return *this;
}

// /= scalar
vec& vec::operator/=(double s)
{
    x /= s;
    y /= s;
    z /= s;
    return *this;
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



int main() {

vec a = vec(1.0, 3.0, 2.0);
vec b {1.0,1.0,1.0};

vec c = a;
c += b;

vec d = a;
d -=b;

c.print("Adding vectors: a + b");


d.print("Subtracting vectors a - b");


return 0;
}
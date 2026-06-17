#include<iostream>
#include <string>
#include"vec.cc"


using namespace std;

int main() {

vec a = vec(1.0, 1.0, 2.0);
vec b {1.0,1.0,1.0};

vec c = a;
c += b;

vec d = a;
d -=b;

c.print("Adding vectors: a + b");


d.print("Subtracting vectors a - b");

double e = a * b;

cout << "Inner product =  " << e << endl;

cout << "Norm of b =" << b.norm() << endl;


return 0;
}
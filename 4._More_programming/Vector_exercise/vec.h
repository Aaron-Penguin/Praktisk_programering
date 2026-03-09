#include<iostream>
#include<string>

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

    // // Inner product
    // double operator*(const vec& v,const vec&);

    // utility
    void set(double a, double b, double c) { x = a; y = b; z = c; };
    void print(const std::string& s = "") const;                              // for debugging

    // stream output
    friend std::ostream& operator<<(std::ostream&, const vec&);
};


// non-member operators
vec operator-(const vec&);
vec operator-(const vec&, const vec&);
vec operator+(const vec&, const vec&);
vec operator*(const vec&, double);
vec operator*(double, const vec&);
vec operator/(const vec&, double);

double operator*(const vec&, const vec&);

// approximate equality
bool approx(const vec&, const vec&, double acc = 1e-6, double eps = 1e-6);
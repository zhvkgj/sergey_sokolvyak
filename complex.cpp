#include <iostream>
#include "complex.h"
#include "math.h"
using namespace std;

Complex Complex::operator +(const Complex &c){
    Complex d;
    d.comp.a=comp.a+c.comp.a;
    d.comp.b=comp.b+c.comp.b;
    return d;
}
Complex Complex::operator *(const Complex &c){
    Complex t;
    t.comp.a=comp.a*c.comp.a-comp.b*c.comp.b;
    t.comp.b=comp.a*c.comp.b+comp.b*c.comp.a;
    return t;
}
Complex Complex::operator /(const Complex &c){
    Complex t;
    t.comp.a=(comp.a*c.comp.a+comp.b*c.comp.b)/(comp.a*comp.a+comp.b*comp.b);
    t.comp.b=(comp.b*c.comp.a-comp.a*c.comp.b)/(comp.a*comp.a+comp.b*comp.b);
    return t;
}
Complex Complex::operator -(const Complex &c){
    Complex y;
    y.comp.a=comp.a-c.comp.a;
    y.comp.b=comp.b-c.comp.b;
    return y;
}
bool Complex::operator ==(const Complex &c){
        if((comp.a==c.comp.a)&&(comp.b==c.comp.b))
            return true;
        return false;
    }
float Complex::abs(){
    return sqrt(comp.a * comp.a - comp.b * comp.b);
}



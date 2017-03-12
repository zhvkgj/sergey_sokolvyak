#include "class.h"

myclass::myclass(int a, int b, int c): num1(a), num2(b), num3(c){};
myclass::~myclass(){};
myclass::myclass(const myclass& c): num1(c.num1), num2(c.num2), num3(c.num3){};
void swap(myclass& a, myclass& b){
        using std::swap;
        swap(a.num1,b.num1);
        swap(a.num2,b.num2);
        swap(a.num3,b.num3);
};

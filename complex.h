#ifndef __COMPLEX_H__
#define __COMPLEX_H__
 
struct complex{
    int a,b;
};
class Complex{
    complex comp;
public:
    Complex(int x=0,int y=0){
        comp.a=x;
        comp.b=y;
    }
    Complex operator +(const Complex &c);
    Complex operator *(const Complex &c);
    Complex operator -(const Complex &c);
    Complex operator /(const Complex &c);
    bool operator ==(const Complex &c);
    const Complex& operator =(const Complex &c){
        comp.a=c.comp.a;
        comp.b=c.comp.b;
        return *this;
    }
    float abs();

    friend std::ostream& operator<<(std::ostream &out, const Complex &c){
        if( c.comp.b >= 0 )
            out << c.comp.a << "+" << c.comp.b <<"i";
         else
            out << c.comp.a << c.comp.b << "i";
        return out;
        }
 
    friend std::istream& operator>>(std::istream &in, const Complex &c){
        in >> c.comp.a >> c.comp.b;
 
        return in;
        }

};

#endif
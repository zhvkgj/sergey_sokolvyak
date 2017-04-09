#ifndef __THREENUM_H__
#define __THREENUM_H__
template <class T> 
class Trio{
private:
    T num1,num2,num3;
public:
    Trio(T a, T b, T c):num1(a),num2(b),num3(c){};
    Trio(const Trio& c);
    ~Trio();
    Trio& operator=(const Trio& c){
        Trio tmp(c);
        swap(*this,tmp);
        return *this;
    }
    T getMax();
    friend void swap(Trio& a, Trio& b){
        using std::swap;
        swap(a.num1,b.num1);
        swap(a.num2,b.num2);
        swap(a.num3,b.num3);
};

};

#endif
#ifndef __CLASS_H__
#define __CLASS_H__
class myclass{
protected: 
    int num1, num2, num3;
public:
    myclass(int a, int b, int c);
    myclass(const myclass& c);
    ~myclass();
    myclass& operator=(const myclass& c){
        myclass tmp(c);
        swap(*this,tmp);
        return *this;
    }
    friend void swap(myclass& a, myclass& b);
};

#endif
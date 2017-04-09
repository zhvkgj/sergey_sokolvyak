#include <iostream>
#include <algorithm>
#include "threeNum.h"

using namespace std;

int main(){
    Trio <double> obj1(1.1,2.2,3.6);
    Trio <double> obj2(4.5,5.1,6.2);
    swap(obj1,obj2);
    cout << obj1.getMax() << endl;
    return 0;
 }
#include "threeNum.h"
#include <algorithm>

template <class T>
Trio<T>::~Trio(){};

template <class T>
Trio<T>::Trio(const Trio& c): num1(c.num1), num2(c.num2), num3(c.num3){};

template <class T>
T Trio<T>::getMax() {
	return max(num3, max(num1, num2));
};

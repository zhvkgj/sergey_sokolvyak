#include "list.h"
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    index_list my(1);
    my.push(3);
    cout << my[1];
    return 0;
}

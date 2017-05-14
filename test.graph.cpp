#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

int main()
{
	setlocale(0, "");
	graph Graph;
	Graph.inputFile();
	Graph.outputResult();
	cout << "\n";
	system("pause");
	return 0;
}
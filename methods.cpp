#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <algorithm>

void fileReadGraph::Input() {// построение графа на основе матрицы смежности из файла
    char buff[255];
    for (int i=0;i<=255;i++) buff[i]=*""; // обнуляем связующую строку
    //const char* a = "C:\\test.txt";
    ifstream fin("C:\\test.txt");
    if (!fin.is_open()) 
        cout << "Файл не может быть открыт!\n"; 
    else
    {
        ////////////////////////////////////////////
        int number;
        char*pEnd;
        fin.getline(buff,sizeof(buff));
        number = strol(buff,&pEnd,10); // парсит первую строку с кол-во вершин
        setSize(number); // установили кол-во вершин
        for (int i=0;i<=255;i++) buff[i]=*""; //обнулили
        ///////////////////////////////////////////
        fin.getline(buff,sizeof(buff));
        char*graph::names_versh = new char[number]; /* выделили память               */
        for (int i=0, i < number, i++){     /*под массив с названиями вершин*/
            graph::names_versh[i]=buff[i];
        };
        for (int i=0;i<=255;i++) buff[i]=*""; //обнулили
        //////////////////////////////////////////
        for(int k=0; k<number; k++){ //заполняем наш граф пробегая по матрицы смежности
            fin.getline(buff,sizeof(buff));   //считывание первой строки матрицы
            for (int j=0; j<number; j++){    //пробежались по строке с номером k
                VecGraph[k][j]=buff[j];     //записали строку матрицы в наш граф
            }
            for (int i=0;i<=255;i++) buff[i]=*""; //обнулили
        }
        //////////////////////////////////////
    }
    fin.close();
}

void graph::Output(){
    ofstream fout("C:\\result_test.txt", ios_base::trunc);
    fout <<  //запись в файл строки с названиями вершин
    }
} 
////////////////////////////////////////// алгоритм Диница
bool bfs() {
	int qh=0, qt=0;
	q[qt++] = s;
	memset (d, -1, size * sizeof d[0]);
	d[s] = 0;
	while (qh < qt) {
		int v = q[qh++];
		for (int to=0; to<size; ++to)
			if (d[to] == -1 && f[v][to] < VecGraph[v][to]) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
	}
	return d[t] != -1;
}
 
int dfs (int v, int flow) {
    
	if (!flow)  return 0;
	if (v == t)  return flow;
	for (int & to=ptr[v]; to<size; ++to) {
		if (d[to] != d[v] + 1)  continue;
		int pushed = dfs (to, min (flow, VecGraph[v][to] - f[v][to]));
		if (pushed) {
			f[v][to] += pushed;
			f[to][v] -= pushed;
			return pushed;
		}
	}
	return 0;
}
 
int dinic() {
	int flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, size * sizeof ptr[0]);
		while (int pushed = dfs (s, INF))
			flow += pushed;
	}
	return flow;
}

void Result(){
    ofstream fout("C:\\result_test.txt", ios_base::trunc);
    fout <<  //запись в файл строки с названиями вершин
}

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
//ПОЛНОСТЬЮ РАБОТОСПОСОБНО
void graph::setSize(int size_)
{
	size = size_;
	Resize();
}
//ПОЛНОСТЮ РАБОТОСПОСОБНО
void graph::Resize()
{
	throughputs.resize(size);
	for (int i = 0; i < size; ++i)
		throughputs[i].resize(size);
}

//ПОЛНОСТЬЮ РАБОТОСПОСОБНО
void graph::inputConsole()
{
	int number;
	cout << "Введите кол-во вершин:" << endl;
	cin >> number;
	setSize(number);
	cout << "Введите названия вершин:" << endl;
	cin >> names_versh;
	cout << "Введите номера вершины истока и стока:" << endl;
	cin >> s >> t;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cout << "Введите пропускную способность дуги из  " << i + 1 << " вершины в " << j + 1 << " вершину: ";
			cin >> throughputs[i][j];
		}
	}
	for (int i = 0; i < size; i++) {
		throughputs[i][i] = 0;
	}
}

//ПОЛНОСТЬЮ РАБОТОСПОСОБНО
void graph::inputFile() {	// построение графа на основе матрицы смежности из файла
	ifstream fin("test.txt");
	if (!fin.is_open())
		cout << "Файл не может быть открыт!\n";
	else
	{
		int number;
		fin >> number;
		setSize(number);	
		cout << "Установили кол-во вершин!\n";
		fin >> names_versh;
		cout << "Считали названия вершин!\n";
		fin >> s;
		cout << "Номер вершины-истока: " << s << endl;
		fin >> t;
		cout << "Номер вершины-стока: " << t << endl;
		for (int i = 0; i < size; i++){
			for (int k = 0; k < size; k++) {
				fin >> throughputs[i][k];
			}
		}
		for (int j = 0; j < size; j++) {
			throughputs[j][j] = 0;
		}
	}
	fin.close();
}

//ПОЛНОСТЬЮ РАБОТОСПОСОБНО
bool graph::bfs() {
	shortcut_build.resize(size);
	shortcut_counts.resize(size);
	current_saturation.resize(size);
	for (int i = 0; i < size; ++i) {
		current_saturation[i].resize(size);
	}
	int qh = 0, qt = 0;
	shortcut_build[qt++] = s;
	for (int k = 0; k < size; k++) {
		shortcut_counts[k] = -1;
	}
	shortcut_counts[s] = 0;
	while (qh < qt) {
		int v = shortcut_build[qh++];
		for (int to = 0; to < size; ++to)
			if (shortcut_counts[to] == -1 && current_saturation[v][to] < throughputs[v][to]) {
				shortcut_build[qt++] = to;
				shortcut_counts[to] = shortcut_counts[v] + 1;
			}
	}
	return shortcut_counts[t] != -1;
}

//ПОЛНОСТЬЮ РАБОТОСПОСОБНО
int graph::dfs(int v, int flow) {
	if (!flow)  return 0;
	if (v == t)  return flow;
	for (int & to = current_edge[v]; to < size; ++to) {
		if (shortcut_counts[to] != shortcut_counts[v] + 1)  continue;
		int pushed = dfs(to, min(flow, throughputs[v][to] - current_saturation[v][to]));
		if (pushed) {
			current_saturation[v][to] += pushed;
			current_saturation[to][v] -= pushed;
			return pushed;
		}
	}
	return 0;
}

//ПОЛНОСТЬЮ РАБОТОСПОСОБНО
int graph::dinic() {
	current_edge.resize(size);
	int flow = 0;
	for (;;) {
		if (!bfs())  break;
		for (int l = 0; l < size; l++) {
			current_edge[l] = 0;
		}
		while (int pushed = dfs(s, INF)) {
			flow += pushed;
		}
	}
	return flow;
}
//ПОЛНОСТЬЮ РАБОТОСПОСОБНО
void graph::outputResult() {
	ofstream fout("result_test.txt", ios_base::trunc);
	fout << "Максимальный поток из вершины-истока " << names_versh[s] <<" в вершину-сток " << names_versh[t] << " равен: " << dinic() << "\n";
	fout.close();
}
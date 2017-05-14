#ifndef __GRAPH_H__
#define __GRAPH_H__

class graph {
public:
	const int INF = 1000000000;
	graph() {};
	virtual ~graph() {};
	void setSize(int size_);
	void inputFile();
	void inputConsole();
	void outputResult();
	void Resize();
	bool bfs();
	int dfs(int v, int flow);
	int dinic();
		
protected:
	vector<vector<int> > throughputs;
	int size;
	int s, t;                                   //номера вершин стока и истока
	string names_versh;
	vector<int> shortcut_build;              /*для хранения данных алгоритмом ДИНИЦА*/
	vector<int> shortcut_counts;             //////////////////////////////////////////////
	vector<int> current_edge;          //////////////////////////////////////////////
	vector <vector<int> > current_saturation; //////////////////////////////////////////////
};

#endif
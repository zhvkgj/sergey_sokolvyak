#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <vector>
using namespace std;

class graph{
public:
   const int INF = 1000000000;

   graph(){};
   virtual ~graph(){};
   void setSize(int size_);
   virtual void Input()=0;
   virtual void Output_result()=0;
   void Resize();
   friend bool bfs();
   friend int dfs();
   friend void dinic();

protected:
   std::vector<std::vector<int> > VecGraph;
   size_t size;
   int s,t;             //номера вершин стока и истока
   char*names_versh;
   vector<int> q;              /*для хранения данных алгоритмом ДИНИЦА-КАРПА*/
   vector<int> d;             //////////////////////////////////////////////
   vector<int> ptr;          //////////////////////////////////////////////
   vector <vector<int> > f; //////////////////////////////////////////////
};
 
class handWriteGraph:public graph // для ручного ввода значений nропускных 
{                                     //способностей графа
public:
   handWriteGraph(){};
   ~handWriteGraph(){};
   void Input();
   void Output_result();
};

class fileReadGraph:public graph    // для считывания значений пропускных 
{                                       // способностей из файла
public:
    fileReadGraph(){};
    ~fileReadGraph(){};
    void Input();
    void Output_result();
};

#endif
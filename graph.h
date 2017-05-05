#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <vector>

class graph{
public:
   graph(){};
   virtual ~graph(){};
   void setSize(int size_);
   virtual void Input()=0;
   void Output();
   void Resize();
protected:
   std::vector<std::vector<int> > VecGraph;
   int size;
   char*names_versh;
};
 
class handWriteGraph:public graph // для ручного ввода значений потоков в графе
{
public:
   handWriteGraph(){};
   ~handWriteGraph(){};
   void Input();
};

class fileReadGraph:public graph    // для считывания значений потоков из файла
{ 
public:
    fileReadGraph(){};
    ~fileReadGraph(){};
    void Input();

};

#endif
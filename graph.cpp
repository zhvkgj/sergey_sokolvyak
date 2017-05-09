#include "graph.h"
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

//Functions for abstract Graph
void graph::setSize(int size_)
{
   size=size_;
   Resize();
}


void graph::Resize()
{
   VecGraph.resize(size);
   for(int i=0; i<size; ++i)
      VecGraph[i].resize(size);
}
 
 
//Functions for hand writing
void handWriteGraph::Input()
{
    int number;
    cout << "Введите кол-во вершин:"<<endl;
    cin >> number;
    setSize(number);
    cout << "Введите названия вершин:"<<endl;
    char* names_versh = new char[size];
    cin << names_versh;
    cout << "Введите номера вершины истока и стока:"<< endl;
    cin >> s >> t;
    for(int i=0; i<size; ++i){
      for(int j=0; j<size; ++j){
         std::cout<<"Введите пропускную способность дуги из  "<< i+1 <<" вершины в"<< j+1 <<" вершину: ";
         std::cin>>VecGraph[i][j];
      }
    }
}
//Function for text file 
void fileReadGraph::Input() {// построение графа на основе матрицы смежности из файла
    char buff[255] = "";
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

